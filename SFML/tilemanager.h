#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "tile.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class TileManager {
private:
	std::vector<char> tileTypes;
	std::vector<sf::Texture> textureList;
	std::vector<sf::Sprite> spriteList;
public:
	TileManager();
	~TileManager();

	void loadTileTypes(std::vector<char> tileTypes);

	void loadTiles();
	int getTileTypeIndex(char input);

	sf::Texture getTexture(char input);
	sf::Texture getTexture(int input);
	sf::Sprite getSprite(char input);
};

#endif