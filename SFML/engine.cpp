#include "engine.h"

Engine::Engine() {}
Engine::~Engine() {}

// Check if the engine is running
bool Engine::Init() {
	window = new sf::RenderWindow(sf::VideoMode(800,600,32), "SFML");
	level.loadLevel("level1.txt");

	// Test stuff
	sf::Texture pTexture;
	pTexture.loadFromFile("player.png");
	player.setTexture(pTexture);
	player.setPosition(350,120);

	view.setSize(800,600);
	view.setCenter(player.getPosition());
	window->setView(view);
	if (!window)
		return false;
	return true;
}

// Initial engine startup
void Engine::Go() {
	if(!Init())
		throw "Could not initialize engine!";
	MainLoop();
}

// Handle SFML events
void Engine::ProcessInput() {
	sf::Event event;
	while(window->pollEvent(event)) {
		switch(event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::S) {
				sf::Vector2f pos = player.getPosition();
				pos.y += 10;
				view.move(0,10);
				player.setPosition(pos);
			}
			if (event.key.code == sf::Keyboard::W) {
				sf::Vector2f pos = player.getPosition();
				pos.y -= 10;
				view.move(0,-10);
				player.setPosition(pos);
			}
			if (event.key.code == sf::Keyboard::D) {
				sf::Vector2f pos = player.getPosition();
				view.move(10,0);
				pos.x += 10;
				player.setPosition(pos);
			}
			if (event.key.code == sf::Keyboard::A) {
				sf::Vector2f pos = player.getPosition();
				view.move(-10,0);
				pos.x -= 10;
				player.setPosition(pos);
			}
			break;
		}
	}
}

// Update internal workings
void Engine::Update() {

}

// All rendering will be done here
void Engine::RenderFrame() {
	window->clear();
	// level.drawLevelBox(player, 4, window);
	level.drawLevel(window);
	// view.setCenter(player.getPosition());
	window->setView(view);
	window->draw(player);
	window->display();
}

void Engine::MainLoop() {
	// Loop and shit
	while(window->isOpen()) {
		ProcessInput();
		Update();
		RenderFrame();
	}
}