#include "King.h"

King::King(char PieceColor) :Piece(PieceColor)
{
}

King::~King()
{
}

char King::GetPiece()
{
	return 'K';
}

bool King::AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
	int RowMove = destinationRow - sourceRow;
	int ColumnMove = destinationColumn - sourceColumn;

	if (((RowMove <= 1) && (RowMove >= -1)) && ((ColumnMove <= 1) && (ColumnMove >= -1)))
	{
		return true;
	}
	else
	{
		return false;
	}
}