#pragma once
#include "Cell.h"
#include "Piece.h"
#include "Data.h"

class Board
{
public:
	Board(Id id);

	~Board();

	void Print();

	bool IsCheck(char PieceColor);

	bool AllowedToMove(char PieceColor);

	Piece* GameBoard[8][8];

	Id id;

	bool CheckWin(Cells& cells);

	bool IsCellForYou(vector<Cell>::const_reference cell);
};