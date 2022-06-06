#pragma once

#include <vector>
#include "Data.h"
#include "Piece.h"

using namespace std;

class Cell
{
public:
    RectangleShape rect;
    CellStatus cell_status = EMPTY;
    Piece* piece;
};

typedef typename vector<vector<Cell>> Cells;
