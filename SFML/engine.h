#ifndef ENGINE_H
#define ENGINE_H

#include "level.h"

#include <SFML/Graphics.hpp>

class Engine {
private:
	sf::RenderWindow* window;

	// Use clock for printing FPS
	// Implement usage of clock for events later?
	sf::Clock clock;

	// Use view to move view ports around and shit
	sf::View view;

	// Tile system stuff
	Level level;

	sf::Sprite player; // Focus sprite for testing radius rendering

	// Engine startup / loop
	bool Init();

	void ProcessInput();
	void Update();
	void RenderFrame();

	void MainLoop();

public:
	Engine();
	~Engine();
	void Go();
};

#endif