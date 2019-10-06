#ifndef ENTITY
#define ENTITY

#include "Board.h"

class Entity
{
protected:
	string name;
	vector<Entity*> Connections;
	Board statusBoard;

public:
	Entity(string& name);

	virtual void addConnection(Entity* other) = 0;
	virtual void addStatus(string& text, bool isImg = false, bool isVideo = false) = 0;
	virtual void printConnections() const = 0;
	const vector<Entity*>& getConnections() const;
	const string& getName() const;
	virtual bool isEntityExist(Entity* other) const;
	void printStatusArr() const;
	const vector<Status*>& getStatusArr() const;
	virtual void operator+=(Entity& other) = 0;
	virtual int operator>(const Entity& other) const = 0;

	virtual ~Entity();
};

#endif