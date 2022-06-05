#include "Controller.h";
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    
    RenderWindow window(VideoMode(800, 600), "Smart Chess", Style::Titlebar | Style::Close);
    Controller Game(&window);
    Game.Start();
    return 0;
}