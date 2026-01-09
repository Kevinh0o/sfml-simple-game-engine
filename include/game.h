#pragma once

#ifndef GAME_H
#define GAME_H

#include "entityManager.h"
#include "multimedia.h"
#include "input.h"
#include "movement.h"
#include "timer.h"

class Game {
	EntityManager   entityManager;
	s_Multimedia    window;
	c_Input         input;
	s_Movement      movement;
	Timer			timer;
public:
	void run();
};

#endif