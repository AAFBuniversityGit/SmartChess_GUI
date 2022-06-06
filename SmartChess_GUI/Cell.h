#pragma once

#include "vector"
#include "Data.h"
#include "Piece.h"

class Cell
{
public:
    sf::RectangleShape rect;
    CellStatus CellStatus = EMPTY;
    Piece* piece;
};

typedef typename std::vector<std::vector<Cell>> Cells;
