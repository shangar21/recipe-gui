#ifndef VIEWRECIPEWINDOW_H
#define VIEWRECIPEWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QListWidget>
#include <QLabel>

class ViewRecipeWindow : public QWidget {
  Q_OBJECT

public:
  ViewRecipeWindow(QWidget *parent = nullptr);
  ~ViewRecipeWindow();

private:
  QListWidget *recipeListWidget;
  QLabel *recipeDetailLabel;

  void setupUI();
	void addRecipeTitle(const QString& recipeTitle);
};

#endif
