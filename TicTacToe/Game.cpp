#include "Game.h"

void Game::Draw() {
	system("cls");
	//Drawing every row
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			std::cout << "\t";
			if (tile[row][col] == pOne) {
				std::cout << "O";
			}
			else if (tile[row][col] == pTwo) {
				std::cout << "X";
			}
			else
				std::cout << row+1 << " " << col+1;
			//Type the row and col number if tile is *empty for input
		}
		std::cout << std::endl << std::endl;
	}
}

std::pair<bool,Game::tileState> Game::CheckWin() {
	// Check for every row if it's the same
	for (int row = 0; row < 3; row++) {
		if(tile[row][0] != tileState::empty)
			if ((tile[row][0] == tile[row][1]) && (tile[row][0] == tile[row][2])) {
				return std::make_pair(true, tile[row][0]);
			}
	}
	// Check for every col if it's the same
	for (int col = 0; col < 3; col++) {
		if(tile[0][col] != tileState::empty)
			if ((tile[0][col] == tile[1][col]) && (tile[0][col] == tile[2][col])){
				return std::make_pair(true, tile[0][col]);
			}
	}
	// Check diagonal
	if ((tile[0][0] != empty) || (tile[0][2] != empty)) {
		if ((tile[0][0] == tile[1][1]) && (tile[0][0] == tile[2][2])) {
			return std::make_pair(true, tile[0][0]);
		}
		else if ((tile[0][2] == tile[1][1]) && (tile[0][2] == tile[2][0])) {
			return std::make_pair(true, tile[2][0]);
		}
	}
	else for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
			// Check if there is still an empty tile
			// To make sure the game is still "winnable"
			if(tile[row][col] == tileState::empty)
				return std::make_pair(false, tileState::empty);
		}
	}

	// There is no more empty tile
	// The game is over
	// No one wins
	return std::make_pair(true, tileState::empty);
}

void Game::Input() {
	int rNum, cNum;
	do {
	std::string player = pOneTurn ? "Player One (O)" : "Player Two(X)";
	std::cout << player << " turn to pick number to fill: " << std::endl;
	std::cout << "Row number : "; std::cin >> rNum;
	std::cout << "Col number : "; std::cin >> cNum;
	} while (tile[rNum - 1][cNum - 1] != tileState::empty);
	if(pOneTurn)
		tile[rNum - 1][cNum - 1] = pOne;
	else
		tile[rNum - 1][cNum - 1] = pTwo;	
	pOneTurn = !pOneTurn;
}
