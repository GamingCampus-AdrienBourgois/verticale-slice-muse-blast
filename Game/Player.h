#pragma once
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texturesheet;

	//animation
	sf::IntRect currentFrame;

	//movement



	//physics

	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;



	//core


	void initTexture();
	void initSprite();
	void initphysics();

public:
	Player();
	virtual ~Player();
	
	//accessors
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//modifiers

	void setPosition(const float x, const float y);
	void resetVelocityY();

	//function

	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);

};

