#ifndef _DAYSUMMARY_H_
#define _DAYSUMMARY_H_

#include <map>
#include <string>

#include "gameday.h"

class DaySummary {
public:
  using const_iterator = std::map<std::string, int>::const_iterator;

  DaySummary(){};
  DaySummary(const gameday &g);
  DaySummary(const std::vector<gameday> &gamelist);

  int operator[](const std::string x) const {
    if (totals.find(x) == totals.end()) {
      return 0;
    }
    return totals.at(x);
  };

  const_iterator begin() { return totals.begin(); }
  const_iterator end() { return totals.end(); }

private:
  std::map<std::string, int> totals;

  void add_summary(const gameday &);
};

#endif