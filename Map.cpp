#include "Map.h"

Map::Map(const unsigned& width, const unsigned& height) : width(width), height(height) {
	matrix = new char*[width];
	for (unsigned i = 0; i < width; i++) {
		matrix[i] = new char[height];
		std::fill_n(matrix[i], height, ' ');
	}
}


Map::Map(const Map& map) : Map(map.width, map.height) {
	for (unsigned i = 0; i < width; i++)
		std::copy(map.matrix[i], map.matrix[i] + height, matrix[i]);
}

Map Map::operator=(const Map& map) {
	for (unsigned i = 0; i < width; i++)
		delete[] matrix[i];
	delete[] matrix;

	width = map.width;
	height = map.height;

	matrix = new char*[width];
	for (unsigned i = 0; i < width; i++) {
		matrix[i] = new char[height];
		std::copy(map.matrix[i], map.matrix[i] + height, matrix[i]);
	}

	return map;
}

void Map::setChar(const Position& pos, const char& c) {
	if (pos.first >= width || pos.second >= height)
		throw std::out_of_range("Pozitie invalida");
	matrix[pos.first][pos.second] = c;
}

const Map Map::extract(const Position& pos, const unsigned& size) const {
	const unsigned
		line = pos.first,
		col = pos.second,
		//determinam care sunt limitele intre care decupam
		start_line = std::max(line - size / 2, (unsigned)0),
		end_line = std::max(line - size / 2, width - 1),
		start_col = std::max(col - size / 2, (unsigned)0),
		end_col = std::max(col - size / 2, height - 1);
	Map map(end_line - start_line + 1, end_col - start_col + 1);

	//decupam din harta
	for (unsigned i = start_line; i <= end_line; i++) {
		const unsigned line_index = i - start_line;
		for (unsigned j = start_col; j <= end_col; j++) {
			const unsigned col_index = j - start_col;
			map.matrix[line_index][col_index] = matrix[i][j];
		}
	}

	return map;
}

Position Map::extractPosition(const Position& pos, const unsigned& size) const{
	const unsigned
		line = pos.first,
		col = pos.second,
		start_line = std::max(line - size / 2, (unsigned)0),
		start_col = std::max(col - size / 2, (unsigned)0);

	if (pos.first == start_line) {
		if (pos.second == start_col)
			return Position(0, 0);
		return Position(0, 1);
	}
	return Position(1, 1);
}

const unsigned Map::getWidth() const {
	return width;
}

const unsigned Map::getHeight() const {
	return height;
}

bool Map::isEmpty(const Position& pos) const {
	if (pos.first >= width || pos.second >= height)
		throw std::out_of_range("Pozitie invalida ! ");
	return matrix[pos.first][pos.second] == ' ';
}

Map::~Map() {
	for (unsigned i = 0; i < width; i++)
		delete[] matrix[i];
	delete[] matrix;

	height = width = 0;
}

std::ostream& operator<<(std::ostream& out, const Map& map) {
	for (unsigned i = 0; i < map.height + 2; i++)
		out << '-';
	out << std::endl;

	for (unsigned i = 0; i < map.width; i++) {
		out << '|';
		for (unsigned j = 0; j < map.height; j++)
			out << map.matrix[i][j];
		out << '|' << std::endl;
	}

	for (unsigned i = 0; i < map.height + 2; i++)
		out << '-';
	out << std::endl;
	return out;
}