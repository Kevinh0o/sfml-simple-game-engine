#pragma once

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SFML/Graphics.hpp>
#include "vec2d.h"
#include "random.h"

class c_Shape {
public:
    sf::CircleShape sprite;
    c_Shape(float radius);
};

class c_Ai {
public:
    Vec2d movementDiection;
    c_Ai();
};

#endif