#pragma once
class Bullet
{
public:
	
	sf::CircleShape bullet;
	sf::Vector2f currVelocity;
	float maxSpeed;


	Bullet(float radius = 5.f) : currVelocity(0.f, 0.f), maxSpeed(15.f)
	{
		this->bullet.setRadius(radius);
		this->bullet.setFillColor(sf::Color::Blue);
	}
};

