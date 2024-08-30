#include "addrecipewindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QWidget>

AddRecipeWindow::AddRecipeWindow(QWidget *parent) : QWidget(nullptr){
	setupUI();
}

AddRecipeWindow::~AddRecipeWindow() {}

void AddRecipeWindow::setupUI(){
	setWindowTitle("Add Recipe");
	resize(400, 300);

	recipeNameLineEdit = new QLineEdit(this);
	recipeDescLineEdit = new QLineEdit(this);
	instructionsTextEdit = new QTextEdit(this);
	saveButton = new QPushButton("Save", this);

	QFormLayout *formLayout = new QFormLayout;

	formLayout->addRow("Recipe Name: ", recipeNameLineEdit);
	formLayout->addRow("Recipe Desc: ", recipeDescLineEdit);
	formLayout->addRow("Instructions: ", instructionsTextEdit);

	QVBoxLayout *layout = new QVBoxLayout(this);

	layout->addLayout(formLayout);
	layout->addWidget(saveButton);

	setLayout(layout);
}
