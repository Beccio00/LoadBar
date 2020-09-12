#include "LoadFiles.h"
#include "Window.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    std::vector<QString> v;
    v.push_back("files/Lion.jpg");
    v.push_back("files/House.avi");
    v.push_back("files/Bottle.jpg");
    v.push_back("files/Elephant.jpeg");
    v.push_back("files/Doom.mp4");
    v.push_back("files/Gandalf.mp4");
    v.push_back("files/Fire.avi");
    v.push_back("files/Letter.txt");
    v.push_back("files/Rise.mp3");
    v.push_back("files/Cat.jpg");

    LoadFiles loader(v);

    Window mainWindow(&loader);
    mainWindow.show();

    return app.exec();

}