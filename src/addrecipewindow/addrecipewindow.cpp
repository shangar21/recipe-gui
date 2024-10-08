#include "addrecipewindow.h"
#include "SQLiteHelper.h"
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

AddRecipeWindow::AddRecipeWindow(QWidget *parent) : QWidget(nullptr) {
  setupUI();
}

AddRecipeWindow::~AddRecipeWindow() {}

void AddRecipeWindow::setupUI() {
  setWindowTitle("Add Recipe");
  resize(400, 300);
  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  // Recipe Name
  recipeNameLineEdit = new QLineEdit(this);

  // Recipe Description
  recipeDescLineEdit = new QLineEdit(this);

  // Recipe Ingredients
  ingredientComboBox = new QComboBox(this);
  ingredientComboBox->setEditable(true);
  populateIngredientComboBox();

  // Ingredient Quantity
  quantityLineEdit = new QLineEdit(this);
  quantityLineEdit->setPlaceholderText("Quantity");

  // Quantity Unit
  unitComboBox = new QComboBox(this);
  unitComboBox->setEditable(true);
  populateUnitComboBox();

  // Ingredient Button
  addIngredientButton = new QPushButton("Add Ingredient");
  connect(addIngredientButton, &QPushButton::clicked, this,
          &AddRecipeWindow::addIngredient);

  // Ingredient List display
  ingredientsListWidget = new QListWidget(this);

  // Recipe Instructions
  instructionsTextEdit = new QTextEdit(this);

  // Save Button
  saveButton = new QPushButton("Save", this);
  connect(saveButton, &QPushButton::clicked, this,
          &AddRecipeWindow::saveRecipe);

  // Form Layout
  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow("Recipe Name: ", recipeNameLineEdit);
  formLayout->addRow("Recipe Description: ", recipeDescLineEdit);
  formLayout->addRow("Instructions: ", instructionsTextEdit);

  // Ingredients Layout
  QHBoxLayout *ingredientsLayout = new QHBoxLayout;
  ingredientsLayout->addWidget(ingredientComboBox);
  ingredientsLayout->addWidget(quantityLineEdit);
  ingredientsLayout->addWidget(unitComboBox);
  ingredientsLayout->addWidget(addIngredientButton);

  // Add everything to main layout
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(new QLabel("Ingredients: ", this));
  mainLayout->addLayout(ingredientsLayout);
  mainLayout->addWidget(ingredientsListWidget);
  mainLayout->addWidget(saveButton);

  setLayout(mainLayout);
}

void AddRecipeWindow::populateIngredientComboBox() {
  std::vector<Ingredient> ingredients = SQLiteHelper().fetchIngredients();

  for (Ingredient i : ingredients) {
    ingredientComboBox->addItem(i.name);
  }
}

void AddRecipeWindow::populateUnitComboBox() {
  std::vector<Unit> units = SQLiteHelper().fetchUnits();

  for (Unit u : units) {
    unitComboBox->addItem(u.name);
  }
}

void AddRecipeWindow::addIngredient() {
  QString ingredient = ingredientComboBox->currentText();
  QString quantity = quantityLineEdit->text();
  QString unit = unitComboBox->currentText();

  if (!ingredient.isEmpty() && !quantity.isEmpty() && !unit.isEmpty()) {
    QString ingredientEntry =
        QString("%1: %2 %3").arg(ingredient, quantity, unit);
    ingredientsListWidget->addItem(ingredientEntry);

    Ingredient i;
    i.id = -1;
    i.name = ingredient;

    bool ok;
    float q = quantity.toFloat(&ok);

    Unit u;
    u.id = -1;
    u.name = unit;

    ingredientsList.push_back(std::tuple<Ingredient, float, Unit>(i, q, u));

    // Clear the fields after adding
    quantityLineEdit->clear();
    ingredientComboBox->setCurrentIndex(0);
    unitComboBox->setCurrentIndex(0);
  }
}

bool areRecipeFieldsEmpty(const QString &name, const QString &description,
                          const QString &instructions) {
  return name.isEmpty() || description.isEmpty() || instructions.isEmpty();
}

void AddRecipeWindow::saveRecipe() {
  QString recipeName = recipeNameLineEdit->text();
  QString recipeDesc = recipeDescLineEdit->text();
  QString recipeInstructions = instructionsTextEdit->toPlainText();

  if (areRecipeFieldsEmpty(recipeName, recipeDesc, recipeInstructions))
    return;

  for (auto &[ingredient, quantity, unit] : ingredientsList) {
    SQLiteHelper().insertIngredient(ingredient);
    SQLiteHelper().insertUnit(unit);
  }

  Recipe recipe;
  recipe.title = recipeName;
  recipe.description = recipeDesc;
  recipe.instructions = recipeInstructions;

  int recipeId = SQLiteHelper().insertRecipe(recipe);

  recipe.id = recipeId;

  if (recipe.id <= 0) {
    return;
  }

  for (auto &[ingredient, quantity, unit] : ingredientsList) {
    SQLiteHelper().insertRecipeIngredientMap(recipe.id, ingredient, quantity,
                                             unit);
  }

  QMessageBox::information(this, "Success", "Recipe saved successfully!");

  this->close();
}
