//
// Created by Riccardo Becciolini on 24/08/20.
//

#ifndef LABPROJECT_FILE_H
#define LABPROJECT_FILE_H

#include <iostream>
#include <QtCore/QString>

class File {
public:
    explicit File(QString fN):filename(fN), fsize(random()), uploaded(true)  {};

    ~File() {}

    int getFileSize() const {
        return abs(fsize);
    }

    const QString &getFilename() const {
        return filename;
    }

    bool isUploaded() const {
        return uploaded;
    }

private:
    QString filename;
    short int fsize;
    bool uploaded;


};


#endif //LABPROJECT_FILE_H
