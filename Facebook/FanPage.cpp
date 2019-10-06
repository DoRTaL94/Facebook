#include "FanPage.h"


void FanPage::addStatus(string& text, bool isImg, bool isVideo)
{
	statusBoard.createStatus(this, text, isImg, isVideo);
}

FanPage::FanPage(string& name) : Entity(name)
{
	followerCounter = 0;
}

int FanPage::getFC() const
{
	return followerCounter;
}

void FanPage::operator+=(Entity& other)
{
	this->addConnection(&other);
}

int FanPage::operator>(const Entity& other) const
{
	int otherC;
	const FanPage* temp = dynamic_cast<const FanPage*>(&other);

	otherC = temp->getFollowerCounter();

	if (this->getFollowerCounter() > otherC)
	{
		return 1;
	}
	else if (this->getFollowerCounter() < otherC)
	{
		return -1;
	}

	return 0;
}

int FanPage::getFollowerCounter() const
{
	return followerCounter;
}

void FanPage::addConnection(Entity *other)
{
	if (!isEntityExist(other))
	{
		Connections.push_back(other);
		followerCounter++;
		other->addConnection(this);
	}
}

void FanPage::printConnections() const
{
	Member *temp;
	int size;
	
	size = Connections.size();

	for (int i = 0; i < size; i++)
	{
		temp = dynamic_cast<Member*>(Connections[i]);

		if (temp != nullptr)
		{
			cout << "Follower #" << i + 1 << ": " << temp->getName() << endl;
		}
	}
}

FanPage::~FanPage()
{
}