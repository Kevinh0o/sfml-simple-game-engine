#pragma once

#ifndef VEC2D_H
#define VEC2D_H

#include <cmath>

class Vec2d {
public:
	float x = 0;
	float y = 0;

	Vec2d();
	Vec2d(float x, float y);

	float getDistanceTo(const Vec2d& other) const;

	Vec2d& operator+=(const Vec2d& rhs);
	Vec2d  operator*(float scalar);
};

#endif