//
// Created by boa on 8/13/2023.
//

#include "NotesCollection.h"

NotesCollection::NotesCollection(const string &name) : Collection(name) {}

NotesCollection::~NotesCollection() {}

void NotesCollection::addNote(Note *note) {
    auto itr = notes.find(note->getTitle());
    if(itr == notes.end()) {
        notes.insert(make_pair(note->getTitle(), note));
        notify();
    }
    else
        cout << "\nTitolo già presente, cambiare titolo\n";
}

void NotesCollection::removeNote(const string &title) {
    auto note = notes.find(title);
    if(note != notes.end()) {
        if (!note->second->isBlocked()) {
            notes.erase(note);
            notify();
        } else
            cout<<"\nErrore: nota non rimovibile, poiché bloccata\n";
    }
    else
        cout<<"\nErrore: nota non trovata\n";
}

void NotesCollection::editNote(const string &title, Note *note) {
    auto edit = notes.find(title);
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
            cout<<"\nErrore: nota non modificabile, poiché bloccata\n";
    }
    else
        cout<<"\nErrore: nota non trovata\n";
}

int NotesCollection::notesNumber() {
    return notes.size();
}