#include "Board.h"


Board::Board(int size) : size { size } {
	size--;
	
	for (int q = -size; q <= size; q++) {
		int r1 = std::max(-size, -q - size);
		int r2 = std::min(size, -q + size);

		for (int r = r1; r <= r2; r++) {
			map.insert(Hex(q, r, -q - r));
		}
	}

	size++;
}


void Board::printBoard() {
	for (auto& hex : map) {
		std::cout << hex.q << " " << hex.r << " " << hex.s << "\n";
	}
}


void Board::drawRectangleRepresentation() {
	int S = 2 * size;
	int R = size;

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

		std::cout << "\n";
	}
}


void Board::drawHexagonalRepresentation() {
	int spacesQuantity = size;
	bool passedMiddle = false;
	
	for (int q = -size; q <= size; q++) {
		int r1 = std::max(-size, -q - size);
		int r2 = std::min(size, -q + size);
		//std::cout << std::string(std::max(0, -r1), ' ');

		for (int i = 0; i < spacesQuantity; i++) {
			std::cout << " ";
		}

		if (spacesQuantity == 0) {
			passedMiddle = true;
		}
		
		if (!passedMiddle) {
			spacesQuantity--;
		}
		else {
			spacesQuantity++;
		}

		for (int r = r1; r <= r2; r++) {
			if (map.find(Hex(q, r, -q - r)) != map.end()) {
				std::cout << "_ ";
			}
			else if (r != r1) {
				std::cout << "  ";
			}
		}

		std::cout << "\n";
	}
}

