#include "Controller.h"
#include <string>
#include <iostream>

using namespace std;

Controller::Controller(RenderWindow* _window) :Turn('W'), window(_window)
{
    window->setFramerateLimit(60);
}

Controller::~Controller()
{
}

void Controller::Start()
{
    do
    {
        NextMove(xGameBoard.GameBoard);
    } while (!IsGameOver());
}

void Controller::NextMove(Piece* Board[8][8])
{
    bool CanMove = false;
    do {
        string temp{}, start{}, final{};
        int StartRow, StartColumn, FinalRow, FinalColumn;
        cin >> temp;
        start = temp.substr(0, 2);
        final = temp.substr(4, 2);

        if (start[1] == '1')
            StartRow = 7;
        else if (start[1] == '2')
            StartRow = 6;
        else if (start[1] == '3')
            StartRow = 5;
        else if (start[1] == '4')
            StartRow = 4;
        else if (start[1] == '5')
            StartRow = 3;
        else if (start[1] == '6')
            StartRow = 2;
        else if (start[1] == '7')
            StartRow = 1;
        else if (start[1] == '8')
            StartRow = 0;

        if (final[1] == '1')
            FinalRow = 7;
        else if (final[1] == '2')
            FinalRow = 6;
        else if (final[1] == '3')
            FinalRow = 5;
        else if (final[1] == '4')
            FinalRow = 4;
        else if (final[1] == '5')
            FinalRow = 3;
        else if (final[1] == '6')
            FinalRow = 2;
        else if (final[1] == '7')
            FinalRow = 1;
        else if (final[1] == '8')
            FinalRow = 0;

        if (start[0] == 'a')
            StartColumn = 0;
        else if (start[0] == 'b')
            StartColumn = 1;
        else if (start[0] == 'c')
            StartColumn = 2;
        else if (start[0] == 'd')
            StartColumn = 3;
        else if (start[0] == 'e')
            StartColumn = 4;
        else if (start[0] == 'f')
            StartColumn = 5;
        else if (start[0] == 'g')
            StartColumn = 6;
        else if (start[0] == 'h')
            StartColumn = 7;

        if (final[0] == 'a')
            FinalColumn = 0;
        else if (final[0] == 'b')
            FinalColumn = 1;
        else if (final[0] == 'c')
            FinalColumn = 2;
        else if (final[0] == 'd')
            FinalColumn = 3;
        else if (final[0] == 'e')
            FinalColumn = 4;
        else if (final[0] == 'f')
            FinalColumn = 5;
        else if (final[0] == 'g')
            FinalColumn = 6;
        else if (final[0] == 'h')
            FinalColumn = 7;

        Piece* CurrentPieceTurn = Board[StartRow][StartColumn];

        if ((StartRow >= 0 && StartRow <= 7) && (StartColumn >= 0 && StartColumn <= 7) &&
            (FinalRow >= 0 && FinalRow <= 7) && (FinalColumn >= 0 && FinalColumn <= 7))
        {
            Piece* CurrentPiece = Board[StartRow][StartColumn];

            if ((CurrentPiece != 0) && (CurrentPiece->GetColor() == Turn))
            {
                if (CurrentPiece->Allowed(StartRow, StartColumn, FinalRow, FinalColumn, Board))
                {
                    Piece* pieceTemp = Board[FinalRow][FinalColumn];
                    Board[FinalRow][FinalColumn] = Board[StartRow][StartColumn];
                    Board[StartRow][StartColumn] = 0;

                    if (!xGameBoard.IsCheck(Turn))
                    {
                        delete pieceTemp;
                        CanMove = true;
                    }
                    else
                    {
                        Board[StartRow][StartColumn] = Board[FinalRow][FinalColumn];
                        Board[FinalRow][FinalColumn] = pieceTemp;
                    }
                }
            }
        }
        if (CanMove)
        {
            std::cout << "done" << endl;
        }
        else if (!CanMove && CurrentPieceTurn->GetColor() != Turn)
        {
            std::cout << "not your turn" << endl;
        }
        else if (!CanMove)
        {
            std::cout << "try again" << endl;
        }
        IsGameOver();
    } while (!CanMove);
}

void Controller::ChangeColor()
{
    Turn = (Turn == 'W') ? 'B' : 'W';
}

bool Controller::IsGameOver()
{
    bool CanMove(false);
    CanMove = xGameBoard.AllowedToMove(Turn);

    if (!CanMove)
    {
        if (xGameBoard.IsCheck(Turn))
        {
            ChangeColor();
            if (Turn == 'W')
                std::cout << "white win" << std::endl;
            else if (Turn == 'B')
                std::cout << "black win" << std::endl;
        }
        else
        {
            std::cout << "Stalemate!" << std::endl;
        }
    }
    return !CanMove;
}

void Controller::Initialize()
{
    end = false;
    this->cells.resize(3);
    for (int row = 0; row < 3; row++)
    {
        this->cells[row].resize(3);
        for (int column = 0; column < 3; column++)
        {
            this->cells[row][column].rect.setSize(sf::Vector2f(setting::CellSize, setting::CellSize));
            this->cells[row][column].rect.setFillColor(setting::CellColor);
            this->cells[row][column].rect.setPosition(GetCellPosition(row, column));
        }
    }
    this->curr_user = this->user_x;
    font.loadFromFile("resources/fonts/roboto.ttf");
    statusText.setFont(font);
    statusText.setCharacterSize(30);
    statusText.setStyle(sf::Text::Regular);
    statusText.setFillColor(sf::Color::Black);
    statusText.setPosition(400.f, 80.f);
    this->UpdateStatusText();
}

void Controller::Draw()
{
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
        {
            this->window->draw(this->cells[row][column].rect);
            if (this->cells[row][column].CellStatus == OCCUPIED)
                this->window->draw(this->cells[row][column].piece->sprite);
        }
    this->window->draw(this->statusText);
}

void Controller::Run()
{
    this->Initialize();
    this->window->display();
    while (this->window->isOpen()) {
        sf::Event event;

        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
            if (!this->end && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                this->MouseClicked(sf::Mouse::getPosition(*(this->window)));
            }
        }
        this->window->clear(sf::Color(150, 150, 150));
        this->UpdateStatusText();
        this->Draw();
        this->window->display();
    }
}
