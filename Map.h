#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "utility.h"

class Map
{
	char** matrix;
	unsigned width, height;
public:
	//constructor
	Map(const unsigned& = 1, const unsigned& = 1);

	//constructor de copiere
	Map(const Map&);

	//supraincarcarea operatorului de atribuire
	Map operator =(const Map&);

	//metoda ce seteaza pozitia data de primul parametru
	//caracterul primit de al treilea parametru
	void setChar(const Position&, const char&);

	//metoda ce returneaza o noua harta ce contine submatricea patratica centrata in 
	//linia si coloana date de primii 2 parametrii si de dimensiunea celui de-al 3 lea parametru
	const Map extract(const Position&, const unsigned&) const;

	//metoda ce intoarce pozitia relativa la harta extrasa cu metoda extract
	Position extractPosition(const Position&, const unsigned&) const;

	const unsigned getWidth() const;
	const unsigned getHeight() const;

	//metoda ce verifica daca se afla ceva pe o pozitie din harta
	bool isEmpty(const Position&) const;

	//supraincarcarea operatorului <<
	friend std::ostream& operator<<(std::ostream&, const Map&);

	//destructor
	~Map();

};

