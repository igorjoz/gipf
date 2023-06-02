#include "ProgramController.h"


ProgramController::ProgramController() {
	game = nullptr;
}


ProgramController::~ProgramController() {
	delete game;
}


void ProgramController::run() {
	commandString = "";

	//readCommand()
	
	while (std::getline(std::cin, commandString)) {
		if (commandString.empty()) {
			//std::cout << "\"" << commandString << "\"\n";
			
			std::getline(std::cin, commandString);
			std::getline(std::cin, commandString);

			//std::cout << "\"" << commandString << "\"\n";
			
			if (commandString.empty()) {
				break;
			}
		}

		// remove white spaces
		commandString.erase(std::remove_if(commandString.begin(), commandString.end(), isspace), commandString.end());

		readAndExecuteCommand();
	}
}


bool ProgramController::readCommand() {
	commandString = "";

	char character = ' ';

	while (character = getchar()) {
		if (character == '\n') {
			break;
		}

		commandString += character;
	}

	commandString.erase(std::remove_if(commandString.begin(), commandString.end(), isspace), commandString.end());

	if (commandString.empty()) {
		return false;
	}

	return true;
}


void ProgramController::readAndExecuteCommand() {
	if (commandString == "LOAD_GAME_BOARD") {
		//delete game;
		
		game = new Game();
	}
	else if (commandString == "PRINT_GAME_BOARD") {
		game->printBoardInfo();
	}
	else {
		std::cerr << "INVALID INPUIT";
	}
}
