#include <SFML/Window.hpp>

int main()
{
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "My window");
    return 0;
}