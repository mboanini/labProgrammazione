//
// Created by margherita on 8/14/2023.
//

#include "gtest/gtest.h"
#include "../NotesCollection.h"
#include "../Note.h"

#include <iostream>
using namespace std;

TEST(NotesCollection, Constructor){
    string name = "name";
    NotesCollection notesCollection(name);
    ASSERT_EQ(name, notesCollection.getName());
}

TEST(NotesCollection, addNote){
    string name = "name";
    string title = "title";
    string text = "text";
    NotesCollection notesCollection(name);
    Note * note(title, text);
    notesCollection.addNote(note);
    ASSERT_EQ(1, notesCollection.notesNumber());
}

TEST(ImportantNotes, removeNote){
    string name = "name";
    string title = "title";
    string text = "text";
    string key = "key";
    NotesCollection notesCollection(name);
    Note * note(title, text);
    notesCollection.addNote(note);
    notesCollection.removeNote(key);
    ASSERT_EQ(0, notesCollection.notesNumber());
    important.getNotes().find(key)->second->setBlocked(true);
    ASSERT_EQ(1, notesCollection.notesNumber());
}

TEST(ImportantNotes, editNote){
    string name = "name";
    string title = "title";
    string text = "text";
    NotesCollection notesCollection(name);
    Note * note(title, text);
    notesCollection.addNote(note);
    string title1 = "title1";
    string text1 = "text";
    string key = "key";
    Note * note1(title1, text1);
    notesCollection.editNote(key, note1);
    ASSERT_EQ(title1, note->getTitle());
}


