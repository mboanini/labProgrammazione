//
// Created by boa on 8/13/2023.
//

#ifndef LABPROGRAMMAZIONE_NOTESCOLLECTION_H
#define LABPROGRAMMAZIONE_NOTESCOLLECTION_H

#include "Collection.h"
#include "Note.h"

using namespace std;

class NotesCollection: public Collection {
public:
    explicit NotesCollection(const string &name);
    ~NotesCollection() override;

    void addNote(Note * note) override;
    void removeNote(const string& key) override;
    void editNote(const string& key, Note * note) override;
    int notesNumber() override;

};


#endif //LABPROGRAMMAZIONE_NOTESCOLLECTION_H
