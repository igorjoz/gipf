#include "Board.h"


Board::Board(int size, int piecesInLineToTriggerCapture) :
	size{ size },
	piecesInLineToTriggerCapture{ piecesInLineToTriggerCapture },
	totalEmptyPlaces{ 0 },
	whitePiecesPlaced{ 0 },
	blackPiecesPlaced{ 0 },
	spacesQuantity { size },
	hasPassedMiddleLine{ false },
	isCorrupted{ false },
	foundChainsQuantity{ 0 } {
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
		if (character == '\n' or character == EOF) {
			newLineCount++;
		}
		else if (character == '_' or character == 'W' or character == 'B') {
			boardString += character;
			placesCount++;
		}
		
		character = getchar();
	}

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


void Board::printChain(const std::vector<Hex>& chain) {
	std::cerr << "Chain:\n";

	for (const auto& hex : chain) {
		std::cerr << hex.q << " " << hex.r << " " << hex.s << "\n";
	}
	std::cerr << "\n";
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


//void Board::findChains() {
//	for (int direction = 0; direction < 6; direction += 2) { // 0, 2, 4 are left to right, top to bottom, top left to bottom right
//		std::unordered_set<Hex> visited;
//		// chain set
//		std::vector<Hex> chain;
//
//		// found chains vector
//		std::vector<std::vector<Hex>> foundChains;
//
//		for (const auto& hex : map) {
//			if (hex.isOccupied) {
//				visited.clear();
//				chain.clear();
//				dfs(hex, direction, visited, chain);
//				if (chain.size() >= piecesInLineToTriggerCapture) {
//					// check if chain was not found earlier
//					if (foundChainsQuantity > 0) {
//						bool isFound = false;
//						for (const auto& foundChain : foundChains) {
//							if (chain == foundChain) {
//								isFound = true;
//								break;
//							}
//						}
//						if (isFound) {
//							continue;
//						}
//					}
//
//					foundChainsQuantity++;
//					foundChains.push_back(chain);
//					//printChain(chain); // Print or otherwise use the found chain
//				}
//			}
//		}
//	}
//}


std::string hexToString(const Hex& hex) {
	return std::to_string(hex.q) + ',' + std::to_string(hex.r) + ',' + std::to_string(hex.s);
}


std::string chainToString(const std::vector<Hex>& chain) {
	std::vector<std::string> stringChain;
	for (const auto& hex : chain) {
		stringChain.push_back(hexToString(hex));
	}
	std::sort(stringChain.begin(), stringChain.end());
	std::string chainString;
	for (const auto& hexString : stringChain) {
		chainString += hexString + ';';
	}
	return chainString;
}



void Board::findChains() {
	std::set<std::string> uniqueChains;
	std::vector<int> desiredDirections = { 1, 5, 0, 4 };

	for (const auto& direction : desiredDirections) {
		std::unordered_set<Hex> visited;
		std::vector<Hex> chain;
		std::vector<Hex> longestChain;

		for (const auto& hex : map) {
			if (hex.isOccupied) {
				visited.clear();
				chain.clear();
				dfs(hex, direction, visited, chain);

				if (chain.size() > longestChain.size()) {
					longestChain = chain;
				}

				if (longestChain.size() >= piecesInLineToTriggerCapture) {
					std::string chainString = chainToString(longestChain);

					if (uniqueChains.count(chainString) == 0) {
						uniqueChains.insert(chainString);

						foundChainsQuantity++;

						//printChain(chain);
					}
				}
			}
		}

		// clear unique chains
		uniqueChains.clear();
	}
}


void Board::dfs(const Hex& hex, int direction, std::unordered_set<Hex>& visited, std::vector<Hex>& chain) {
	visited.insert(hex);
	chain.push_back(hex);
	
	Hex nextHex = hex.neighbor(direction);
	auto it = map.find(nextHex);
	
	if (it != map.end() && visited.count(*it) == 0 && it->isOccupied && it->isWhite == hex.isWhite) {
		dfs(*it, direction, visited, chain);
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


int Board::getFoundChainsQuantity() const {
	return foundChainsQuantity;
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
