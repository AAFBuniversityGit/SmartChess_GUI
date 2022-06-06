#pragma once
#include "Piece.h"
#include "Board.h"

class Controller
{
public:
	Controller(RenderWindow* _window);

	sf::RenderWindow* window;
	Cells cells;
	Board* user_x;
	Board* user_o;
	Board* curr_user;
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