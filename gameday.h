//
// Created by clay on 5/17/20.
//

#ifndef EXPERIENCETAB_GAMEDAY_H
#define EXPERIENCETAB_GAMEDAY_H

#include <string>
#include <vector>
#include "experienceevent.h"

class gameday {
public:
    std::string session;
    std::vector<experienceevent> events;
};

bool operator==(gameday const& lhs, gameday const& rhs);

#endif //EXPERIENCETAB_GAMEDAY_H