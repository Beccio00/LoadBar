//
// Created by Riccardo Becciolini on 24/08/20.
//

#ifndef LABPROJECT_OBSERVER_H
#define LABPROJECT_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;

    virtual ~Observer() {};

};


#endif //LABPROJECT_OBSERVER_H
