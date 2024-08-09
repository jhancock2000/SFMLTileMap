#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Main.h"
using namespace sf;
using namespace std;



int main()
{
    const int WIDTH = 1080;
    const int HEIGHT = 1080;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TileMap");

    Vector2f mapSize = { 10, 10 };

    const int tilesize = min(WIDTH / mapSize.x, HEIGHT / mapSize.y);


    int tilemap[10][10] = {
        { 1, 0, 0, 1, 1, 0, 0, 0, 1, 1 },
        { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 0, 1, 0, 1, 1, 0 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 0, 1, 0, 0, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 1, 1, 0 }
    };

    Vector2f playerPos = { 0, 0 };
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color::Red);
        for (size_t i = 0; i < mapSize.x; i++)
        {
            for (size_t j = 0; j < mapSize.y; j++)
            {
                RectangleShape tile(Vector2f(tilesize, tilesize));
                tile.setPosition(j * tilesize, i * tilesize);

                if (tilemap[i][j] == 0) {
                    tile.setFillColor(Color::Blue);
                }
                else {
                    tile.setFillColor(Color::Black);
                }

                if (playerPos.x == i && playerPos.y == j) {
                    tile.setFillColor(Color::Green);

                }

                tile.setOutlineColor(Color::White);
                tile.setOutlineThickness(2);

                window.draw(tile);
            }
        }
        window.display();
    }

    return 0;
}
