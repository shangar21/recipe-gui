#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

#include "SQLiteHelper.h"
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class AddRecipeWindow : public QWidget {
  Q_OBJECT

public:
  AddRecipeWindow(QWidget *parent = nullptr);
  ~AddRecipeWindow();

private:
  QLineEdit *recipeNameLineEdit;
  QLineEdit *recipeDescLineEdit;
  QTextEdit *instructionsTextEdit;
  QComboBox *ingredientComboBox;
  QLineEdit *quantityLineEdit;
  QComboBox *unitComboBox;
  QPushButton *addIngredientButton;
  QListWidget *ingredientsListWidget;
  QPushButton *saveButton;

  Recipe recipeInput;
  std::vector<std::tuple<Ingredient, float, Unit>> ingredientsList;

  void setupUI();
  void populateIngredientComboBox();
  void populateUnitComboBox();
  void addIngredient();
  void saveRecipe();
};

#endif
