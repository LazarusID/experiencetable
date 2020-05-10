#ifndef _EXPERIENCEEVENT_H_
#define _EXPERIENCEEVENT_H_

#include <string>

using namespace std;

struct experienceevent {
    string character;
    unsigned int points;
    string reason;
};

bool operator==(const experienceevent& lhs, const experienceevent& rhs);

bool operator<(const experienceevent& lhs, const experienceevent& rhs); 

#endif
