#include "Knight.h"

Knight::Knight(char PieceColor) :Piece(PieceColor)
{
}

Knight::~Knight()
{
}

char Knight::GetPiece()
{
    return 'N';
}

bool Knight::AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
    if ((sourceColumn == destinationColumn + 2) || (sourceColumn == destinationColumn - 2))
    {
        if ((sourceRow == destinationRow + 1) || (sourceRow == destinationRow - 1))
        {
            return true;
        }
    }

    if ((sourceColumn == destinationColumn - 1) || (sourceColumn == destinationColumn + 1))
    {
        if ((sourceRow == destinationRow + 2) || (sourceRow == destinationRow - 2))
        {
            return true;
        }
    }

    return false;
}