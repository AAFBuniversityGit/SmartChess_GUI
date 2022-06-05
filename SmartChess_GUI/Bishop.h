#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(char);

	~Bishop();

private:
	virtual char GetPiece();

	bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);
};
