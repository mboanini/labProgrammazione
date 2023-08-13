//
// Created by margherita on 5/17/2023.
//

#ifndef LABPROGRAMMAZIONE_OBSERVER_H
#define LABPROGRAMMAZIONE_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;;

    virtual void update() = 0;

    virtual void attach() = 0;
    virtual void detach() = 0;
};


#endif //LABPROGRAMMAZIONE_OBSERVER_H
