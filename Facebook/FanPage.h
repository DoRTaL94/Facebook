#ifndef  FANPAGE
#define FANPAGE

#pragma warning (disable: 4996)
#include "Board.h"
#include "Member.h"
#include "Entity.h"

class FanPage : public Entity
{
private:
	int followerCounter;
public:
	FanPage(string& name);

	virtual void printConnections() const;
	virtual void addConnection(Entity *other);
	void addStatus(string& text, bool isImg = false, bool isVideo = false);
	int getFC() const;
	void operator+=(Entity& other);
	int operator>(const Entity& other) const;
	int getFollowerCounter() const;

	~FanPage();
};

#endif
