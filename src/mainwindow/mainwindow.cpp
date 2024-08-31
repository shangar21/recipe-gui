#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { setupUI(); }

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QPushButton *addRecipeButton = new QPushButton("Add Recipe", centralWidget);
  QPushButton *viewRecipeButton = new QPushButton("View Recipe", centralWidget);
  QPushButton *generateGroceryListButton =
      new QPushButton("Generate Grocery List", centralWidget);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);
  layout->addWidget(addRecipeButton);
  layout->addWidget(viewRecipeButton);
  layout->addWidget(generateGroceryListButton);

  centralWidget->setLayout(layout);

  connect(addRecipeButton, &QPushButton::clicked, this,
          &MainWindow::openAddRecipeWindow);

  connect(viewRecipeButton, &QPushButton::clicked, this,
          &MainWindow::openViewRecipeWindow);
}

void MainWindow::openAddRecipeWindow() {
  if (!addRecipeWindow) {
    addRecipeWindow = new AddRecipeWindow(this);
    addRecipeWindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(addRecipeWindow, &QWidget::destroyed, this,
            [this]() { addRecipeWindow = nullptr; });
  }
  addRecipeWindow->show();
  addRecipeWindow->raise();
  addRecipeWindow->activateWindow();
}

void MainWindow::openViewRecipeWindow() {
  if (!viewRecipeWindow) {
    viewRecipeWindow = new ViewRecipeWindow(this);
    viewRecipeWindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(viewRecipeWindow, &QWidget::destroyed, this,
            [this]() { viewRecipeWindow = nullptr; });
  }
  viewRecipeWindow->show();
  viewRecipeWindow->raise();
  viewRecipeWindow->activateWindow();
}
