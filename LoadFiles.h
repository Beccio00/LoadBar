//
// Created by Riccardo Becciolini on 24/08/20.
//

#ifndef LABPROJECT_LOADFILES_H
#define LABPROJECT_LOADFILES_H

#include "Subject.h"
#include <list>
#include <string>
#include <QtCore/QString>
#include <vector>
#include <iostream>
#include "File.h"

class LoadFiles : public Subject{
public:

    explicit LoadFiles(std::vector<File*>& v) : vector(v) {}

    virtual ~LoadFiles() {}

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() const override;

    void load();





    int getNumberFile() const {
        return numberFile;
    }


    const std::vector<File *> &getVector() const {
        return vector;
    }

private:
    std::list<Observer*> observers;

    std::vector<File*> vector;


    int numberFile;

};


#endif //LABPROJECT_LOADFILES_H
