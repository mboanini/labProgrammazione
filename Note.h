//
// Created by margherita on 5/17/2023.
//

#ifndef LABPROGRAMMAZIONE_NOTE_H
#define LABPROGRAMMAZIONE_NOTE_H

#include "Subject.h"

#include <list>
#include <iostream>
using namespace std;

class Note: public Subject {
public:
    Note(const string &title, const string &text, const string &category);
    virtual ~Note();

    const string &getTitle() const;

    void setTitle(const string &title);

    const string &getText() const;

    void setText(const string &text);

    const string &getCategory() const;

    void setCategory(const string &category);

    bool isImportant() const;

    void setImportant(bool important);

    bool isBlocked() const;

    void setBlocked(bool blocked);

    void subscribe(Observer * o) override;
    void unsubscribe(Observer * o) override;
    void notify() override;

    void removeNote(Note * note);
    void modifyNote(Note * note);

private:
    string title;
    string text;
    string category;
    bool important = false;
    bool blocked = false;
    list<Observer * > observers;
};


#endif //LABPROGRAMMAZIONE_NOTE_H
