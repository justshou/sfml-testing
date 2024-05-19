#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "Ball.h"

sf::Color getRandomColor() {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    // Return the random color
    return sf::Color(r, g, b);
}

int main()
{
    srand((int)time(0));

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ball");
    window.setFramerateLimit(60);

    std::vector<Ball> balls;

    /*Ball ball;
    ball.setRadius(20);
    ball.setPosition(rand() % 1280, rand() % 720);
    ball.setAccel(0.0f, 0.1f);*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                Ball newBall;
                newBall.setVelo(-2 + rand() % 4, -2 + rand() % 4);
                newBall.setAccel(-.1 + rand() % 2, -.1 + rand() % 2);
                newBall.setRadius(3 + rand() % 57);
                newBall.setPosition(event.mouseButton.x - newBall.getRadius(), event.mouseButton.y - newBall.getRadius());
                newBall.setAccel(0.0f, 0.1f);
                newBall.setFillColor(getRandomColor());
                balls.push_back(newBall);
            }
        }

        window.clear();

        for (size_t i = 0; i < balls.size(); ++i)
        {
            balls[i].updateBall(window);
            window.draw(balls[i]);
        }

        window.display();
        //sf::Vector2f velocity = ball.getVelo();
        //sf::Vector2f acceleration = ball.getAccel();
        //std::cout << "Velocity: (" << velocity.x << " , " << velocity.y << ")" << std::endl;
        //std::cout << "Acceleration: (" << acceleration.x << " , " << acceleration.y << ")" << std::endl;

    }




    return 0;
}