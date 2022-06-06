#pragma once

#include "vector"
#include "Data.h"
#include "Piece.h"
#include "PutPieces.h"
#include "SFML/Graphics.hpp"

class Cell
{
public:
    sf::RectangleShape rect;
    CellStatus CellStatus = EMPTY;
    PutPieces* PutPieces;
};

typedef typename std::vector<std::vector<Cell>> Cells;
