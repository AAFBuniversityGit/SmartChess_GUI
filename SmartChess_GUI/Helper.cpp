#include "Helper.h"

sf::Vector2f GetCellPosition(int row, int column)
{
    return sf::Vector2f(
        setting::CellOffset + column * (setting::CellSize + setting::LineSpace),
        setting::CellOffset + row * (setting::CellSize + setting::LineSpace));
}

string GetPiecePath(Id id)
{
    string path = "resources/images/";
    path += (id == X ? "X" : "O");
    return path + ".png";
}

int GetCellIndex(int x)
{
    x -= setting::CellOffset;
    if (x < 0)
        return -1;
    int cell_plus_space = setting::CellSize + setting::LineSpace;
    int index = x / cell_plus_space;
    if (index > 2 || x > index * cell_plus_space + setting::CellSize)
        return -1;
    return index;
}

string get_naGetNameofIdme_of_id(Id id)
{
    return id == X ? "X" : "O";
}