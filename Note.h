//
// Created by margherita on 5/17/2023.
//

#ifndef LABPROGRAMMAZIONE_NOTE_H
#define LABPROGRAMMAZIONE_NOTE_H

#include <list>
#include <iostream>
using namespace std;

class Note{
public:
    Note(const string &title, const string &text);
    virtual ~Note();

    const string &getTitle() const;
    void setTitle(const string &title);

    const string &getText() const;
    void setText(const string &text);

    bool isImportant() const;
    void setImportant(bool important);

    bool isBlocked() const;
    void setBlocked(bool blocked);

private:
    string title;
    string text;
    bool important = false;
    bool blocked = false;
};


#endif //LABPROGRAMMAZIONE_NOTE_H
