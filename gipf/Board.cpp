#include "Board.h"


Board::Board() {
}


void Board::drawRectangleRepresentation() {
	int S = 2 * mapSize;
	int R = mapSize;

	for (int r = 0; r < R; r++) {
		std::cout << std::string(R - r - 1, ' ');

		for (int s = 0; s < S; s++) {
			int q = s - r;

			if (map.find(Hex(q, r, -q - r)) != map.end()) {
				std::cout << " . ";
			}
			else {
				std::cout << "   ";
			}
		}

		std::cout << std::endl;
	}
}
