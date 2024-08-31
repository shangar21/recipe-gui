#include "mainwindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

	qRegisterMetaType<Recipe>("Recipe");

  MainWindow window;
  window.setWindowTitle("Recipe CLI - Main Window");
  window.resize(300, 200);
  window.show();

  return app.exec();
}
