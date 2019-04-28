#pragma once

#include "Map.h"
#include "utility.h"
#include "MapObject.h"

class Agent : public MapObject
{
	int hp;
	int dmg;
public:
	Agent(const Position& = { 0,0 }, const char& = 'a', const int& = 0, const int& = 0);
	virtual Position nextMove(const Map&, const Position&) = 0;
	void advance(const Position&);

	void fight(Agent&);
	bool isAlive();

	virtual ~Agent();
};

class AgentA : public Agent {
public:
	AgentA(const Position& = { 0, 0 }, int = 100, int = 35);
	Position nextMove(const Map&, const Position&);
};

class AgentB : public Agent {
public:
	AgentB(const Position& = { 0, 0 }, int = 125, int = 23);
	Position nextMove(const Map&, const Position&);
};

class AgentC : public Agent {
	int previous;
public:
	AgentC(const Position& = { 0, 0 }, int = 200, int = 15);
	Position nextMove(const Map&, const Position&);
};
