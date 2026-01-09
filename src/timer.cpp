#include "timer.h"

Timer::Timer() {
    startTimePoint = getCurrentTimeMilli();
}

double Timer::getElapsedTime() {
    return getCurrentTimeMilli() - startTimePoint;
}

double Timer::getCurrentTimeMilli() {
	TimePoint now = std::chrono::high_resolution_clock::now();
    return std::chrono::time_point_cast<std::chrono::milliseconds>(now)
        .time_since_epoch()
        .count();
}