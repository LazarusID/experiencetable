#include "experienceevent.h"

bool operator==(const experienceevent& lhs, const experienceevent& rhs) {
	return lhs.character == rhs.character
		&& lhs.points == rhs.points
		&& lhs.reason == rhs.reason;
}

bool operator<(const experienceevent& lhs, const experienceevent& rhs) {
	return lhs.character < rhs.character
		|| lhs.points < rhs.points
		|| lhs.reason < rhs.reason;
}
