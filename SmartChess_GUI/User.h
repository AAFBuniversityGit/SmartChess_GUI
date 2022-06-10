#pragma once
#include "Cell.h"
#include "Data.h"

class User
{
public:
	Id id;

	bool CheckWin(Cells& cells);

	bool IsCellForYou(vector<Cell>::const_reference cell);
}