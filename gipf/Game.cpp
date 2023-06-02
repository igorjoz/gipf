#include "Game.h"


Game::Game() : isWhitePlayerTurn{ true } {
	readGameSettings();

	board = new Board(boardSize);
	board->read();
	
	checkBoardAfterReading();
}


Game::~Game() {
	delete board;
}


void Game::readGameSettings() {
	std::cin >> boardSize >> piecesInLineToTriggerCapture;
	
	std::cin >> whitePiecesQuantity >> blackPiecesQuantity;
	
	std::cin >> whitePiecesLeft >> blackPiecesLeft;

	std::cin >> initialPlayerCharacter;

	if (initialPlayerCharacter == 'B') {
		isWhitePlayerTurn = false;
	}
}


void Game::checkBoardAfterReading() {
	if (board->getWhitePiecesPlaced() > whitePiecesQuantity - whitePiecesLeft) {
		std::cout << "WRONG_WHITE_PAWNS_NUMBER\n";
		board->setIsCorrupted(true);
	}
	else if (board->getBlackPiecesPlaced() > blackPiecesQuantity - blackPiecesLeft) {
		std::cout << "WRONG_BLACK_PAWNS_NUMBER\n";
		board->setIsCorrupted(true);
	}
	else if (!board->getIsCorrupted()) {
		std::cout << "BOARD_STATE_OK\n";
	}
}


void Game::printBoardInfo() {
	if (board->getIsCorrupted()) {
		std::cout << "EMPTY_BOARD\n";
		return;
	}
	
	std::cout << boardSize << " " << piecesInLineToTriggerCapture << " ";
	std::cout << whitePiecesQuantity << " " << blackPiecesQuantity << "\n";

	std::cout << whitePiecesLeft << " " << blackPiecesLeft << " ";
	std::cout << initialPlayerCharacter << " " << "\n";

	board->print();
}
