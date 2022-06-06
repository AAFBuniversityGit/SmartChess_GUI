#pragma once

#include "SFML/Graphics.hpp"
#include "Data.h"
#include "Setting.h"

using namespace std;

sf::Vector2f GetCellPosition(int row, int column);

string GetPiecePath(Id id);

int GetCellIndex(int x);

string GetNameofId(Id id);