#include "utility.h"

std::ostream& operator<<(std::ostream& out, const Position& p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

bool operator ==(const Position& p, const Position& o) {
	return p.first == o.first && p.second == o.second;
}