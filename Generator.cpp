#include "Generator.h"

Agent* Generator::spawnAgent() const {
	int type = rand() % 3;
	switch (type) {
	case 0: {
		return new AgentA(getPosition());
		break;
	}
	case 1: {
		return new AgentB(getPosition());
		break;
	}
	}
	return new AgentC(getPosition());
}


Generator::Generator(const Position& pos, const char& sym) : MapObject(pos, sym) {

}

Generator::~Generator(){}

bool GeneratorY::isEven(const int& round) const {
	return round % 2 == 0;
}

GeneratorY::GeneratorY(const Position& pos) : Generator(pos, 'Y') {
}

Agent* GeneratorY::generate(const unsigned &round) const {
	if (!isEven(round))
		return nullptr;
	Agent *agent = spawnAgent();
	return agent;
}

bool GeneratorZ::isPrime(const unsigned& round) const {
	if (round == 1)
		return false;
	for (unsigned i = 2; i <= round / 2; i++)
		if (round%i == 0)
			return false;
	return true;
}

GeneratorZ::GeneratorZ(const Position& pos) :Generator(pos, 'U') {
}

Agent* GeneratorZ::generate(const unsigned& round) const {
	if (!isPrime(round))
		return nullptr;
	Agent* agent = spawnAgent();
	return agent;
}
