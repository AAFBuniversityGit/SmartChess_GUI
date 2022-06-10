#pragma once
#include "Cell.h"
#include "Data.h"

class User
{
public:
	User(Id id);

	Id id;

	bool CheckWin(Cells& cells);

	bool IsCellForYou(Cell& cell);
};