#include "daysummary.h"

DaySummary::DaySummary(const gameday &g) { add_summary(g); }

DaySummary::DaySummary(const vector<gameday> &c) {
  for (auto g : c) {
    add_summary(g);
  }
}

void DaySummary::add_summary(const gameday &g) {
  for (experienceevent e : g.events) {
    auto p = totals.find(e.character);
    if (p == totals.end()) {
      totals[e.character] = e.points;
    } else {
      p->second += e.points;
    }
  }
}