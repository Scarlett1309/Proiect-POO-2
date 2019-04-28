#include "Game.h"

void Game::addGenerators() {
	Positions p;
	unsigned width = map.getWidth(),
		height = map.getHeight();

	for (unsigned i = 1; i <= 2; i++) {
		Position pos;
		Generator* g;

		//inseram item-ul
		int random;
		random = rand() % 6;
		for (i = 0; i < random; i++) {
			pos.first = rand() % width;
			pos.second = rand() % height;

			map.setChar(pos, '*');
		}

		bool is_ok;
		do {
			is_ok = true;
			pos.first = rand() % width;
			pos.second = rand() % height;

			double h_distance, v_distance;

			//verificam sa nu fim prea aproape de coltul din stanga sus
			h_distance = (double)pos.first - 0;
			v_distance = (double)pos.second - 0;

			if (abs(h_distance) < 10 || abs(v_distance) < 10)
				is_ok = false;

			//verificam sa nu fim prea aproape de coltul din dreapta jos
			h_distance = (double)pos.first - width;
			v_distance = (double)pos.second - height;
			if (abs(h_distance) < 10 || abs(v_distance) < 10)
				is_ok = false;
		} while (!is_ok);

		p.push_back(pos);
		switch (i % 2) {
		case 1:
			g = new GeneratorY(pos);
			break;
		case 0:
			g = new GeneratorZ(pos);
			break;
		}
		generators.push_back(g);
		map.setChar(g->getPosition(), g->getSymbol());

	}
}

void Game::eraseAgent(const unsigned& index) {
	Position pos = agents[index]->getPosition();
	char symbol = agents[index]->getSymbol();

	//se elimina agentul de pe harta
	map.setChar(pos, ' ');

	//se elimina agentul din vectorul de agenti
	agents.erase(agents.begin() + index);

	std::cout << "Agentul " << symbol << " de pe pozitia " << pos <<
		"a fost eliminat \n";
}

Game::Game(const unsigned& width, const unsigned& height) : round(0), map(width, height)
{
	addGenerators();
	std::cout << "Configuratia initiala este : \n";
	std::cout << map;
}

void Game::operator()() {
	bool keep_playing = true;
	char input;
	unsigned i, j;
	do {
		round++;
		std::cout << "Runda " << round << "\n";
		for (i = 0; i < agents.size(); i++) {
			//incercam sa mutam toti agentii
			Position pos = agents[i]->getPosition();
			Position new_pos = agents[i]->nextMove(map.extract(pos, 3), map.extractPosition(pos, 3));
			if (pos != new_pos) {
				try {
					
					for (j = 0; j < agents.size() && j != i; j++)
						if (new_pos == agents[j]->getPosition()) {
							agents[i]->fight(*agents[j]);
							if (!(agents[i]->isAlive())) {
								eraseAgent(i);
							}
							if(!(agents[j]->isAlive())) {
								eraseAgent(j);
								map.setChar(pos, ' ');
								map.setChar(new_pos, agents[i]->getSymbol());
								agents[i]->advance(new_pos);
							}
						}
					
					std::cout << "agentul " << agents[i]->getSymbol() << " s-a mutat din " <<
						pos << " in " << new_pos << "\n";

				}
				catch (std::exception e) {
					eraseAgent(i);
					i--;
				}
			}
		}

		//generarea
		for (i = 0; i < generators.size(); i++) {
			Agent* agent = generators[i]->generate(round);
			if (agent != nullptr) {
				Position pos = agent->getPosition();
				if (map.isEmpty(pos)) {
					agents.push_back(agent);
					map.setChar(pos, agent->getSymbol());
				}
			}
		}

		std::cout << map << "\n";
		std::cout << "Continuati (Y\N)?";
		std::cin >> input;
		if (input != 'Y' && input != 'y')
			keep_playing = false;
	} while (keep_playing);
}
Game::~Game(){
	std::cout << "\nJocul s-a sfarsit!!";
}
