#pragma once
#include "Piece.h"
#include "Board.h"

class Controller
{
public:
	Controller(RenderWindow* _window);

	sf::RenderWindow* window;
	Font font;
	Text statusText;

	~Controller();

	void Start();

	void NextMove(Piece* Board[8][8]);

	void ChangeColor();

	bool IsGameOver();

private:
	Board xGameBoard;
	char Turn;
};