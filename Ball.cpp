#include "Ball.h"

Ball::Ball(float radius) : sf::CircleShape(radius) {
	velo = sf::Vector2f(5.0f, 4.0f);
	accel = sf::Vector2f(0.0f, 0.0f);
}

void Ball::setAccel(float ax, float ay) {
	accel.x = ax;
	accel.y = ay;
}

void Ball::setVelo(float vx, float vy) {
	velo.x = vx;
	velo.y = vy;
}

sf::Vector2f Ball::getAccel() {
	return accel;
}

sf::Vector2f Ball::getVelo() {
	return velo;
}

void Ball::updateBall(const sf::RenderWindow& window) {
    velo += accel;

    move(velo);

    if (getPosition().x - getRadius() < 0) {
        setPosition(getRadius(), getPosition().y);
        velo.x = -velo.x * 0.9f;
    }

    else if (getPosition().x + getRadius() > window.getSize().x) {
        setPosition(window.getSize().x - getRadius(), getPosition().y);
        velo.x = -velo.x * 0.9f;
    }

    if (getPosition().y - getRadius() < 0) {
        setPosition(getPosition().x, getRadius());
        velo.y = -velo.y * 0.9f;
    }

    else if (getPosition().y + getRadius() > window.getSize().y) {
        setPosition(getPosition().x, window.getSize().y - getRadius());
        velo.y = -velo.y * 0.9f;
    }
}