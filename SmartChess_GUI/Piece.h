#pragma once
#include <SFML/Graphics.hpp>
#include "Helper.h"
#include "Setting.h"

using namespace sf;

class Piece
{
public:
	Piece(char, Id);

	~Piece();

	virtual char GetPiece() = 0;

	char GetColor();

	bool Allowed(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8]);

	Sprite sprite;

	Id id;

	void LoadTexture();
private:
	virtual bool AllowedCoordinates(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* [8][8]) = 0;
	char xPieceColor;
};