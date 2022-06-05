#pragma once
#include "Piece.h"
#include "Board.h"

class Controller
{
public:
	Controller();

	~Controller();

	void Start();

	void NextMove(Piece* Board[8][8]);

	void ChangeColor();

	bool IsGameOver();

private:
	Board xGameBoard;
	char Turn;
};