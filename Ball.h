#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:

	Ball(float radius = 20.0f);

	void updateBall(const sf::RenderWindow& window);

	void setVelo(float vx, float vy);
	sf::Vector2f getVelo();

	void setAccel(float ax, float ay);
	sf::Vector2f getAccel();

private:
	sf::Vector2f velo;
	sf::Vector2f accel;
};

