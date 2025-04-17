#include "viewrecipewindow.h"
#include <QFormLayout>
#include <QPushButton>
#include <QWidget>

ViewRecipeWindow::ViewRecipeWindow(QWidget *parent) : QWidget(nullptr) {
  setupUI();
}

ViewRecipeWindow::~ViewRecipeWindow() {}

void ViewRecipeWindow::setupUI() {
  setWindowTitle("View Recipes");
  resize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(this);
  recipeListWidget = new QListWidget(this);
  layout->addWidget(recipeListWidget);

  std::vector<Recipe> recipes = SQLiteHelper().fetchRecipes();

  for (Recipe r : recipes) {
    addRecipeTitle(r);
  }

  recipeDetailLabel = new QLabel("Select a recipe to view details", this);
  layout->addWidget(recipeDetailLabel);

  connect(recipeListWidget, &QListWidget::itemClicked, this,
          &ViewRecipeWindow::displayRecipeInfo);
}

void ViewRecipeWindow::addRecipeTitle(const Recipe &recipe) {
  QListWidgetItem *item = new QListWidgetItem(recipe.title, recipeListWidget);
  item->setData(Qt::UserRole, QVariant::fromValue(recipe));
}

void ViewRecipeWindow::displayRecipeInfo(QListWidgetItem *item) {
  QVariant var = item->data(Qt::UserRole);
  if (var.canConvert<Recipe>()) {
    Recipe recipe = var.value<Recipe>();
    RecipeDetailPopup *popup = new RecipeDetailPopup(recipe, this);
    popup->setAttribute(Qt::WA_DeleteOnClose);
    popup->show();
  }
}

std::string RecipeDetailPopup::getIngredientString(const Recipe &recipe) {
    std::vector<std::tuple<Ingredient, float, Unit>> ingredientList = 
        SQLiteHelper().fetchRecipeIngredients(recipe.id);

    std::string data;

    for (const std::tuple<Ingredient, float, Unit>& ingredient : ingredientList) {
        const Ingredient& ing = std::get<0>(ingredient);
        float quantity = std::get<1>(ingredient);
        const Unit& unit = std::get<2>(ingredient);

        data += ing.name.toStdString();
        data += " ";
        data += std::to_string(quantity);
        data += " ";
        data += unit.name.toStdString();
        data += "\n";
    }

    return data;
}

