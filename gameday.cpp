//
// Created by clay on 5/17/20.
//

#include "gameday.h"

bool operator==(gameday const& lhs, gameday const& rhs) {
    return lhs.session == rhs.session;
}
