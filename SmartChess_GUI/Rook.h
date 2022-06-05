#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(char);

	~Rook();

private:
	virtual char GetPiece();

	bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);
};
