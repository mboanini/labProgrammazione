//
// Created by margherita on 5/17/2023.
//

#include "Note.h"

Note::Note(const string &title, const string &text) : title(title), text(text) {}

Note::~Note() {}

const string &Note::getTitle() const {
    return title;
}

void Note::setTitle(const string &title) {
    if(!blocked)
        Note::title = title;
    else
        throw runtime_error{"Impossibile modificare il titolo"};
}

const string &Note::getText() const {
    return text;
}

void Note::setText(const string &text) {
    if(!blocked)
        Note::text = text;
    else
        throw runtime_error{"Impossibile modificare il testo"};
}

bool Note::isImportant() const {
    return important;
}

void Note::setImportant(bool important) {
    if(!blocked)
        Note::important = important;
    else
        throw runtime_error{"Impossibile modificare"};
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}
