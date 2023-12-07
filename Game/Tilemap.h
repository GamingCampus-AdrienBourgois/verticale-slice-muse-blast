#pragma once
#include "Tile.h"
class Tilemap
{
private:
	std::vector < std::vector <Tile*> > tiles;
	sf::Texture* tilesheet;
	unsigned tilesize;

public:
	Tilemap();
	Tilemap(unsigned whidth, unsigned height, sf::Texture* tile_sheet, unsigned tile_size);
	~Tilemap();


	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);

	void update();
	void render(sf::RenderTarget& target);

};

