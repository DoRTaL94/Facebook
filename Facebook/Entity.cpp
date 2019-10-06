#include "Entity.h"

Entity::Entity(string& name)
{
	this->name = name;
}

const vector<Entity*>& Entity::getConnections() const
{
	return Connections;
}

const string& Entity::getName() const
{
	return name;
}

bool Entity::isEntityExist(Entity* other) const
{
	int size;

	size = Connections.size();

	for (int i = 0; i < size; i++)
	{
		if (Connections[i] == other)
			return true;
	}

	return false;
}

void Entity::printStatusArr() const
{
	statusBoard.printAll();
}

const vector<Status*>& Entity::getStatusArr() const
{
	return statusBoard.getStatusArr();
}

Entity::~Entity()
{
	Connections.clear();
}