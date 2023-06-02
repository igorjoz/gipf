#include "Board.h"


Board::Board(int size) :
	size { size },
	totalEmptyPlaces{ 0 },
	whitePiecesPlaced{ 0 },
	blackPiecesPlaced{ 0 },
	spacesQuantity { size },
	hasPassedMiddleLine{ false },
	isCorrupted{ false } {
}


void Board::read() {
	size--;

	int placesInHexagonInTotal = 3 * size * (size + 1) + 1;
	int height = 2 * size + 1;

	int newLineCount = 0;
	int placesCount = 0;
	std::string boardString = "";

	char character = getchar();
	character = getchar();

	while (newLineCount < height) {
		//if (character == '\n')
		// if new line or end of file
		if (character == '\n' or character == EOF) {
			newLineCount++;
		}
		else if (character == '_' or character == 'W' or character == 'B') {
			boardString += character;
			placesCount++;
		}
		
		character = getchar();
	}

	//std::cerr << placesInHexagonInTotal << "\n";
	//std::cerr << "counted places: " << placesCount << "\n";

	if (placesCount != placesInHexagonInTotal) {
		std::cout << "WRONG_BOARD_ROW_LENGTH\n";
		isCorrupted = true;

		return;
	}

	int placeIndex = 0;

	for (int q = -size; q <= size; q++) {
		int r1 = std::max(-size, -q - size);
		int r2 = std::min(size, -q + size);

		for (int r = r1; r <= r2; r++) {
			character = boardString[placeIndex++];

			if (character == '_') {
				map.insert(Hex(q, r, -q - r));
				totalEmptyPlaces++;
			}
			else if (character == 'W') {
				map.insert(Hex(q, r, -q - r, true, true));
				whitePiecesPlaced++;
			}
			else {
				map.insert(Hex(q, r, -q - r, true, false));
				blackPiecesPlaced++;
			}
		}
	}

	size++;
}


void Board::print() {
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


int Board::getTotalEmptyPlaces() const {
	return totalEmptyPlaces;
}


int Board::getWhitePiecesPlaced() const {
	return whitePiecesPlaced;
}


int Board::getBlackPiecesPlaced() const {
	return blackPiecesPlaced;
}


bool Board::getIsCorrupted() const {
	return isCorrupted;
}


void Board::setIsCorrupted(bool isCorrupted) {
	this->isCorrupted = isCorrupted;
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
