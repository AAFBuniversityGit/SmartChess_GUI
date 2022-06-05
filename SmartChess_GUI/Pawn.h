#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(char);
	~Pawn();

private:
	virtual char GetPiece();

	bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);
};
