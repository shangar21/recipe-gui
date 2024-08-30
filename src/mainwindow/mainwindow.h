#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addrecipewindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
		AddRecipeWindow *addRecipeWindow = nullptr;
    void setupUI();           // Function to set up the UI elements
		void openAddRecipeWindow();
};

#endif // MAINWINDOW_H

