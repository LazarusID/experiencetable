
#include "daysummary.h"
#include "gameday.h"
#include <gtest/gtest.h>

TEST(daysummary_suite, default_summary_returns_zero_for_all_characters) {
  DaySummary s;

  ASSERT_EQ(0, s["Ron"]);
}

TEST(daysummary_suite,
     given_gameday_with_one_entry_per_character_return_point_for_entry) {
  gameday g;

  g.events.push_back(experienceevent("Ron", 1, "For being ron"));
  g.events.push_back(experienceevent("Harry", 2, "Pure pluck"));
  g.events.push_back(
      experienceevent("Hermione", 10, "Saving these two knuckleheads"));

  DaySummary s(g);

  ASSERT_EQ(1, s["Ron"]);
  ASSERT_EQ(2, s["Harry"]);
  ASSERT_EQ(10, s["Hermione"]);
}

TEST(
    daysummary_suite,
    given_gameday_with_two_entries_per_character_return_point_total_for_character) {
  gameday g;

  g.events.push_back(experienceevent("Ron", 1, "For being ron"));
  g.events.push_back(experienceevent("Harry", 2, "Pure pluck"));
  g.events.push_back(
      experienceevent("Hermione", 10, "Saving these two knuckleheads"));
  g.events.push_back(experienceevent("Ron", 2, "Getting them into the muck"));
  g.events.push_back(experienceevent("Harry", 4, "Foolish Bravery"));
  g.events.push_back(
      experienceevent("Hermione", 5, "Saving these two knuckleheads - again."));

  DaySummary s(g);

  ASSERT_EQ(3, s["Ron"]);
  ASSERT_EQ(6, s["Harry"]);
  ASSERT_EQ(15, s["Hermione"]);
}

TEST(daysummery_suite, given_gameday_can_iterate_over_all_members) {
  gameday g;

  g.events.push_back(experienceevent("Ron", 1, "For being ron"));
  g.events.push_back(experienceevent("Harry", 2, "Pure pluck"));
  g.events.push_back(
      experienceevent("Hermione", 10, "Saving these two knuckleheads"));
  g.events.push_back(experienceevent("Ginny", 4, "Cuteness"));

  DaySummary s(g);

  bool ron = false;
  bool harry = false;
  bool hermione = false;
  bool ginny = false;
  int count = 0;
  for (auto p : s) {
    ++count;
    if (p.first == "Ron")
      ron = true;
    else if (p.first == "Harry")
      harry = true;
    else if (p.first == "Hermione")
      hermione = true;
    else if (p.first == "Ginny")
      ginny = true;
  }

  ASSERT_EQ(4, count);
  ASSERT_TRUE(ron);
  ASSERT_TRUE(harry);
  ASSERT_TRUE(hermione);
  ASSERT_TRUE(ginny);
}