#include "tilemanager.h"

TileManager::TileManager() {}
TileManager::~TileManager() {}

void TileManager::loadTileTypes(std::vector<char> tileTypes) {
	this->tileTypes = tileTypes;
}

void TileManager::loadTiles() {

	for (unsigned int i = 0; i < tileTypes.size(); i++) {
		sf::Texture* texture = new sf::Texture();
		if (tileTypes[i] == ' ') {
			texture->loadFromFile("whitespace.png");
			textureList.push_back(*texture);
		} else if (tileTypes[i] == '0') {
			texture->loadFromFile("ground.png");
			textureList.push_back(*texture);
		} else if (tileTypes[i] == '1') {
			texture->loadFromFile("water.png");
			textureList.push_back(*texture);
		}
	}

	for (unsigned int i = 0; i < tileTypes.size(); i++) {
		sf::Sprite* sprite = new sf::Sprite();
		if (tileTypes[i] == ' ') {
			sprite->setTexture(textureList[getTileTypeIndex(' ')]);
		} else if (tileTypes[i] == '0') {
			sprite->setTexture(textureList[getTileTypeIndex('0')]);
		} else if (tileTypes[i] == '1') {
			sprite->setTexture(textureList[getTileTypeIndex('1')]);
		}
	}
}

int TileManager::getTileTypeIndex(char input) {
	for (unsigned int i = 0; i < tileTypes.size(); i++) {
		if (tileTypes[i] == input) {
			return i;
		}
	}
	return 0;
}

sf::Texture TileManager::getTexture(char input) {
	return textureList[getTileTypeIndex(input)];
}

sf::Texture TileManager::getTexture(int input) {
	return textureList[input];
}


sf::Sprite TileManager::getSprite(char input) {
	return spriteList[getTileTypeIndex(input)];
}
