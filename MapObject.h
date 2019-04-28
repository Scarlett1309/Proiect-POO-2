#pragma once

#include "utility.h"

class MapObject
{
	Position position;
	char symbol;
protected:
	void setPosition(const Position&);
public:
	MapObject(const Position& = { 0, 0 }, const char& = '*');
	Position getPosition() const;
	char getSymbol();
};

