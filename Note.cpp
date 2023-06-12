//
// Created by margherita on 5/17/2023.
//

#include "Note.h"

Note::Note(const string &title, const string &text, const string &category) : title(title), text(text),
                                                                              category(category) {}

Note::~Note() {}

const string &Note::getTitle() const {
    return title;
}

void Note::setTitle(const string &title) {
    Note::title = title;
}

const string &Note::getText() const {
    return text;
}

void Note::setText(const string &text) {
    Note::text = text;
}

const string &Note::getCategory() const {
    return category;
}

void Note::setCategory(const string &category) {
    Note::category = category;
}

bool Note::isImportant() const {
    return important;
}

void Note::setImportant(bool important) {
    Note::important = important;
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}

void Note::subscribe(Observer *o) {
    observers.push_back(o);
}

void Note::unsubscribe(Observer *o) {
    observers.remove(0);
}

void Note::notify() {
    for (auto itr = begin(observers); itr != end(observers); itr++){
        (*itr)->update();
    }
}



