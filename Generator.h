#pragma once

#include "utility.h"
#include "MapObject.h"
#include "Agent.h"

class Generator : public MapObject
{
protected:
	Agent* spawnAgent()const;
public:
	Generator(const Position& = { 0,0 }, const char& = 'G');
	virtual Agent* generate(const unsigned&) const = 0;
	virtual ~Generator() = 0;
};

class GeneratorY : public Generator {
	bool isEven(const int&) const;
public:
	GeneratorY(const Position& = { 0,0 });
	Agent* generate(const unsigned&) const override;
};

class GeneratorZ : public Generator {
	bool isPrime(const unsigned&) const;
public:
	GeneratorZ(const Position& = { 0,0 });
	Agent* generate(const unsigned&) const override;
};
