#include "components.h"

c_Shape::c_Shape(float radius) {
	sprite.setRadius(radius);
	sprite.setOrigin(radius, radius);
	sprite.setFillColor(sf::Color::Green);
};

c_Ai::c_Ai() {
	movementDiection = Vec2d(
		Random::generateRandomFloatValue(-1.0f, 1.0f),
		Random::generateRandomFloatValue(-1.0f, 1.0f)
	);
};