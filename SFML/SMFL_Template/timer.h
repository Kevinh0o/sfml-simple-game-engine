#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

typedef std::chrono::high_resolution_clock::time_point TimePoint;

class Timer {
	double startTimePoint;
public:
	Timer();
	double getElapsedTime();
	double getCurrentTimeMilli();
};

#endif