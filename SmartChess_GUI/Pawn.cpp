#include "Pawn.h"

Pawn::Pawn(char PieceColor) :Piece(PieceColor)
{
}

Pawn::~Pawn()
{
}

char Pawn::GetPiece()
{
    return 'P';
}

bool Pawn::AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
    Piece* CheckDestination = Board[destinationRow][destinationColumn];

    if (CheckDestination == 0)
    {
        if (sourceColumn == destinationColumn)
        {
            if (GetColor() == 'W')
            {
                if (destinationRow == sourceRow - 1)
                {
                    return true;
                }
            }
            else {
                if (destinationRow == sourceRow + 1)
                {
                    return true;
                }
            }
        }
    }
    else {
        if ((sourceColumn == destinationColumn + 1) || (sourceColumn == destinationColumn - 1))
        {
            if (GetColor() == 'W') {
                if (destinationRow == sourceRow - 1)
                {
                    return true;
                }
            }
            else {
                if (destinationRow == sourceRow + 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}