#ifndef _EXPERIENCEEVENT_H_
#define _EXPERIENCEEVENT_H_

#include <iostream>
#include <string>


using namespace std;

struct experienceevent {

  experienceevent() : character(""), points(0), reason(""){};
  experienceevent(string c, unsigned int p, string r)
      : character(c), points(p), reason(r){};

  string character;
  unsigned int points;
  string reason;
};

bool operator==(const experienceevent &lhs, const experienceevent &rhs);

bool operator<(const experienceevent &lhs, const experienceevent &rhs);

istream &operator>>(istream &, experienceevent &);

#endif
