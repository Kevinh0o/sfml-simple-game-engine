#pragma once

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "entity.h"
#include "random.h"
#include "components.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::shared_ptr<Entity> Entity_ptr;

class EntityManager {
	int				 counter		       = 1;
	EntityVector	 entitiesToAdd;
	EntityVector	 entities;
	Entity_ptr		 player;

	//Enemy Spawner
	double			 lastSpawnEnemyTime    = 0;
	double			 enemySpawnTime        = 1000; // 3 seconds
	int			     enemiesSpawned		   = 0;
	int			     maxEnemiesSpawned     = 300;

	std::map<std::string, EntityVector> entitiesMap;
public:
	void		 printEntities ();
	void		 updateEntities();
	void         enemySpawner  (double elapsedTime, float xPos, float yPos);
	void		 addPlayer	   (float xPos, float yPos);
	void		 addEnemy      (Vec2d pos);
	EntityVector getEntities   ();
	Entity_ptr	 getPlayer	   ();
	Entity_ptr	 addEntity	   (std::string type);
};

#endif