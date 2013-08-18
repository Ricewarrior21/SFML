#include "tile.h"

Tile::Tile() {}
Tile::~Tile() {}

void Tile::setType(char input) {
	type = input;
}

void Tile::setPosition(sf::Vector2f input) {
	position = input;
}

void Tile::setTilePosition(sf::Vector2i input) {
	tilePosition = input;
}

sf::Vector2f Tile::getPosition() {
	return position;
}

sf::Vector2i Tile::getTilePosition() {
	return tilePosition;
}

char Tile::getTileType() {
	return type;
}