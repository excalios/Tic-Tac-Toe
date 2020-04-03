#pragma once
#include <iostream>
#include <utility>
#include <string>

class Game
{
public:
	enum tileState {
		empty = 2, pOne, pTwo
	};
private:
	tileState tile[3][3] = { {empty, empty, empty}, {empty, empty, empty}, {empty, empty, empty}};
	bool pOneTurn = true;
public:
	void Draw();
	std::pair<bool, tileState> CheckWin();
	void Input();
};

