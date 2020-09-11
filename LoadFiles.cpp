//
// Created by Riccardo Becciolini on 24/08/20.
//

#include "LoadFiles.h"
#include "File.h"

void LoadFiles::subscribe(Observer *o) {
    observers.push_back(o);
}

void LoadFiles::unsubscribe(Observer *o) {
    observers.remove(o);
}

void LoadFiles::notify() const {
    for(const auto itr : observers) {
        itr->update();
    }
}


void LoadFiles::load(std::vector<const char *> filenames) {

    numberFile = static_cast<int>(filenames.size());

    for (auto itr : filenames) {
        File file(itr);
        fileName = file.getFilename();
        size = file.getFileSize();
        loaded = file.isUploaded();
        notify();
    }
}

void LoadFiles::loadVector() {

    std::vector<const char*> filenames;

    filenames.push_back("files/Lion.jpg");
    filenames.push_back("files/House.avi");
    filenames.push_back("files/Bottle.jpg");
    filenames.push_back("files/Elephant.jpeg");
    filenames.push_back("files/Doom.mp4");
    filenames.push_back("files/Gandalf.mp4");
    filenames.push_back("files/Fire.avi");
    filenames.push_back("files/Letter.txt");
    filenames.push_back("files/Rise.mp3");
    filenames.push_back("files/Cat.jpg");

    this->load(filenames);
}