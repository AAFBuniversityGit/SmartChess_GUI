#include "Rook.h"

Rook::Rook(char PieceColor) :Piece(PieceColor)
{
}

Rook::~Rook()
{
}

char Rook::GetPiece()
{
    return 'R';
}

bool Rook::AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
    if (sourceRow == destinationRow)
    {
        int Progress = (destinationColumn - sourceColumn > 0) ? 1 : -1;
        for (int ColumnCheck = sourceColumn + Progress; ColumnCheck != destinationColumn; ColumnCheck = ColumnCheck + Progress)
        {
            if (Board[sourceRow][ColumnCheck] != 0)
            {
                return false;
            }
        }
        return true;
    }
    else if (destinationColumn == sourceColumn)
    {
        int Progress = (destinationRow - sourceRow > 0) ? 1 : -1;
        for (int RowCheck = sourceRow + Progress; RowCheck != destinationRow; RowCheck = RowCheck + Progress)
        {
            if (Board[RowCheck][sourceColumn] != 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}