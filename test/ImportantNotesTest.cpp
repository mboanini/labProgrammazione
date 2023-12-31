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
    string name1 = "name1";
    string title1 = "title1";
    string text1 = "text1";
    Note note1(title1, text1);
    important.addNote(&note1);
    ASSERT_EQ(1, important.notesNumber());
    note1.setImportant(true);
    important.addNote(&note1);
    ASSERT_EQ(2, important.notesNumber());
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
    important.getNotes().find(title)->second->setBlocked(true);
    important.editNote(title, &note1);
    ASSERT_EQ(title, note.getTitle());
    important.getNotes().find(title)->second->setBlocked(false);
    important.editNote(title, &note1);
    ASSERT_EQ(title1, note.getTitle());
}

TEST(ImportantNotes, notesNumber){
    ImportantNotes important("name");
    Note note("title", "text");
    Note note1("title1", "text1");
    Note note2("title2", "text2");
    Note note3("title3", "text3");
    note.setImportant(true);
    note1.setImportant(true);
    note2.setImportant(true);
    important.addNote(&note);
    important.addNote(&note1);
    important.addNote(&note2);
    important.addNote(&note3);
    ASSERT_EQ(3, important.notesNumber());
    important.removeNote("title1");
    ASSERT_EQ(2, important.notesNumber());
}

TEST(ImportantNotes, searchNote){
    ImportantNotes important("name");
    Note note("title", "text");
    Note note1("title1", "text1");
    Note note2("title2", "text2");
    Note note3("title3", "text3");
    note.setImportant(true);
    note1.setImportant(true);
    note2.setImportant(true);
    important.addNote(&note);
    important.addNote(&note1);
    important.addNote(&note2);
    important.addNote(&note3);
    int s = important.searchNote("title");
    ASSERT_EQ(0, s);
    int f = important.searchNote("title3");
    ASSERT_EQ(1, f);
}