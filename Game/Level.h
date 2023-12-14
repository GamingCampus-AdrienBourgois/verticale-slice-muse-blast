#pragma once
class Level
{
private:

	sf::Sprite sprite1;


	sf::Texture texturesheet;
	sf::Music music;

	void initTexture();
	void initSprite();
	void initMusic();

public:
	Level();
	virtual ~Level();

	void render(sf::RenderTarget& target);
};

