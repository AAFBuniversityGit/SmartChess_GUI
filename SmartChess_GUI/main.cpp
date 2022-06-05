#include "Controller.h";
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    /*Controller Game;
    Game.Start();*/
    RenderWindow window(VideoMode(800, 600), "Smart Chess", Style::Titlebar | Style::Close);
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}