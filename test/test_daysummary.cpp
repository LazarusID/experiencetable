
#include "daysummary.h"
#include "gameday.h"
#include "jazzassert.h"

int main(void) {

    describe("DaySummary", [] {
        it("should return zero for all characters by default", [] {
            DaySummary s;
            expect(s["Ron"]).toBe(0);
        });

        it("should return points for each entry", [] {
            gameday g;

            g.events.push_back(experienceevent("Ron", 1, "For being ron"));
            g.events.push_back(experienceevent("Harry", 2, "Pure pluck"));
            g.events.push_back(
                    experienceevent("Hermione", 10, "Saving these two knuckleheads"));

            DaySummary s(g);

            expect(s["Ron"]).toBe(1);
            expect(s["Harry"]).toBe(2);
            expect(s["Hermione"]).toBe(10);
        });

        it("should return point total for each character", [] {
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

            expect(s["Ron"]).toBe(3);
            expect(s["Harry"]).toBe(6);
            expect(s["Hermione"]).toBe(15);
        });

        it("should allow iteration over all members", [] {
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

            expect(count).toBe(4);
            expect(ron).toBe(true);
            expect(harry).toBe(true);
            expect(hermione).toBe(true);
            expect(ginny).toBe(true);
        });

        it("should summarize all gamedays provided to the constructor", [] {
            gameday g1;
            gameday g2;

            g1.events.push_back(experienceevent("Ron", 1, "For being ron"));
            g1.events.push_back(experienceevent("Harry", 2, "Pure pluck"));
            g1.events.push_back(
                    experienceevent("Hermione", 10, "Saving these two knuckleheads"));
            g1.events.push_back(experienceevent("Ginny", 4, "Cuteness"));

            g2.events.push_back(experienceevent("Ron", 5, "For being ron"));
            g2.events.push_back(experienceevent("Harry", 6, "Pure pluck"));
            g2.events.push_back(
                    experienceevent("Hermione", 5, "Saving these two knuckleheads"));
            g2.events.push_back(experienceevent("Ginny", 1, "Cuteness"));

            vector<gameday> campaign = {g1, g2};

            DaySummary s(campaign);

            expect(s["Ron"]).toBe(6);
            expect(s["Harry"]).toBe(8);
            expect(s["Hermione"]).toBe(15);
            expect(s["Ginny"]).toBe(5);
        });

    });

    testSummary();

    return failed;
}