#include "movement.h"

void s_Movement::processEntitiesMovement(EntityVector entities) {
	for (Entity_ptr e : entities) {
		if (e->transform == nullptr)
			continue;
		if (e->input)
			processInputMovement(e);
		if (e->ai)
			processAiMovement(e);

		doMovement(e);
	}
}

void s_Movement::processInputMovement(Entity_ptr entity) {
	if(entity->input->up) {
		entity->transform->velocity.y = entity->transform->speed * -1;
	}
	if (entity->input->left) {
		entity->transform->velocity.x = entity->transform->speed * -1;
	}
	if (entity->input->down) {
		entity->transform->velocity.y = entity->transform->speed * 1;
	}
	if (entity->input->right) {
		entity->transform->velocity.x = entity->transform->speed * 1;
	}
}

void s_Movement::processAiMovement(Entity_ptr entity) {
	entity->transform->velocity = entity->ai->movementDiection * entity->transform->speed;
}

void s_Movement::doMovement(Entity_ptr& entity) {
	entity->transform->position += entity->transform->velocity;
	entity->transform->velocity = Vec2d(0, 0);
}