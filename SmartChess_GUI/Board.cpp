#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board()
{
    for (int Row = 0; Row < 8; ++Row)
    {
        for (int Column = 0; Column < 8; ++Column)
        {
            GameBoard[Row][Column] = 0;
        }
    }

    int spaceFlag;
    string temp{};

    for (int Row = 0; Row < 8; ++Row)
    {
        spaceFlag = 0;

        getline(cin, temp);

        for (int Column = 0; Column < 8; ++Column)
        {
            char colorTemp;
            if (temp[spaceFlag] == '-')
            {
                GameBoard[Row][Column] = 0;
                spaceFlag += 3;
            }
            else
            {
                if (temp[spaceFlag] == 'K')
                {
                    GameBoard[Row][Column] = new King(temp[spaceFlag + 1]);
                }
                else if (temp[spaceFlag] == 'Q')
                {
                    GameBoard[Row][Column] = new Queen(temp[spaceFlag + 1]);
                }
                else if (temp[spaceFlag] == 'B')
                {
                    GameBoard[Row][Column] = new Bishop(temp[spaceFlag + 1]);
                }
                else if (temp[spaceFlag] == 'N')
                {
                    GameBoard[Row][Column] = new Knight(temp[spaceFlag + 1]);
                }
                else if (temp[spaceFlag] == 'R')
                {
                    GameBoard[Row][Column] = new Rook(temp[spaceFlag + 1]);
                }
                else if (temp[spaceFlag] == 'P')
                {
                    GameBoard[Row][Column] = new Pawn(temp[spaceFlag + 1]);
                }
                spaceFlag += 3;
            }
        }
    }
}

Board::~Board()
{
    for (int Row = 0; Row < 8; ++Row)
    {
        for (int Column = 0; Column < 8; ++Column)
        {
            delete GameBoard[Row][Column];
            GameBoard[Row][Column] = 0;
        }
    }
}

void Board::Print()
{
    for (int Row = 0; Row < 8; ++Row)
    {
        for (int Column = 0; Column < 8; ++Column)
        {
            if (GameBoard[Row][Column] != 0)
            {
                std::cout << GameBoard[Row][Column]->GetPiece() << GameBoard[Row][Column]->GetColor() << ' ';
            }
            else
            {
                std::cout << "-- ";
            }
        }
        std::cout << endl;
    }
}

bool Board::IsCheck(char PieceColor)
{
    int KingRow;
    int KingColumn;

    for (int Row = 0; Row < 8; ++Row)
    {
        for (int Column = 0; Column < 8; ++Column)
        {
            if (GameBoard[Row][Column] != 0)
            {
                if (GameBoard[Row][Column]->GetColor() == PieceColor)
                {
                    if (GameBoard[Row][Column]->GetPiece() == 'K')
                    {
                        KingRow = Row;
                        KingColumn = Column;
                    }
                }
            }
        }
    }

    for (int Row = 0; Row < 8; ++Row)
    {
        for (int Column = 0; Column < 8; ++Column)
        {
            if (GameBoard[Row][Column] != 0)
            {
                if (GameBoard[Row][Column]->GetColor() != PieceColor)
                {
                    if (GameBoard[Row][Column]->Allowed(Row, Column, KingRow, KingColumn, GameBoard))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Board::AllowedToMove(char PieceColor)
{
    for (int Row = 0; Row < 8; ++Row)
    {
        for (int Column = 0; Column < 8; ++Column)
        {
            if (GameBoard[Row][Column] != 0)
            {
                if (GameBoard[Row][Column]->GetColor() == PieceColor)
                {
                    for (int RowMove = 0; RowMove < 8; ++RowMove)
                    {
                        for (int ColumnMove = 0; ColumnMove < 8; ++ColumnMove)
                        {
                            if (GameBoard[Row][Column]->Allowed(Row, Column, RowMove, ColumnMove, GameBoard))
                            {
                                Piece* pieceTemp = GameBoard[RowMove][ColumnMove];
                                GameBoard[RowMove][ColumnMove] = GameBoard[Row][Column];
                                GameBoard[Row][Column] = 0;
                                bool IsAllowed = !IsCheck(PieceColor);

                                GameBoard[Row][Column] = GameBoard[RowMove][ColumnMove];
                                GameBoard[RowMove][ColumnMove] = pieceTemp;

                                if (IsAllowed)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

