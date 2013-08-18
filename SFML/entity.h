#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
private:
	std::vector<std::vector<char>> levelData;

	sf::Vector2f position;
	sf::Vector2f size;

	sf::Sprite sprite;
	sf::Texture texture;
public:
	Entity();
	~Entity();

	void setTexture(std::string input);
	sf::Vector2f getPosition();

	void loadLevelData(std::vector<std::vector<char>> levelData);

	void drawEntity(sf::RenderWindow* window);
};

#endif