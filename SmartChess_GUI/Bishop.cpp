#include "Bishop.h"

Bishop::Bishop(char PieceColor) :Piece(PieceColor)
{
}

Bishop::~Bishop()
{
}

char Bishop::GetPiece()
{
    return 'B';
}

bool Bishop::AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
    if ((destinationColumn - sourceColumn == sourceRow - destinationRow) || (destinationColumn - sourceColumn == destinationRow - sourceRow))
    {
        int RowCheck;
        int ColumnCheck;
        int RowProgress = (destinationRow - sourceRow > 0) ? 1 : -1;
        int ColumnProgress = (destinationColumn - sourceColumn > 0) ? 1 : -1;

        for (RowCheck = sourceRow + RowProgress, ColumnCheck = sourceColumn + ColumnProgress;
            RowCheck != destinationRow;
            RowCheck = RowCheck + RowProgress, ColumnCheck = ColumnCheck + ColumnProgress)
        {
            if (Board[RowCheck][ColumnCheck] != 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}