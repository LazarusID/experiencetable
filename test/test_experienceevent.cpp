
#include "experienceevent.h"
#include "jazzassert.h"

#include <sstream>

using namespace std;

int main(void) {
  describe("Plain Text ExperienceEvent", [] {
    it("should populate event and leave reason empty when reading from input "
       "stream",
       [] {
         stringstream src("Ron 7");
         experienceevent e;

         src >> e;

         expect(e.character).toBe(string("Ron"));
         expect(e.points).toBe(7);
         expect(e.reason).toBe(string(""));
       });

    it("should populate reason if reason is present", [] {
      stringstream src("Ron 6 Because of awesomeness");
      experienceevent e;

      src >> e;

      expect(e.character).toBe(string("Ron"));
      expect(e.points).toBe(6);
      expect(e.reason).toBe(string("Because of awesomeness"));
    });

    it("should set default values if stream has ended", [] {
      stringstream src;
      experienceevent e("Harry", 3, "Because he's harry");

      src >> e;

      expect(e.character).toBe(string(""));
      expect(e.points).toBe((int)0);
      expect(e.reason).toBe(string(""));
    });
  });

  xdescribe("CSV ExperienceEvent", [] {
    it("Populates all fields", [] {
      stringstream src("\"Harry\",3,\"General Awesomeness\"");
      experienceevent e;

      src >> e;

      expect(e.character).toBe(string("Harry"));
      expect(e.points).toBe(3);
      expect(e.reason).toBe(string("General Awesomeness"));
    });
  });

  testSummary();

  return failed;
}