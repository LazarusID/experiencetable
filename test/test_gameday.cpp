//
// Created by clay on 5/17/20.
//

#include <gtest/gtest.h>
#include "gameday.h"

TEST(gameday_suite, identical_sessions_are_equal) {

    gameday left;
    gameday right;

    left.session = "You're in a tavern";
    right.session = "You're in a tavern";

    ASSERT_TRUE(left == right);
}

TEST(gameday_suite, non_matching_sessions_are_not_equal) {

    gameday left;
    gameday right;

    left.session = "You're in a tavern";
    right.session = "Roll for initiative";

    ASSERT_FALSE(left == right);
}

