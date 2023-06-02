#pragma once


#include <functional>
#include <algorithm>
#include <unordered_set>


#include "Hex.h"
#include "Resources.cpp"


class Board {
private:
    std::unordered_set<Hex> map;
    
    int size = 0;

    int spacesQuantity = 0;
    bool hasPassedMiddleLine = false;

public:
    Board(int size);

    void printBoard();
    void readBoard();

    void drawHexagonalRepresentation();

    void handleSpacesWhileDrawing();

    void testBoardPopulation();
};

