#pragma once

#include <ostream>
#include <vector>
#include <utility>

class Agent;
class Generator;

typedef std::pair<unsigned, unsigned>Position;
typedef std::vector<Generator*>Generators;
typedef std::vector<Agent*>Agents;
typedef std::vector<Position>Positions;
typedef std::vector<int>Items;

std::ostream& operator<<(std::ostream&, const Position&);
bool operator ==(const Position&, const Position&);
