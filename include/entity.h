#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

#include "components.h"
#include "transform.h"
#include "input.h"

class Entity {
	friend class EntityManager;

	int		    id;
	bool		isAlive;
	std::string type;

	Entity(bool isAlive, int id, std::string type);
public:
	std::shared_ptr<c_Shape>     shape     = nullptr;
	std::shared_ptr<c_Transform> transform = nullptr;
	std::shared_ptr<c_Input>	 input     = nullptr;
	std::shared_ptr<c_Ai>	     ai        = nullptr;

	void printEntity() const;
	void remove();
};

#endif