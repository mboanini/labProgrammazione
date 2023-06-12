//
// Created by margherita on 5/17/2023.
//

#ifndef LABPROGRAMMAZIONE_SUBJECT_H
#define LABPROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer * o);
    virtual void unsubscribe(Observer * o);
    virtual void notify() = 0;
    virtual ~Subject() {};

};


#endif //LABPROGRAMMAZIONE_SUBJECT_H
