//
// Created by margherita on 8/11/2023.
//

#include "Collection.h"

Collection::Collection(const string &name) : name(name) {}

Collection::~Collection() {}

void Collection::subscribe(Observer *o) {
    observers.push_back(o);
}

void Collection::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Collection::notify() {
    for (auto itr = begin(observers); itr != end(observers); itr++){
        (*itr)->update();
    }
}

const string &Collection::getName() const {
    return name;
}

void Collection::setName(const string &name) {
    Collection::name = name;
}

const map<string, Note *> &Collection::getNotes() const {
    return notes;
}

void Collection::setNotes(const map<string, Note *> &notes) {
    Collection::notes = notes;
}
