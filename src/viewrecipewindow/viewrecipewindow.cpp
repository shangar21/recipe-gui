#include "viewrecipewindow.h"
#include "SQLiteHelper.h"
#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>
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

  if (recipes.size() == 0) {
    addRecipeTitle(QString::fromStdString("No recipes Currently!"));
  }

  for (Recipe r : recipes) {
    addRecipeTitle(r.title);
  }

  recipeDetailLabel = new QLabel("Select a recipe to view details", this);
  layout->addWidget(recipeDetailLabel);
}

void ViewRecipeWindow::addRecipeTitle(const QString &recipeTitle) {
  recipeListWidget->addItem(recipeTitle);
}
