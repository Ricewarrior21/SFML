#ifndef LEVEL_H
#define LEVEL_H

#include "tile.h"
#include "tilemanager.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

class Level {
private:
	std::vector<std::vector<char>> levelData;
	std::vector<std::vector<Tile>> tileList;

	std::vector<char> tileTypes;
	std::vector<sf::Texture> textureList;
	std::vector<sf::Sprite> spriteList;
public:
	Level();
	~Level();

	void loadLevel(std::string input);
	void getTileTypes();

	void loadTiles();
	void loadTileList();
	int getTileTypeIndex(char input);

	sf::Sprite getTile(int x, int y);
	void drawTile(int x, int y, sf::RenderWindow* window);
	void drawTileFromPosition(sf::Vector2f position, sf::RenderWindow* window);
	void drawLevel(sf::RenderWindow* window);
	void drawLevelBox(sf::Sprite sprite, int width, sf::RenderWindow* window);
	void drawLevelRadius(sf::Sprite sprite, int radius, sf::RenderWindow* window);

	std::vector<std::vector<char>> getLevelData();
	Tile getTileFromPosition(sf::Vector2f position);
};

#endif