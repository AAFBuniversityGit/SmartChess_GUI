#include "Helper.h"

#include "Controller.h"

sf::Vector2f GetCellPosition(int row, int column)
{
    return sf::Vector2f(
        setting::CellOffset + column * (setting::CellSize + setting::LineSpace),
        setting::CellOffset + row * (setting::CellSize + setting::LineSpace));
}

string GetPiecePath(Id id)
{
    string path = "resources/images/";
    string imageName;
    if (id == 'K')
    {
        imageName == "k";
    }
    else if (id == 'Q')
    {
        imageName == "Q";
    }
    else if (id == 'B')
    {
        imageName == "B";
    }
    else if (id == 'N')
    {
        imageName == "N";
    }
    else if (id == 'R')
    {
        imageName == "R";
    }
    else if (id == 'P')
    {
        imageName == "P";
    }
    path = imageName;
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

string GetNameofId(Id id)
{
    return id == W ? "W" : "B";
}