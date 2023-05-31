#pragma once


#include <functional>
#include <unordered_set>


#include "Hex.h"


class Board {
private:
	int mapSize = 0;
	int piecesInLineToTriggerCapture = 0;
	int whitePlayerPiecesQuantity = 0;
	int blackPlayerPiecesQuantity = 0;

public:
    Board();

    void drawRectangleRepresentation();
};

