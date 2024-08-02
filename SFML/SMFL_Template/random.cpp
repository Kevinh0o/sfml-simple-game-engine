#include "random.h"

float Random::generateRandomFloatValue(float min, float max) {
    std::random_device rd;
    std::uniform_real_distribution<double> dist(min, max);

    return dist(rd);
}

bool Random::generateBooleanValue(float min, float max) {
	return 0;
}