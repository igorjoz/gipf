#include "Game.h"


Game::Game() : isWhitePlayerTurn{ true } {
	readGameSettings();

	whitePiecesLeft = whitePiecesQuantity;
	blackPiecesLeft = blackPiecesQuantity;

	board = new Board(boardSize);
}


Game::~Game() {
	delete board;
}


void Game::readGameSettings() {
	char startingPlayerCharacter;

	int unknownVariable1 = 0;
	int unknownVariable2 = 0;
	
	std::cin >> boardSize >> piecesInLineToTriggerCapture;
	
	std::cin >> whitePiecesQuantity >> blackPiecesQuantity;
	
	std::cin >> unknownVariable1 >> unknownVariable2;

	std::cin >> startingPlayerCharacter;

	if (startingPlayerCharacter == 'B') {
		isWhitePlayerTurn = false;
	}
}


//void Game::drawRectangleRepresentation() {
//	board->drawRectangleRepresentation();
//}


void Game::drawHexagonalRepresentation() {
	board->drawHexagonalRepresentation();
}
