#include "domain/model/base/Entity.h"

Entity::Entity(const std::string& id) : id(id)
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

std::string Entity::getId() const
{
	return id;
}
