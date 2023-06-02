#include "Board.h"


Board::Board(int size) :
	size { size },
	spacesQuantity { size },
	hasPassedMiddleLine{ false } {
	readBoard();
}


void Board::printBoard() {
	for (auto& hex : map) {
		std::cout << hex.q << " " << hex.r << " " << hex.s << "\n";
	}
}


void Board::readBoard() {
	size--;

	for (int q = -size; q <= size; q++) {
		int r1 = std::max(-size, -q - size);
		int r2 = std::min(size, -q + size);

		for (int r = r1; r <= r2; r++) {
			char character;

			std::cin >> character;

			if (character == '_') {
				map.insert(Hex(q, r, -q - r));
			}
			else if (character == 'W') {
				map.insert(Hex(q, r, -q - r, true, true));
			}
			else {
				map.insert(Hex(q, r, -q - r, true, false));
			}
		}
	}

	size++;

	drawHexagonalRepresentation();
}


void Board::drawHexagonalRepresentation() {
	for (int q = -size; q <= size; q++) {
		int r1 = std::max(-size, -q - size);
		int r2 = std::min(size, -q + size);

		handleSpacesWhileDrawing();

		for (int r = r1; r <= r2; r++) {
			auto hex = map.find(Hex(q, r, -q - r));
			
			if (hex != map.end()) {
				if (!hex->isOccupied) {
					std::cout << "_";
				}
				else if (hex->isWhite) {
					std::cout << "W";
				}
				else {
					std::cout << "B";
				}

				std::cout << " ";
			}
			else if (r != r1) {
				std::cout << "  ";
			}
		}

		std::cout << "\n";
	}
}


void Board::handleSpacesWhileDrawing() {
	for (int i = 0; i < spacesQuantity; i++) {
		std::cout << " ";
	}

	if (spacesQuantity == 0) {
		hasPassedMiddleLine = true;
	}

	if (!hasPassedMiddleLine) {
		spacesQuantity--;
	}
	else {
		spacesQuantity++;
	}
}


void Board::testBoardPopulation() {
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
