#include "generatelistwindow.h"
#include <QMessageBox>

GenerateGroceryListWindow::GenerateGroceryListWindow(QWidget *parent)
    : QDialog(parent) {
  setupUI();
}

GenerateGroceryListWindow::~GenerateGroceryListWindow() {}

void GenerateGroceryListWindow::setupUI() {
  setWindowTitle("Generate Grocery List");
  resize(500, 400);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  recipeScrollArea = new QScrollArea(this);
  QWidget *scrollAreaWidget = new QWidget(recipeScrollArea);
  scrollAreaLayout = new QVBoxLayout(scrollAreaWidget);
  recipeScrollArea->setWidget(scrollAreaWidget);
  recipeScrollArea->setWidgetResizable(true);

  generateListButton = new QPushButton("Generate List", this);
	connect(generateListButton, &QPushButton::clicked, this, &GenerateGroceryListWindow::generateGroceryList);

  mainLayout->addWidget(recipeScrollArea);
	mainLayout->addWidget(generateListButton);

  loadRecipes();
}

void GenerateGroceryListWindow::loadRecipes() {
  std::vector<Recipe> recipes = SQLiteHelper().fetchRecipes();

  for (Recipe recipe : recipes) {
    QWidget *recipeWidget = new QWidget(this);
    QHBoxLayout *recipeLayout = new QHBoxLayout(recipeWidget);

    QLabel *recipeLabel = new QLabel(recipe.title, recipeWidget);
    QSpinBox *quantitySpinBox = new QSpinBox(recipeWidget);
    quantitySpinBox->setRange(0, 100);

    recipeLayout->addWidget(recipeLabel);
    recipeLayout->addWidget(quantitySpinBox);

    scrollAreaLayout->addWidget(recipeWidget);

    recipeSpinBoxes[recipe.id] = quantitySpinBox;
  }
}

void GenerateGroceryListWindow::generateGroceryList() {
  QMap<QString, float> aggregatedIngredients;

  for (auto it = recipeSpinBoxes.begin(); it != recipeSpinBoxes.end(); it++) {
    int recipeId = it.key();
    int quantity = it.value()->value();

    if (quantity > 0) {
      std::vector<std::tuple<Ingredient, float, Unit>> recipeIngredients =
          SQLiteHelper().fetchRecipeIngredients(recipeId);

			for (auto &[ingredient, measure, unit] : recipeIngredients){
				QString key = QString("%1 (%2)").arg(ingredient.name).arg(unit.name);
				aggregatedIngredients[key] += measure * quantity;
			}
    }
  }

	QStringList output;
	for (auto it = aggregatedIngredients.begin(); it != aggregatedIngredients.end(); it++){
		output.append(QString("%1: %2").arg(it.key()).arg(it.value()));
	}

	QMessageBox::information(this, "Grocery List", output.join("\n"));
}
