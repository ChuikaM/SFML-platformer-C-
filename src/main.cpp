#include <SFML/Graphics.hpp>
#include <textmaploader.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Platformer 2D");
    TextMapLoader textMapLoader;
    textMapLoader.load("maps/map1.txt");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.draw(textMapLoader);
        window.display();
    }
}