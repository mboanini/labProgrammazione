//
// Created by margherita on 8/11/2023.
//

#ifndef LABPROGRAMMAZIONE_IMPORTANTNOTES_H
#define LABPROGRAMMAZIONE_IMPORTANTNOTES_H

#include "Collection.h"
#include "Note.h"

using namespace std;
class ImportantNotes: public Collection {
public:
    explicit ImportantNotes(const string &name);
    ~ImportantNotes() override;

    void addNote(Note * note) override;
    void removeNote(const string& title) override;
    void editNote(const string& title, Note * note) override;
    int notesNumber() override;
};


#endif //LABPROGRAMMAZIONE_IMPORTANTNOTES_H
