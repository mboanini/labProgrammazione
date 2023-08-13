//
// Created by margherita on 8/11/2023.
//

#include "ImportantNotes.h"

ImportantNotes::ImportantNotes(const string &name) : Collection(name) {}

ImportantNotes::~ImportantNotes() {}

void ImportantNotes::addNote(Note* note){
    if(note->isImportant()) {
        notes.insert(make_pair(note->getTitle(), note));
        notify();
    }
    else
        throw std::runtime_error{"Errore: nota non importante"};
}

void ImportantNotes::removeNote(const string& key){
    auto note = notes.find(key);
    if(note != notes.end()) {
        if (! note -> second -> isBlocked()) {
            notes.erase(note);
            notify();
        } else
            throw std::runtime_error{"Errore: nota bloccata"};
    }
    else
        throw std::runtime_error{"Errore: nota non trovata"};
}

int ImportantNotes::notesNumber() {
    return notes.size();
}
