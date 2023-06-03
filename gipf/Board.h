#pragma once


#include <functional>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <string>


#include "Hex.h"
#include "Resources.h"


class Board {
private:
    std::unordered_set<Hex> map;
    
    int size = 0;
	int piecesInLineToTriggerCapture = 0;

	int totalEmptyPlaces = 0;
	int whitePiecesPlaced = 0;
	int blackPiecesPlaced = 0;

    int spacesQuantity = 0;
    bool hasPassedMiddleLine = false;

	bool isCorrupted = false;
	int foundChainsQuantity = 0;

public:
	Board(int size, int piecesInLineToTriggerCapture);

    void read();
    void print();
	void printChain(const std::vector<Hex>& chain);

    void handleSpacesWhileDrawing();

	void findChains();
	void dfs(const Hex& hex, int direction, std::unordered_set<Hex>& visited, std::vector<Hex>& chain);

	int getTotalEmptyPlaces() const;
	int getWhitePiecesPlaced() const;
	int getBlackPiecesPlaced() const;

	bool getIsCorrupted() const;
	int getFoundChainsQuantity() const;

	void setIsCorrupted(bool isCorrupted);

    void testBoardPopulation();
};

