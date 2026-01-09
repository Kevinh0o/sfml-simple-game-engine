#include "entity.h"

Entity::Entity(bool isAlive, int id, std::string type)
	: isAlive (isAlive)
	, id	  (id)
	, type	  (type) 
{

};

void Entity::printEntity() const {
	std::cout << "Entity: " << type << " " << id << std::endl;
}

void Entity::remove() {
	isAlive = false;
}