//
// Created by Riccardo Becciolini on 24/08/20.
//

#include "LoadFiles.h"
#include "File.h"

LoadFiles::~LoadFiles()  {
    vector.clear();
}

void LoadFiles::subscribe(Observer *o) {
    observers.push_back(o);
}

void LoadFiles::unsubscribe(Observer *o) {
    observers.remove(o);
}

void LoadFiles::notify() const {
    for(auto itr : observers) {
        itr->update();
    }
}


void LoadFiles::load() {

    numberFile = static_cast<int>(vector.size());

    notify();

}



