#ifndef FACEBOOK
#define FACEBOOK

#pragma warning (disable: 4996)

#include "Utilities.h"
#include "Member.h"
#include "FanPage.h"
#include "Viewer.h"
#include <typeinfo.h>

class Facebook
{
private:
	vector<Entity*> Entities;

public:
	Facebook();

	template<class T>
	T* searchEntity(const string& name) const;

	template<class T>
	void printOneKind() const; // printing one kind of entity exists in facebook.

	const vector<Entity*>& getEntitiesArr() const;
	void addMember();
	void addStatus();
	void addFanPage();
	void printStatusArr() const; // printing statuses array of a given member or fan page.
	void createFriendship();
	void addFollower();
	void printEntities() const; // printing every entity exists in facebook.
	void printConnections() const; // printing friends of a given member or printing followers of a given fan page.
	void printLastTen() const; // printing last ten most updated statuses of a given member.
	void comparef() const;
	void compareStatuses() const;

	~Facebook();
};

template<class T>
T* Facebook::searchEntity(const string& name) const
{
	T *temp;
	int size;

	size = Entities.size();

	for (int i = 0; i < size; i++)
	{
		temp = dynamic_cast<T*>(Entities[i]);

		if (temp != nullptr)
		{
			if (temp->getName() == name)
			{
				return temp;
			}
		}
	}

	return nullptr;
}

template<class T>
void Facebook::printOneKind() const
{
	T *temp;
	int counter = 0, size;
	bool isExists = false;
	string type;

	size = Entities.size();

	for (int i = 0; i < size; i++)
	{
		temp = dynamic_cast<T*>(Entities[i]);
		type = typeid(T).name();

		if (temp != nullptr)
		{
			isExists = true;
			
			if (type == typeid(FanPage).name())
			{
				cout << "Fan page";
			}
			else
			{
				cout << "Member";
			}
			cout << " #" << counter + 1 << ": " << temp->getName() << endl;
			counter++;
		}
	}

	if (!isExists)
	{
		cout << "None exists" << endl;
	}
}
#endif