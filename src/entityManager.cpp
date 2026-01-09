#include "entityManager.h"

Entity_ptr EntityManager::addEntity(std::string type) {
	auto entity = Entity_ptr(new Entity(true, counter, type));
	entitiesToAdd.push_back(entity);
	counter++;
	return entity;
}

EntityVector EntityManager::getEntities() {
	return entities;
}

void EntityManager::printEntities() {
	for (const Entity_ptr e : entities) {
		e->printEntity();
	}
}

void EntityManager::updateEntities() {
	EntityVector::iterator it = std::remove_if(entities.begin(), entities.end(), [](Entity_ptr e) {
		return !e->isAlive;
	});
	entities.erase(it, entities.end());

	for (auto& entity : entitiesToAdd) {
		entities.push_back(entity);
		entitiesMap[entity->type].push_back(entity);
	}
	entitiesToAdd.clear();
}

void EntityManager::addPlayer(float xPos, float yPos) {
	Entity_ptr p = addEntity("player");

	p->shape     = std::make_shared<c_Shape>(30.0f);
	p->transform = std::make_shared<c_Transform>();
	p->input     = std::make_shared<c_Input>();

	p->transform->position = Vec2d(xPos, yPos);
	player = p;
}

Entity_ptr EntityManager::getPlayer() {
	return player;
}

void EntityManager::addEnemy(Vec2d position) {
	Entity_ptr e = addEntity("enemy");

	e->shape     = std::make_shared<c_Shape>(30.0f);
	e->transform = std::make_shared<c_Transform>();
	e->ai        = std::make_shared<c_Ai>();

	e->transform->speed    = 3.0f;
	e->transform->position = position;
}

void EntityManager::enemySpawner(double elapsedTime, float xPos, float yPos) {
	if(elapsedTime - lastSpawnEnemyTime > enemySpawnTime && enemiesSpawned < maxEnemiesSpawned) {
		std::cout << "Enemy spawned\n";

		lastSpawnEnemyTime = elapsedTime;
		enemiesSpawned++;

		Vec2d enemyPos = Vec2d(
			Random::generateRandomFloatValue(0, xPos),
			Random::generateRandomFloatValue(0, yPos)
		);

		while(enemyPos.getDistanceTo(player->transform->position) < player->shape->sprite.getRadius() * 10) {
			enemyPos.x = Random::generateRandomFloatValue(0, xPos);
			enemyPos.y = Random::generateRandomFloatValue(0, xPos);
		}

		addEnemy(enemyPos);
	}
}