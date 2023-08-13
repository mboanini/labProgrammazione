//
// Created by margherita on 8/12/2023.
//

#include "User.h"

User::User(Collection *subject) : subject(subject) {}

User::~User() {}

Collection *User::getSubject() const {
    return subject;
}

void User::attach() {
    subject -> subscribe(this);
}

void User::detach() {
    subject -> unsubscribe(this);
}

void User::update() {

}
