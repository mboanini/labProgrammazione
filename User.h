//
// Created by margherita on 8/12/2023.
//

#ifndef LABPROGRAMMAZIONE_USER_H
#define LABPROGRAMMAZIONE_USER_H

#include "Observer.h"
#include "Collection.h"

#include <iostream>
using namespace std;

class User: public Observer {
public:
    explicit User(Collection *subject);
    ~User() override;

    virtual void update() override;

    void attach() override;
    void detach() override;

    Collection *getSubject() const;

private:
    Collection * subject;
};


#endif //LABPROGRAMMAZIONE_USER_H
