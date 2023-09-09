//
// Created by margherita on 8/14/2023.
//

#include "gtest/gtest.h"
#include "../User.h"
#include "../Collection.h"

TEST(User, Constructor){
    Collection * subject = new Collection("name");
    User user(subject);
    ASSERT_EQ(subject, user.getSubject());
}
