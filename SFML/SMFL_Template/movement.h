#pragma once

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "input.h"
#include "entityManager.h"

class s_Movement {
public:
	void processEntitiesMovement(EntityVector entities);
	void processInputMovement(Entity_ptr entity);
	void processAiMovement(Entity_ptr entity);
	void doMovement(Entity_ptr& entity);
};

#endif