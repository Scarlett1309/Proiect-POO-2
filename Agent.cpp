#include "Agent.h"

Agent::Agent(const Position& pos, const char& sym, const int& HP, const int& DMG) : MapObject(pos, sym), hp(HP), dmg(DMG) {
}

void Agent::advance(const Position& new_position) {
	setPosition(new_position);
}

void Agent::fight(Agent& enemy) {
	while (this->hp > 0 && enemy.hp > 0) {
		this->hp = this->hp - enemy.dmg;
		enemy.hp = enemy.hp - this->dmg;
	}
}

bool Agent::isAlive() {
	return this->hp > 0;
}

Agent::~Agent(){}

AgentA::AgentA(const Position& pos, int h, int d) : Agent(Position(pos.first - 1, pos.second), 'a', h, d) {
}

Position AgentA::nextMove(const Map& map, const Position& pos) {
	Position new_pos(pos.first - 1, pos.second);
	Position position = getPosition();
	Position ret_position(position.first - 1, position.second);

	try {
		if (map.isEmpty(new_pos))
			return ret_position;
		new_pos = Position(pos.first, pos.second + 1);
		ret_position = Position(position.first, position.second + 1);
		if (map.isEmpty(new_pos))
			return ret_position;
		return position;
	}
	catch(std::exception e){}
	return ret_position;
}


AgentB::AgentB(const Position& pos, int h, int d) : Agent(Position(pos.first + 1, pos.second), 'b', h, d) {

}


Position AgentB::nextMove(const Map& map, const Position& pos) {
	Position new_pos(pos.first + 1, pos.second);
	Position position = getPosition();
	Position ret_position(position.first + 1, position.second);

	try {
		if (map.isEmpty(new_pos))
			return ret_position;
		return position;
	}
	catch (std::exception e) {}
	return ret_position;
}

AgentC::AgentC(const Position& pos, int h, int d) : Agent(Position(pos.first, pos.second + 1), 'c', h, d), previous(-1){
}

Position AgentC::nextMove(const Map& map, const Position& pos) {
	previous *= -1;
	Position new_pos(pos.first + previous, pos.second + 1);
	Position position = getPosition();
	Position ret_position(position.first + previous, position.second + 1);

	try {
		if (map.isEmpty(new_pos))
			return ret_position;
		new_pos = Position(new_pos.first + 1, new_pos.second);
		new_pos = Position(ret_position.first + 1, ret_position.second);

		if (map.isEmpty(new_pos))
			return ret_position;

		previous *= -1;
		return position;
	}
	catch(std::exception e){}
	return ret_position;
}

