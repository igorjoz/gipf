#pragma once


#include "Board.h"


class Game
{
private:
	Board* board;
	
	int boardSize = 0;
	int piecesInLineToTriggerCapture = 0;
	int whitePlayerPiecesQuantity = 0;
	int blackPlayerPiecesQuantity = 0;

public:
	Game();
	~Game();

	void readGameSettings();

	void drawRectangleRepresentation();
	void drawHexagonalRepresentation();
};

