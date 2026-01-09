#include "multimedia.h"
#include <iostream>

s_Multimedia::s_Multimedia()
    : window(sf::VideoMode(windowWidth, windowHeight), "Game")
	, event()
{
    
}

void s_Multimedia::renderEntities(EntityVector entities) {
	for (Entity_ptr e : entities) {
		if (e->shape == nullptr || e->transform == nullptr)
			continue;

		e->shape->sprite.setPosition(e->transform->position.x, e->transform->position.y);
		window.draw(e->shape->sprite);
	}
}

void s_Multimedia::renderWindow(std::function<void()> fun) {
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		processEvents();

		window.clear();
		fun();
		window.display();
	}
}

void s_Multimedia::processEvents() {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == 22)
				input.up = false;

			if (event.key.code == 0)
				input.left = false;

			if (event.key.code == 18)
				input.down = false;

			if (event.key.code == 3)
				input.right = false;
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == 22)
				input.up = true;

			if (event.key.code == 0)
				input.left = true;

			if (event.key.code == 18)
				input.down = true;

			if (event.key.code == 3)
				input.right = true;
		}
	}
}