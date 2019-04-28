#include "MapObject.h"

MapObject::MapObject(const Position& pos, const char& sym) : position(pos), symbol(sym)
{}

void MapObject::setPosition(const Position& new_position) {
	position = new_position;
}

Position MapObject::getPosition() const {
	return position;
}

char MapObject::getSymbol() {
	return symbol;
}
