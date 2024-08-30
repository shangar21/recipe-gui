#include <QApplication>
#include "mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

		MainWindow window;
    window.setWindowTitle("Recipe CLI - Main Window");
    window.resize(300, 200);
    window.show();

    return app.exec();

}

