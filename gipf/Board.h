#pragma once


#include <functional>
#include <unordered_set>


#include "Hex.h"
#include "Resources.cpp"


class Board {
private:
    int size;

    std::unordered_set<Hex> map;

public:
    Board(int size);

    void printBoard();
    void drawRectangleRepresentation();
    void drawHexagonalRepresentation();
};

