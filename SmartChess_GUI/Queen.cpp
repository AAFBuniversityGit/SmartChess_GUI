#include "Queen.h"

Queen::Queen(char PieceColor) :Piece(PieceColor)
{
}

Queen::~Queen()
{
}

char Queen::GetPiece()
{
    return 'Q';
}

bool Queen::AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
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
    else if ((destinationColumn - sourceColumn == sourceRow - destinationRow) || (destinationColumn - sourceColumn == destinationRow - sourceRow))
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