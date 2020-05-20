#include "daysummary.h"

DaySummary::DaySummary(const gameday &g) {

  for (experienceevent e : g.events) {
    auto p = totals.find(e.character);
    if (p == totals.end()) {
      totals[e.character] = e.points;
    } else {
      p->second += e.points;
    }
  }
}