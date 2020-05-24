//
// Created by clay on 5/17/20.
//

#include "gameday.h"
#include <gtest/gtest.h>

TEST(gameday_suite, identical_sessions_are_equal) {

  gameday left;
  gameday right;

  left.filename = "You're in a tavern";
  right.filename = "You're in a tavern";

  ASSERT_TRUE(left == right);
}

TEST(gameday_suite, non_matching_sessions_are_not_equal) {

  gameday left;
  gameday right;

  left.filename = "You're in a tavern";
  right.filename = "Roll for initiative";

  ASSERT_FALSE(left == right);
}
