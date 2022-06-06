#include "Piece.h"

Piece::Piece(char PieceColor) : xPieceColor(PieceColor)
{
}

Piece::~Piece()
{
}

char Piece::GetColor()
{
    return xPieceColor;
}

bool Piece::Allowed(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
    Piece* destination = Board[destinationRow][destinationColumn];
    if ((destination == 0) || (xPieceColor != destination->GetColor()))
    {
        return AllowedCoordinates(sourceRow, sourceColumn, destinationRow, destinationColumn, Board);
    }
}
