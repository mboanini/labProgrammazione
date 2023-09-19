//
// Created by margherita on 8/11/2023.
//

#include "ImportantNotes.h"

ImportantNotes::ImportantNotes(const string &name) : Collection(name) {}

ImportantNotes::~ImportantNotes() {}

void ImportantNotes::addNote(Note* note){
    auto itr = notes.find(note->getTitle());
    if(itr == notes.end()) {
        if (note->isImportant()) {
            notes.insert(make_pair(note->getTitle(), note));
            notify();
        } else
            cout << "\nErrore: nota non importante\n";
    }
    else
        cout << "\nErrore: titolo già presente, cambiare titolo\n";
}

void ImportantNotes::removeNote(const string& title){
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

void ImportantNotes::editNote(const string &title, Note *note) {
    auto edit = notes.find(title);
    if(edit != notes.end()){
        if (!edit->second->isBlocked()) {
            if(!(edit->second->getTitle()==note->getTitle()))
                edit->second->setTitle(note->getTitle());
            else if(!(edit->second->getText() == note->getText()))
                edit->second->setText(note->getText());
            else if(edit->second->isImportant() != note->isImportant()) {
                edit->second->setImportant(note->isImportant());
                if (!edit->second->isImportant()) {
                    notes.erase(edit);
                    notify();
                }
            }
            else if(edit->second->isBlocked() != note->isBlocked())
                edit->second->setBlocked(note->isBlocked());
        } else
            cout<<"\nErrore: nota non modificabile, poiché bloccata\n";
    }
    else
        cout<<"\nErrore: nota non trovata\n";
}

int ImportantNotes::notesNumber() {
    return notes.size();
}
