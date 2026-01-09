#pragma once

#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
public:
	static float generateRandomFloatValue(float min, float max);
	static bool  generateBooleanValue    (float min, float max);
};

#endif