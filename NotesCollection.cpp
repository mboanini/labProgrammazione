//
// Created by boa on 8/13/2023.
//

#include "NotesCollection.h"

NotesCollection::NotesCollection(const string &name) : Collection(name) {}

NotesCollection::~NotesCollection() {}

void NotesCollection::addNote(Note *note) {
    notes.insert(make_pair(note->getTitle(), note));
    notify();
}

void NotesCollection::removeNote(const string &key) {
    auto note = notes.find(key);
    if(note != notes.end()) {
        if (!note->second->isBlocked()) {
            notes.erase(note);
            notify();
        } else
            cout<<"\n Errore: nota bloccata";
    }
    else
        cout<<"\nErrore: nota non trovata";
}

void NotesCollection::editNote(const string &key, Note *note) {
    auto edit = notes.find(key);
    if(edit != notes.end()){
        if (!edit->second->isBlocked()) {
            if(!(edit->second->getTitle()==note->getTitle()))
                edit->second->setTitle(note->getTitle());
            else if(!(edit->second->getText() == note->getText()))
                edit->second->setText(note->getText());
            else if(edit->second->isImportant() != note->isImportant())
                edit->second->setImportant(note->isImportant());
            else if(edit->second->isBlocked() != note->isBlocked())
                edit->second->setBlocked(note->isBlocked());
        } else
            cout<<"\nErrore: nota bloccata";
    }
    else
        cout<<"\nErrore: nota non trovata";
}

int NotesCollection::notesNumber() {
    return notes.size();
}