#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
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
  QPushButton *saveButton;

  void setupUI();
};

#endif
