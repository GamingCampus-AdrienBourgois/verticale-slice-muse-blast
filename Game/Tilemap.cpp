#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "Tilemap.h"

Tilemap::Tilemap()
{
	this->tilesheet = NULL;
	this->tilesize = 0;

}

Tilemap::Tilemap(unsigned whidth, unsigned height, sf::Texture* tile_sheet, unsigned tile_size)
{
	this->tilesheet = tile_sheet;
	this->tilesize = tile_size;

	this->tiles.resize(whidth);
	for (int i = 0; i < this->tiles.size(); i++)
	{
		this->tiles[i].resize(height, nullptr);
	}
}

Tilemap::~Tilemap()
{
	for (int i = 0; i < this->tiles.size(); i++)
	{
		for (int k = 0; k < this->tiles.size(); k++)
		{
			delete this->tiles[i][k];
			this->tiles[i][k] = nullptr;
		}
	}

}

void Tilemap::addTile(unsigned x, unsigned y)
{
	if (x < this->tiles.size())
	{
		if (y < this->tiles.size())
		{
			if (this->tiles[x][y] == nullptr)
				this->tiles[x][y] = new Tile(this->tilesheet, sf::IntRect(0, 0, this->tilesize, this->tilesize), false);
		}
	}

}

void Tilemap::removeTile(unsigned x, unsigned y)
{
	if (x < this->tiles.size())
	{
		if (y < this->tiles.size())
		{
			if (this->tiles[x][y] != nullptr)
			{
				delete this->tiles[x][y];
				this->tiles[x][y] = nullptr;
			}

		}
	}
}

void Tilemap::update()
{
	for (int i = 0; i < this->tiles.size(); i++)
	{
		for (int k = 0; k < this->tiles.size(); k++)
		{
			if (this->tiles[i][k] != nullptr)
				this->tiles[i][k]->update();
		}
	}
}

void Tilemap::render(sf::RenderTarget& target)
{
	for (int i = 0; i < this->tiles.size(); i++)
	{
		for (int k = 0; k < this->tiles.size(); k++)
		{
			if (this->tiles[i][k] != nullptr)
				this->tiles[i][k]->render(target);
		}
	}


}
