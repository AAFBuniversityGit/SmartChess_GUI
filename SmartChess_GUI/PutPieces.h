#pragma once

#include <SFML/Graphics.hpp>
#include "helper.h"
#include "setting.h"

class PutPieces
{
public:
    PutPieces(Id _id);
    sf::Sprite sprite;
    Id id;
    void load_texture();
};