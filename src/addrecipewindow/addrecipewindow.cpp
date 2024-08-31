#include "addrecipewindow.h"
#include "SQLiteHelper.h"
#include <QFormLayout>
#include <QLabel>
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

  // Recipe Instructions
  instructionsTextEdit = new QTextEdit(this);

  // Save Button
  saveButton = new QPushButton("Save", this);

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

  // Add everything to main layout
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(new QLabel("Ingredients: ", this));
  mainLayout->addLayout(ingredientsLayout);
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
