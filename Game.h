#pragma once

#include "utility.h"
#include "Map.h"
#include "Agent.h"
#include "Generator.h"

class Game
{
	Map map;
	unsigned round;
	Generators generators;
	Agents agents;

	//metoda ce adauga generatori
	void addGenerators();

	//metoda ce elimina un agent din joc
	void eraseAgent(const unsigned&);
public:
	Game(const unsigned&, const unsigned&);

	//supraincarcarea operatorului () pt rularea jocului
	void operator()();

	~Game();
};

