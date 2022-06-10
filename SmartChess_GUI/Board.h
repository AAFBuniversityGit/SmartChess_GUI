#pragma once

#include "Piece.h"

class Board
{
public:
	Board();

	~Board();

	void Print();

	bool IsCheck(char PieceColor);

	bool AllowedToMove(char PieceColor);

	Piece* GameBoard[8][8];
};