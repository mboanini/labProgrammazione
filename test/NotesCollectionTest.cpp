//
// Created by margherita on 8/14/2023.
//

#include "gtest/gtest.h"
#include "../NotesCollection.h"

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
    Note note(title, text);
    notesCollection.addNote(&note);
    ASSERT_EQ(1, notesCollection.notesNumber());
}

TEST(NotesCollection, removeNote){
    string name = "name";
    string title = "title";
    string text = "text";
    NotesCollection notesCollection(name);
    Note note(title, text);
    notesCollection.addNote(&note);
    notesCollection.removeNote("title");
    ASSERT_EQ(0, notesCollection.notesNumber());
    notesCollection.addNote(&note);
    notesCollection.getNotes().find("title")->second->setBlocked(true);
    notesCollection.removeNote("title");
    ASSERT_EQ(1, notesCollection.notesNumber());
}

TEST(NotesCollection, editNote){
    string name = "name";
    string title = "title";
    string text = "text";
    NotesCollection notesCollection(name);
    Note note(title, text);
    notesCollection.addNote(&note);
    string title1 = "title1";
    string text1 = "text";
    Note note1(title1, text1);
    notesCollection.editNote("title", &note1);
    ASSERT_EQ(title1, note.getTitle());
}


