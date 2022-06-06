#include "PutPieces.h"

std::map<Id, sf::Texture> xo_textures;

PutPieces::PutPieces(Id _id) : id(_id)
{
    this->load_texture();
}

void PutPieces::load_texture()
{
    if (xo_textures.find(this->id) == xo_textures.end())
        xo_textures[this->id].loadFromFile(GetPiecePath(this->id));
    this->sprite.setTexture(xo_textures[this->id]);
    float piece_scale_x = (float)setting::CellSize / this->sprite.getTexture()->getSize().x;
    float piece_scale_y = (float)setting::CellSize / this->sprite.getTexture()->getSize().y;
    this->sprite.setScale(piece_scale_x, piece_scale_y);
}