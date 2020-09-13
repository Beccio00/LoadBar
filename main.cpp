#include "LoadFiles.h"
#include "Window.h"
#include <QApplication>
#include "File.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    std::vector<File*> v;


    v.push_back(new File("files/Lion.jpg"));
    v.push_back(new File("files/House.avi"));
    v.push_back(new File("files/Bottle.jpg"));
    v.push_back(new File("files/Elephant.jpeg"));
    v.push_back(new File("files/Doom.mp4"));
    v.push_back(new File("files/Gandalf.mp4"));
    v.push_back(new File("files/Fire.avi"));
    v.push_back(new File("files/Letter.txt"));
    v.push_back(new File("files/Rise.mp3"));
    v.push_back(new File("files/Cat.jpg", false));

    LoadFiles loader(v);

    Window mainWindow(&loader);
    mainWindow.show();

    return app.exec();

}