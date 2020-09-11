//
// Created by Riccardo Becciolini on 24/08/20.
//

#ifndef LABPROJECT_WINDOW_H
#define LABPROJECT_WINDOW_H



#include "LoadFiles.h"
#include <QtWidgets>
#include <iostream>
#include "Observer.h"


class Window : public QMainWindow , public Observer{

    Q_OBJECT

public:


    explicit Window(LoadFiles* f, QWidget* parent = nullptr);

    ~Window() {
        files->unsubscribe(this);
    }

    LoadFiles* getFiles() const {
        return files;
    }

    void update() override;


private slots:
    void loadFiles();


private:

    LoadFiles* files;

    QPushButton* button;
    QProgressBar* progressBar;
    QTextEdit* text;

    QLabel* title;
    QLabel* name;
};


#endif //LABPROJECT_WINDOW_H
