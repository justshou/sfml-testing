#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

int main()
{
    srand((int)time(0));

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Moving squares");
    window.setFramerateLimit(60);
    
    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(600, 350);

    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(100, 100));

    float xVelo = 3;
    float yVelo = 3;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        // physics i hate physics

        // moving by hand
        /*if (sf::keyboard::iskeypressed(sf::keyboard::w)) rectangleposition.y -= 1;
        if (sf::keyboard::iskeypressed(sf::keyboard::s)) rectangleposition.y += 1;
        if (sf::keyboard::iskeypressed(sf::keyboard::a)) rectangleposition.x -= 1;
        if (sf::keyboard::iskeypressed(sf::keyboard::d)) rectangleposition.x += 1;*/
        //

        sf::Color randomColor(rand() % 256, rand() % 256, rand() % 256);
        if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 100) // the -100 is from the size of the shape
        {
            xVelo *= -1;
            rect.setFillColor(randomColor);
        }
        if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 100)
        {
                yVelo *= -1;
                rect.setFillColor(randomColor);
        }



        rectanglePosition.x += xVelo;
        rectanglePosition.y += yVelo;
        rect.setPosition(rectanglePosition);

        // draw the screen
        window.clear();
        window.draw(rect);
        window.display();
    }

    
    

    return 0;
}