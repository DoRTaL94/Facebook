#ifndef MEMBER
#define MEMBER

#pragma warning (disable: 4996)

#include "Board.h"
#include "Status.h"
#include "Date.h"
#include "Entity.h"
#include <algorithm>
#include <iostream>
using namespace std;

class FanPage;

class Member : public Entity
{
private:
	Date *bDay;
	int friendsCounter;
	vector<Status*> lastTen;

public:
	Member(string& name, Date* bDay);

	virtual void printConnections() const;
	virtual void addConnection(Entity* other);
	void addStatus(string& text, bool isImg = false, bool isVideo = false);
	int getFC() const;
	vector<Status*>& getLastTenArr();
	void updateLastTen(vector<Status*> otherStatusArr);
	void printLastTen() const;
	void addStatusToAllLt(Status *status); // adds a given status to every lastTen array of this member's friends.
	virtual void operator+=(Entity& other);
	virtual int operator>(const Entity& other) const;
	int operator>(const FanPage& other) const;
	int getFriendsCounter() const;

	~Member();
};

#endif
