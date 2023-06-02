#pragma once


#include <functional>
#include <algorithm>
#include <unordered_set>


#include "Hex.h"
#include "Resources.h"


class Board {
private:
    std::unordered_set<Hex> map;
    
    int size = 0;

	int totalEmptyPlaces = 0;
	int whitePiecesPlaced = 0;
	int blackPiecesPlaced = 0;

    int spacesQuantity = 0;
    bool hasPassedMiddleLine = false;

	bool isCorrupted = false;

public:
    Board(int size);

    void read();
    void print();

    void handleSpacesWhileDrawing();

	int getTotalEmptyPlaces() const;
	int getWhitePiecesPlaced() const;
	int getBlackPiecesPlaced() const;

	bool getIsCorrupted() const;

	void setIsCorrupted(bool isCorrupted);

    void testBoardPopulation();
};

