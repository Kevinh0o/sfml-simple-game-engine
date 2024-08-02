#pragma once

#ifndef MULTIMEDIA_SYSTEM_H
#define MULTIMEDIA_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include "entityManager.h"
#include "input.h"

class s_Multimedia {
public:
	int windowWidth = 1280;
	int windowHeight = 720;

	sf::RenderWindow window;
	sf::Event        event;
	c_Input          input;
	s_Multimedia();

	void renderEntities     (EntityVector entities);
	void renderWindow	    (std::function<void()>);
	void processEvents      ();
};

#endif