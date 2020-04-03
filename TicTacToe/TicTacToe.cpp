#include <iostream>
#include "Game.h"


int main() {
	Game game;
	bool isFirst = true;
	while (1) {
		game.Draw();
		game.Input();
			std::pair<int, Game::tileState> gameState = game.CheckWin();
			if (gameState.first) { // Check if the game is over
				std::string state;
				// Check who won
				if (gameState.second == Game::tileState::pOne) {
					state = "Player One Win!!!";
				}
				else if (gameState.second == Game::tileState::pTwo) {
					state = "Player Two Win!!!";
				}
				else state = "Nobody Win :(";
				game.Draw(); // To show the last state of the game
				std::cout << state << " Congratss" << std::endl;
				break; // To end the game loop
			}
	}
}