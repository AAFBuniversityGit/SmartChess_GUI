#pragma once
#include "PutPieces.h"
#include "Board.h"
#include "User.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class Controller
{
public:
	Controller(RenderWindow* _window);

	sf::RenderWindow* window;
	Cells cells;
	User* user_x;
	User* user_o;
	User* curr_user;
	Font font;
	bool end;
	Text statusText;

	~Controller();

	void Start();

	void NextMove(Piece* Board[8][8]);

	void ChangeColor();

	bool IsGameOver();

	void Initialize();

	void Draw();

	void Run();

	void MouseClicked(const sf::Vector2i& position);

	void EmptyCellClicked(int row, int column);

	void PutPiecesInCell(int row, int column);

	void UpdateStatusText();

private:
	Board xGameBoard;
	char Turn;
};