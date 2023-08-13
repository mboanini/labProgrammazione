//
// Created by margherita on 8/11/2023.
//

#ifndef LABPROGRAMMAZIONE_COLLECTION_H
#define LABPROGRAMMAZIONE_COLLECTION_H

#include "Subject.h"
#include "Note.h"

#include "map"

#include <list>
#include <iostream>
using namespace std;

class Collection: public Subject {
public:
    Collection(const string &name);
    virtual ~Collection();

    void subscribe(Observer * o) override;
    void unsubscribe(Observer * o) override;
    void notify() override;

    const string &getName() const;

    void setName(const string &name);

    const map<string, Note *> &getNotes() const;

    void setNotes(const map<string, Note *> &notes);

    virtual void addNote(Note * note) = 0;
    virtual void removeNote(const string& key) = 0;
    virtual void editNote(const string& key, Note * note) = 0;
    virtual int notesNumber() = 0;


protected:
    string name;
    map<string, Note *> notes;
    list<Observer *> observers;
};


#endif //LABPROGRAMMAZIONE_COLLECTION_H
