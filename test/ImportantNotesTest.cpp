//
// Created by margherita on 8/14/2023.
//

#include "gtest/gtest.h"
#include "../ImportantNotes.h"

#include <iostream>
using namespace std;

TEST(ImportantNotes, Constructor){
    string name = "name";
    ImportantNotes important(name);
    ASSERT_EQ(name, important.getName());
}

TEST(ImportantNotes, addNote){
    string name = "name";
    string title = "title";
    string text = "text";
    ImportantNotes important(name);
    Note note(title, text);
    important.addNote(&note);
    ASSERT_EQ(0, important.notesNumber());
    note.setImportant(true);
    important.addNote(&note);
    ASSERT_EQ(1, important.notesNumber());
}

TEST(ImportantNotes, removeNote){
    string name = "name";
    string title = "title";
    string text = "text";
    ImportantNotes important(name);
    Note note(title, text);
    note.setImportant(true);
    important.addNote(&note);
    important.removeNote(title);
    ASSERT_EQ(0, important.notesNumber());
    important.addNote(&note);
    important.getNotes().find(title)->second->setBlocked(true);
    important.removeNote(title);
    ASSERT_EQ(1, important.notesNumber());
}

TEST(ImportantNotes, editNote){
    string name = "name";
    string title = "title";
    string text = "text";
    ImportantNotes important(name);
    Note note(title, text);
    note.setImportant(true);
    important.addNote(&note);
    string title1 = "title1";
    string text1 = "text";
    Note note1(title1, text1);
    note1.setImportant(true);
    important.editNote(title, &note1);
    ASSERT_EQ(title1, note.getTitle());
}



