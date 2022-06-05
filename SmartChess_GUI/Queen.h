#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(char);

	~Queen();

private:
	virtual char GetPiece();

	bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);
};
