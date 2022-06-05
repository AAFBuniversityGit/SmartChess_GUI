#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(char);

	~Knight();

private:
	virtual char GetPiece();

	bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);
};
