#include "domain/model/base/Entity.h"

Entity::Entity(int id) : id(id)
{

}

bool Entity::operator==(const Entity* rhs)
{
	return id == rhs->id;
}

bool Entity::operator!=(const Entity* rhs)
{
	return !operator==(rhs);
}

int Entity::getId() const
{
	return id;
}
