//
// Created by margherita on 8/14/2023.
//

#include "gtest/gtest.h"
#include "../Note.h"

#include <iostream>
using namespace std;

TEST(Note, Constructor){
    string title = "title";
    string text = "text";
    Note note(title, text);
    ASSERT_FALSE(note.isImportant());
    ASSERT_FALSE(note.isBlocked());
}

TEST(Note, getTitle){
    string title = "title";
    string text = "text";
    Note note(title, text);
    ASSERT_EQ(title, note.getTitle());
}

TEST(Note, setTitle){
    string title = "title";
    string text = "text";
    Note note(title,text);
    note.setTitle("ciao");
    ASSERT_EQ("ciao",note.getTitle());
}

TEST(Note, getText){
    string title = "title";
    string text = "text";
    Note note(title, text);
    ASSERT_EQ(text, note.getText());
}

TEST(Note, setText){
    string title = "title";
    string text = "text";
    Note note(title,text);
    note.setText("mi chiamo luigi");
    ASSERT_EQ("mi chiamo luigi",note.getText());
}

TEST(Note, isImportant){
    string title = "title";
    string text = "text";
    Note note(title, text);
    ASSERT_FALSE(note.isImportant());
}

TEST(Note, setImportant){
    string title = "title";
    string text = "text";
    Note note(title,text);
    note.setImportant(true);
    ASSERT_TRUE(note.isImportant());
}

TEST(Note, isBlocked){
    string title = "title";
    string text = "text";
    Note note(title, text);
    ASSERT_FALSE(note.isBlocked());
}

TEST(Note, setBlocked){
    string title = "title";
    string text = "text";
    Note note(title,text);
    note.setBlocked(true);
    ASSERT_TRUE(note.isBlocked());
}