#include "level.h"

Level::Level() {}
Level::~Level() {}

void Level::loadLevel(std::string input) {
	std::cout << "Loading level..." << std::endl;
	std::fstream file;
	std::string line;

	// Read file
	file.open("level1.txt");
	if (file.is_open()) {
		std::cout << "File opened properly" << std::endl;
		while (file.good()) {
			getline(file, line);
			std::vector<char> charVector;
			for (unsigned int i = 0; i < line.length(); i++) {
				if (line[i] != ',')
					charVector.push_back(line[i]);
			}
			levelData.push_back(charVector);
		}
	} else {
		std::cout << "Unable to open the file" << std::endl;
	}

	for (unsigned int i = 0; i < levelData.size(); i++) {
		for (unsigned int j = 0; j < levelData[i].size(); j++) {
			std::cout << levelData[i][j];
		}
		std::cout << std::endl;
	}

	file.close();
	getTileTypes();
	loadTiles();
	loadTileList();
}

// Loading unique textures into a list
void Level::getTileTypes() {
	for (unsigned int i = 0; i < levelData.size(); i++) {
		for (unsigned int j = 0; j < levelData[i].size(); j++) {
			if (std::find(tileTypes.begin(), tileTypes.end(), ' ') == tileTypes.end()) {
				tileTypes.push_back(levelData[i][j]);
			} else if (std::find(tileTypes.begin(), tileTypes.end(), '0') == tileTypes.end()) {
				tileTypes.push_back(levelData[i][j]);
			} else if (std::find(tileTypes.begin(), tileTypes.end(), '1') == tileTypes.end()) {
				tileTypes.push_back(levelData[i][j]);
			}
		}
	}
}

void Level::loadTileList() {
	Tile tile;
	sf::Vector2f position;
	sf::Vector2i tilePosition;
	sf::Vector2f size;
	for (unsigned int i = 0, x = 0; i < levelData.size(); i++, x += 64) {
		std::vector<Tile> tileVector;
		for (unsigned int j = 0, y = 0; j < levelData[i].size(); j++, y += 64) {
			if (levelData[i][j] == ' ') {
				position.x = (float)y;
				position.y = (float)x;
				tile.setPosition(position);
				tile.setType(' ');
				tilePosition.x = j;
				tilePosition.y = i;
				tile.setTilePosition(tilePosition);
				tileVector.push_back(tile);
			} else if (levelData[i][j] == '0') {
				position.x = (float)y;
				position.y = (float)x;
				tile.setPosition(position);
				tile.setType('0');
				tilePosition.x = j;
				tilePosition.y = i;
				tile.setTilePosition(tilePosition);
				tileVector.push_back(tile);
			} else if (levelData[i][j] == '1') {
				position.x = (float)y;
				position.y = (float)x;
				tile.setPosition(position);
				tile.setType('1');
				tilePosition.x = j;
				tilePosition.y = i;
				tile.setTilePosition(tilePosition);
				tileVector.push_back(tile);
			}
		}
		tileList.push_back(tileVector);
	}
}

void Level::loadTiles() {

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
			spriteList.push_back(*sprite);
		} else if (tileTypes[i] == '0') {
			sprite->setTexture(textureList[getTileTypeIndex('0')]);
			spriteList.push_back(*sprite);
		} else if (tileTypes[i] == '1') {
			sprite->setTexture(textureList[getTileTypeIndex('1')]);
			spriteList.push_back(*sprite);
		}
	}
}

int Level::getTileTypeIndex(char input) {
	for (unsigned int i = 0; i < tileTypes.size(); i++) {
		if (tileTypes[i] == input) {
			return i;
		}
	}
	return 0;
}

void Level::drawTile(int x, int y, sf::RenderWindow* window) {
	if (((x >= 0) && (x < levelData.size())) && ((y >= 0) && (y < (levelData[x].size())))) {
		sf::Sprite sprite = spriteList[getTileTypeIndex(levelData[x][y])];
		sprite.setPosition(tileList[x][y].getPosition());
		window->draw(sprite);
	}
}

void Level::drawTileFromPosition(sf::Vector2f position, sf::RenderWindow* window) {
	Tile tile = getTileFromPosition(position);
	sf::Sprite sprite = spriteList[getTileTypeIndex(levelData[(int)tile.getTilePosition().x][(int)tile.getTilePosition().y])];
	sprite.setPosition(tileList[tile.getTilePosition().x][tile.getTilePosition().y].getPosition());
	window->draw(sprite);
}

void Level::drawLevel(sf::RenderWindow* window) {
	for(unsigned int i = 0; i < levelData.size(); i++) {
		for(unsigned int j = 0; j < levelData[i].size(); j++) {
			drawTile(i,j,window);
		}
	}
}

// Draw box around sprite
void Level::drawLevelBox(sf::Sprite sprite, int width, sf::RenderWindow* window) {
	int y = (int)(sprite.getPosition().x + 64) / 64;
	int x = (int)(sprite.getPosition().y + 64) / 64;
	
	int startX = (x - (width / 2));
	int startY = (y - (width / 2));
	int endX = (x + (width / 2));
	int endY = (y + (width / 2));

	for (int i = startX; i < endX; i++) {
		for(int j = startY; j < endY; j++) {
			drawTile(i,j,window);
		}
	}
}

// Work on later cause I'm retarded
void Level::drawLevelRadius(sf::Sprite sprite, int radius, sf::RenderWindow* window) {
	Tile tile = getTileFromPosition(sprite.getPosition());
	
	for (int i = (radius / 2), y = 0; i < radius; i++, y++) {
		drawTile(tile.getTilePosition().x + y, tile.getTilePosition().y, window);
	}

	for (int i = (radius / 2) + 1, y = 0; i < radius; i++, y++) {
		drawTile(tile.getTilePosition().x + y, tile.getTilePosition().y + 1, window);
	}
}

Tile Level::getTileFromPosition(sf::Vector2f position) {
	int x = (int)(position.x / 64.f);
	int y = (int)(position.y / 64.f);
	return tileList[x][y];
}