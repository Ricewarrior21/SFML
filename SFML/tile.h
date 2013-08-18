#ifndef TILE_H
#define TILE_H

#include <string>
#include <SFML/Graphics.hpp>

class Tile {
private:
	sf::Vector2f position; // SFML coordinates
	sf::Vector2i tilePosition; // position on level map
	char type;
public:
	Tile();
	~Tile();

	void setType(char input);
	void setPosition(sf::Vector2f input);
	void setTilePosition(sf::Vector2i input);
	sf::Vector2f getPosition();
	sf::Vector2i getTilePosition();
	char getTileType();
};

#endif