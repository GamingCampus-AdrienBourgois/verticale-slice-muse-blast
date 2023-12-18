#pragma once
#include "hitbox.h"
#include "bullet.h"
enum PLAYER_ANIMATION_STATES 
{
	IDLE = 0,
	MOVING_LEFT = 1,
	MOVING_RIGHT = 2,
	JUMPING = 3,
	FALLING = 4,
	SHOOTHING = 5,
	GETDAMAGED = 6,
	DEAD = 7,
};


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texturesheet;
	sf::Clock animationtimer;
	sf::Sprite healthbar;
	sf::Texture health;

	//animation

	short animationState;
	sf::IntRect currentFrame;
	bool animationswitch;

	void initAnimation();

	//shooting

	sf::Vector2f mousePosWindow;
	sf::Vector2f playercenter;
	std::vector<Bullet> bullets;
	float shootTimer;
	float shootTimerMax;
	sf::Vector2f bulletDir;


	//physics

	Hitbox* hitbox;


	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float velocityY;
	float gravity;
	float velocityMaxY;
	float jumpVel;

	bool isJumping;
	bool isGrounded;
	float jumpHeight;
	float jumpVelocity;
	bool canDoubleJump;


	//health

	int hp;
	int hpMax;

	//core
	void initHitbox();
	void initVariables();
	void initTexture();
	void initSprite();
	void initphysics();
	void initBullet();

public:
	Player();
	virtual ~Player();
	
	//accessors
	const bool& getAnimationSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const sf::FloatRect getHitbox() const;
	const sf::Vector2f getPlayerCenter() const;
	float getBottom() const;
	const sf::Vector2f getHitboxCenter() const;
	const sf::Vector2f normalize(const sf::Vector2f& vector) const;
	const int& getHp() const;
	const int& getHpMax() const;
	//modifiers


	void setHp(const int hp);
	void loseHp(const int value);
	void setPosition(const float x, const float y);
	void setMousePosWindow(const sf::Vector2f& mousePosWindow);
	void resetVelocityY();
	void resetVelocityX();

	//function

	

	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void shoot();
	void updatePhysics();
	void updateMovement();
	void updateHitbox();
	void updateAnimation();
	void update();
	void renderBullets(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);

};

