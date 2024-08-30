#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

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
