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
            if(!(edit->second->getTitle()==note->getTitle())){
                edit->second->setTitle(note->getTitle());
                cout<<"\nNota modificata con successo!";
                cout<<"\nTitolo modificato: "<<edit->second->getTitle();
            }
            else if(!(edit->second->getText() == note->getText())){
                edit->second->setText(note->getText());
                cout<<"\nNota modificata con successo!";
                cout<<"\nTesto modificato: "<<edit->second->getText();
            }
            else if(edit->second->isImportant() != note->isImportant()){
                edit->second->setImportant(note->isImportant());
                cout<<"\nNota modificata con successo!";
            }
            else if(edit->second->isBlocked() != note->isBlocked()){
                edit->second->setBlocked(note->isBlocked());
                cout<<"\nNota modificata con successo!";
            }
        } else
            cout<<"\nErrore: nota non modificabile, poiché bloccata\n";
    }
    else
        cout<<"\nErrore: nota non trovata\n";
}

int NotesCollection::notesNumber() {
    return notes.size();
}

int NotesCollection::searchNote(const string &title) {
    auto itr = notes.find(title);
    if(itr!=notes.end()){
        cout<<"\nNota trovata"<<endl;
        cout<<"Titolo: "<<itr->second->getTitle()<<endl;
        cout<<"Testo: "<<itr->second->getText()<<endl;
        return 0;
    }
    else
        cout<<"\nErrore: nota non trovata"<<endl;
        return 1;
}