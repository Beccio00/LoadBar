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

class LoadFiles : public Subject{
public:

    LoadFiles() {}

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() const override;

    void load(std::vector<QString> filenames);

    void loadVector();

    int getSize() const {
        return size;
    }

    bool isLoaded() const {
        return loaded;
    }


    int getNumberFile() const {
        return numberFile;
    }

    const QString &getFileName() const {
        return fileName;
    }

private:
    std::list<Observer*> observers;

    int size;
    bool loaded;
    int numberFile;
    QString fileName;
};


#endif //LABPROJECT_LOADFILES_H
