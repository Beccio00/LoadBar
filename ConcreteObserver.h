//
// Created by Riccardo Becciolini on 11/09/20.
//

#include "Observer.h"
#include "LoadFiles.h"
#include <iostream>

#ifndef LABPROJECT_CONCRETEOBSERVER_H
#define LABPROJECT_CONCRETEOBSERVER_H

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(LoadFiles* s) : subject(s) {
        subject->subscribe(this);
    }
    virtual ~ConcreteObserver() {
        subject->unsubscribe(this);
    }

    void update() override {
        std::cout << "Update" << std::endl;
    }

private:
    LoadFiles* subject;
};

#endif //LABPROJECT_CONCRETEOBSERVER_H
