#ifndef VIEWRECIPEWINDOW_H
#define VIEWRECIPEWINDOW_H

#include "SQLiteHelper.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class ViewRecipeWindow : public QWidget {
  Q_OBJECT

public:
  ViewRecipeWindow(QWidget *parent = nullptr);
  ~ViewRecipeWindow();

private:
  QListWidget *recipeListWidget;
  QLabel *recipeDetailLabel;

  void setupUI();
  void addRecipeTitle(const Recipe &recipeTitle);
  void displayRecipeInfo(QListWidgetItem *item);
};

class RecipeDetailPopup : public QDialog {
  Q_OBJECT

public:
  explicit RecipeDetailPopup(const Recipe &recipe, QWidget *parent = nullptr)
      : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Title: " + recipe.title, this);
    QLabel *descriptionLabel =
        new QLabel("Description \n" + recipe.description, this);
    QLabel *instructionsLabel =
        new QLabel("Instructions: \n" + recipe.instructions, this);

    layout->addWidget(titleLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(instructionsLabel);

    setLayout(layout);
    setWindowTitle("Recipe Details");
    resize(300, 200);
  }
};

#endif
