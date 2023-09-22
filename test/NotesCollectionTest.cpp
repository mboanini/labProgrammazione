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
    string name1 = "name1";
    string title1 = "title1";
    string text1 = "text1";
    Note note1(title1, text1);
    notesCollection.addNote(&note1);
    ASSERT_EQ(2, notesCollection.notesNumber());
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
    notesCollection.getNotes().find("title")->second->setBlocked(true);
    notesCollection.editNote("title", &note1);
    ASSERT_EQ(title, note.getTitle());
    notesCollection.getNotes().find("title")->second->setBlocked(false);
    notesCollection.editNote("title", &note1);
    ASSERT_EQ(title1, note.getTitle());
}

TEST(NotesCollection, notesNumber){
    NotesCollection notesCollection("name");
    Note note("title", "text");
    Note note1("title1", "text1");
    Note note2("title2", "text2");
    Note note3("title3", "text3");
    notesCollection.addNote(&note);
    notesCollection.addNote(&note1);
    notesCollection.addNote(&note2);
    notesCollection.addNote(&note3);
    ASSERT_EQ(4, notesCollection.notesNumber());
    notesCollection.removeNote("title3");
    ASSERT_EQ(3, notesCollection.notesNumber());
}

TEST(NotesCollection, searchNote){
    NotesCollection notesCollection("name");
    Note note("title", "text");
    Note note1("title1", "text1");
    Note note2("title2", "text2");
    Note note3("title3", "text3");
    notesCollection.addNote(&note);
    notesCollection.addNote(&note1);
    notesCollection.addNote(&note2);
    notesCollection.addNote(&note3);
    int s = notesCollection.searchNote("title");
    ASSERT_EQ(0, s);
    int f = notesCollection.searchNote("title4");
    ASSERT_EQ(1, f);
}