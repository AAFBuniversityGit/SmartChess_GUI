#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(char);

	~King();

private:
	virtual char GetPiece();

	bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);
};