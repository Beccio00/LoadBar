//
// Created by Riccardo Becciolini on 24/08/20.
//

#include <vector>
#include "Window.h"
#include <unistd.h>


Window::Window(LoadFiles *f, QWidget *parent) : files(f), QMainWindow(parent) {
    files->subscribe(this);

    this->setWindowTitle("Elaborato di laboratorio");
    this->setFixedSize(QSize(1280, 720));

    name = new QLabel("Riccardo Becciolini", this);
    name->setGeometry(QRect(QPoint(30,30), QSize(400, 60)));
    name->setAlignment(Qt::AlignLeft);

    title = new QLabel("Classe che carica file di risorse e aggiorna una progress bar (con QT).", this);
    title->setGeometry(QRect(QPoint(350, 60), QSize(550, 200)));
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(20);
    title->setFont(font);

    button = new QPushButton("Carica risorse!", this);
    button->setGeometry(QRect(QPoint(520, 300), QSize(200, 30)));

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(470, 260), QSize(300, 30)));

    text = new QTextEdit(this);
    text->setGeometry(QRect(QPoint(360, 350), QSize(500, 140)));
    text->setText("...Pronto a caricare i files...\n");
    text->setReadOnly(true);

    QTextCursor c =  text->textCursor();
    c.movePosition(QTextCursor::End);
    text->setTextCursor(c);

    progressBar->setMinimum(0);
    progressBar->setMaximum(1000);
    progressBar->setValue(0);

    // Connette il segnale del bottone allo slot appropiato
    connect(button, SIGNAL (released()), this, SLOT (loadFiles()));
}




void Window::update() {

    if (files->isLoaded()) {

        //Aggiorna progess bar
        while (progressBar->value() < 1000) {
            progressBar->setValue(progressBar->value() + (10 / files->getNumberFile()));
            usleep(1000);
        }
        //Aggiorna text
        QString log = "✅ File caricato '" + QString(files->getFileName()) + QString("' con successo (") +
                      QString::number(files->getSize()) + QString(" bytes).") + "\n";
        text->append(log);


        //Aggiorna text di button
        QString percentText = QString::number(progressBar->value() / 10) + QString("%  files caricate!");
        button->setText(percentText);

    } else {

        //Aggiorna  text log
        QString log = "❌ Non è possibile caricare il files '" + files->getFileName();
        text->append(log);
    }
}

void Window::loadFiles() {

    text->setText("... Caricamento in corso ...\n\n\n");

    files->load();

}

