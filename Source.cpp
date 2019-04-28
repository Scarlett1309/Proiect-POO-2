#include "Game.h"
#include <ctime>

int main() {
	unsigned width, height;
	std::cout << "Dimensiunile hartii (minim 15 x 15) : \n";
	do {
		std::cout << "Lungimea = ";
		std::cin >> width;
	} while (width < 15);

	do {
		std::cout << "Latimea = ";
		std::cin >> height;
	} while (height < 15);

	srand((unsigned)time(NULL));

	Game game(width, height);
	game();

	system("pause");
	return 0;
}