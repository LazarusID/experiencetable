#include "experienceevent.h"

bool operator==(const client::ast::experienceevent& lhs, const client::ast::experienceevent& rhs) {
	return lhs.name == rhs.name
		&& lhs.points == rhs.points
		&& lhs.reason == rhs.reason;
}

bool operator<(const client::ast::experienceevent& lhs, const client::ast::experienceevent& rhs) {
	return lhs.name < rhs.name
		|| lhs.points < rhs.points
		|| lhs.reason < rhs.reason;
}
