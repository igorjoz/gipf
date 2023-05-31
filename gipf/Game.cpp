#include "Game.h"


Game::Game() {
	readGameSettings();

	board = new Board(boardSize);
}


Game::~Game() {
	delete board;
}


void Game::readGameSettings() {
	std::cin >> boardSize >> piecesInLineToTriggerCapture;
	std::cin >> whitePlayerPiecesQuantity >> blackPlayerPiecesQuantity;
}


void Game::drawRectangleRepresentation() {
	board->drawRectangleRepresentation();
}


void Game::drawHexagonalRepresentation() {
	board->drawHexagonalRepresentation();
}
