//
// Created by margherita on 5/17/2023.
//

#ifndef LABPROGRAMMAZIONE_SUBJECT_H
#define LABPROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer * o) = 0;
    virtual void unsubscribe(Observer * o) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;;

};


#endif //LABPROGRAMMAZIONE_SUBJECT_H
