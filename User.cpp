//
// Created by boa on 5/17/2023.
//

#include "User.h"

void User::update() {

}

void User::attach() {
    subject->subscribe(this);
}

void User::detach() {
    subject->unsubscribe(this);
}
