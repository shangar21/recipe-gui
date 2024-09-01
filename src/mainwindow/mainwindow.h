#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addrecipewindow.h"
#include "generatelistwindow.h"
#include "viewrecipewindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  AddRecipeWindow *addRecipeWindow = nullptr;
  ViewRecipeWindow *viewRecipeWindow = nullptr;
  GenerateGroceryListWindow *generateGroceryListWindow = nullptr;
  void setupUI(); // Function to set up the UI elements
  void openAddRecipeWindow();
  void openViewRecipeWindow();
  void openGenerateGroceryListWindow();
};

#endif // MAINWINDOW_H
