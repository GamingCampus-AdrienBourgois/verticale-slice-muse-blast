#pragma once
#include "hitbox.h"
enum PLAYER_ANIMATION_STATES 
{
	IDLE = 0,
	MOVING_LEFT = 1,
	MOVING_RIGHT = 2,
	JUMPING = 3,
	FALLING = 4
};


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texturesheet;
	sf::Clock animationtimer;

	//animation

	short animationState;
	sf::IntRect currentFrame;
	bool animationswitch;

	void initAnimation();

	//shooting

	sf::Vector2f playercenter;
	sf::Vector2f mousePos;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;


	//physics

	Hitbox* hitbox;


	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;
	float jumpVel;

	bool isjumping = false;
	bool isonground = true;



	//core

	void initVariables();
	void initTexture();
	void initSprite();
	void initphysics();
	void initHitbox();

public:
	Player();
	virtual ~Player();
	
	//accessors
	const bool& getAnimationSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//modifiers

	void setPosition(const float x, const float y);
	void resetVelocityY();
	//hitbox
	
	void createhitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);


	//function


	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void jump(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateHitbox();
	void updateMovement();
	void updateAnimation();
	void update();
	void render(sf::RenderTarget& target);

};

