#pragma once
#include "hitbox.h"


class Ground
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//physic

	//Hitbox* hitbox;


	void initHitbox();
	void initTexture();
	void initSprite();
public:
	Ground();
	virtual ~Ground();

	const sf::FloatRect getGlobalBounds() const;
	const sf::FloatRect getHitbox() const;

	void setPosition(const float x, const float y);
	
	void updateHitbox();
	void update();
	void render(sf::RenderTarget& target);
};

