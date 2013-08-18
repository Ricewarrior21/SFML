#include "entity.h"

Entity::Entity() {}
Entity::~Entity() {}

void Entity::setTexture(std::string input) {

}

sf::Vector2f Entity::getPosition() {
	return position;
}

void Entity::drawEntity(sf::RenderWindow* window) {
	window->draw(sprite);
}