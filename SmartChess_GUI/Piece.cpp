#include "Piece.h"

std::map<Id, sf::Texture> PieceTextures;

Piece::Piece(char PieceColor, Id _id) : xPieceColor(PieceColor), id(_id)
{
    this->LoadTexture();
}

Piece::~Piece()
{
}

char Piece::GetColor()
{
    return xPieceColor;
}

bool Piece::Allowed(int sourceRow, int sourceColumn, int destinationRow, int destinationColumn, Piece* Board[8][8])
{
    Piece* destination = Board[destinationRow][destinationColumn];
    if ((destination == 0) || (xPieceColor != destination->GetColor()))
    {
        return AllowedCoordinates(sourceRow, sourceColumn, destinationRow, destinationColumn, Board);
    }
}

void Piece::LoadTexture()
{
    if (PieceTextures.find(this->id) == PieceTextures.end())
        PieceTextures[this->id].loadFromFile(GetPiecePath(this->id));
    this->sprite.setTexture(PieceTextures[this->id]);
    float piece_scale_x = (float)setting::CellSize / this->sprite.getTexture()->getSize().x;
    float piece_scale_y = (float)setting::CellSize / this->sprite.getTexture()->getSize().y;
    this->sprite.setScale(piece_scale_x, piece_scale_y);
}
