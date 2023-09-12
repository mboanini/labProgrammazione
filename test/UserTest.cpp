//
// Created by margherita on 8/14/2023.
//

#include "gtest/gtest.h"
#include "../User.h"
#include "../NotesCollection.h"

TEST(User, Constructor){
    Collection * subject = new NotesCollection("name");
    User user(subject);
    ASSERT_EQ(subject, user.getSubject());
}
