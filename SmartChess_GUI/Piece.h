#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Piece
{
public:
	Piece(char);

	~Piece();

	virtual char GetPiece() = 0;

	char GetColor();

	bool Allowed(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);

private:
	virtual bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* [8][8]) = 0;
	char xPieceColor;
};