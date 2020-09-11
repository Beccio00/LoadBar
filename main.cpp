#include "LoadFiles.h"
#include "Window.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadFiles loader;

    Window mainWindow(&loader);
    mainWindow.show();

    return app.exec();

}