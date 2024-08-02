#include "vec2d.h"

Vec2d::Vec2d()
	: x(0), y(0)
{}

Vec2d::Vec2d(float x, float y)
	: x(x), y(y)
{}

Vec2d& Vec2d::operator+=(const Vec2d& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vec2d Vec2d::operator*(float scalar) {
	return Vec2d(x * scalar, y * scalar);
}

float Vec2d::getDistanceTo(const Vec2d& other) const {
	// sqrt(difx^2 + dify^2)
	float dx = x - other.x;
	float dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}