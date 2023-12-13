#pragma once
class Hitbox
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitboxbound;
	float offsetX;
	float offsetY;


public:
	Hitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);

	//function
	bool checkcollision(const sf::FloatRect& frect);


	void update();
	void render(sf::RenderTarget& target);
};

