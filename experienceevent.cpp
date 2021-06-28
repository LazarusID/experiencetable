#include "experienceevent.h"
#include "stringtrim.h"

bool operator==(const experienceevent &lhs, const experienceevent &rhs) {
  return lhs.character == rhs.character && lhs.points == rhs.points &&
         lhs.reason == rhs.reason;
}

bool operator<(const experienceevent &lhs, const experienceevent &rhs) {
  return lhs.character < rhs.character || lhs.points < rhs.points ||
         lhs.reason < rhs.reason;
}

istream &operator>>(istream &in, experienceevent &e) {
    if (in) {
        in >> e.character;
    }
    if (in) in >> e.points;
    if (in) {
        string reason;
        getline(in, reason);
        e.reason = trim_copy(reason);
    }
    return in;
}


