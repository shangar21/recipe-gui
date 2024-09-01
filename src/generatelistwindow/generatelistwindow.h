#pragma once

#include "SQLiteHelper.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

class GenerateGroceryListWindow : public QDialog {
  Q_OBJECT

public:
  GenerateGroceryListWindow(QWidget *parent = nullptr);
  ~GenerateGroceryListWindow();

private:
  QScrollArea *recipeScrollArea;
  QVBoxLayout *scrollAreaLayout;
  QPushButton *generateListButton;
  QMap<int, QSpinBox *> recipeSpinBoxes;

  void loadRecipes();
  void generateGroceryList();
  void setupUI();
};
