//
// Created by margherita on 5/17/2023.
//

#ifndef LABPROGRAMMAZIONE_USER_H
#define LABPROGRAMMAZIONE_USER_H

#include "Observer.h"
#include "Note.h"

#include <iostream>
using namespace std;

class User: public Observer {
public:

    virtual void update() override;
    void attach() override;
    virtual void detach() override;

private:
    Note * subject;
};


#endif //LABPROGRAMMAZIONE_USER_H
