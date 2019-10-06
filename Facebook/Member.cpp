#include "Member.h"
#include "FanPage.h"

Member::Member(string& name, Date* bDay) : Entity(name)
{
	friendsCounter = 0;
	this->bDay = bDay;
}

void Member::printConnections() const
{
	Member *temp;
	int size;

	size = Connections.size();

	for (int i = 0; i < size; i++)
	{
		temp = dynamic_cast<Member*>(Connections[i]);

		if (temp != nullptr)
		{
			cout << "Friend #" << i + 1 << ": " << temp->getName() << endl;
		}
	}
}

int Member::getFC() const
{
	return friendsCounter;
}

void Member::addConnection(Entity* other)
{
	Member *temp = dynamic_cast<Member*>(other);

	if (!isEntityExist(other))
	{
		Connections.push_back(other);

		if (temp != nullptr)
		{
			friendsCounter++;
			updateLastTen(other->getStatusArr());
		}

		other->addConnection(this);
	}
}

void Member::operator+=(Entity& other)
{
	this->addConnection(&other);
}

int Member::getFriendsCounter() const
{
	return friendsCounter;
}

int Member::operator>(const Entity& other) const
{
	int otherC;
	const Member* temp = dynamic_cast<const Member*>(&other);

	otherC = temp->getFriendsCounter();

	if (this->getFriendsCounter() > otherC)
	{
		return 1;
	}
	else if (this->getFriendsCounter() < otherC)
	{
		return -1;
	}

	return 0;
}

int Member::operator>(const FanPage& other) const
{
	int otherC;
	const FanPage* temp = dynamic_cast<const FanPage*>(&other);

	otherC = temp->getFollowerCounter();

	if (this->getFriendsCounter() > otherC)
	{
		return 1;
	}
	else if (this->getFriendsCounter() < otherC)
	{
		return -1;
	}

	return 0;
}

void Member::printLastTen() const
{
	int ltSize;

	ltSize = lastTen.size();

	for (int i = 0; i < ltSize; i++)
	{
		cout << ltSize - i << ") " << (lastTen[i]->getStatusCreator())->getName() << " status: ";
		lastTen[i]->printStatus();
		cout << endl;
	}

	if (ltSize == 0)
	{
		setTextColor(RED);
		cout << this->getName() << "'s friends have no Statuses." << endl;
		setTextColor(LIGHTGREY);
	}
}

vector<Status*>& Member::getLastTenArr()
{
	return lastTen;
}

void Member::addStatusToAllLt(Status *status)
{
	Member *temp;
	vector<Status*>* currLt;
	int cSize;

	cSize = Connections.size();

	for (int i = 0; i < cSize; i++)
	{
		temp = dynamic_cast<Member*>(Connections[i]);

		if (temp != nullptr)
		{
			currLt = &temp->getLastTenArr();

			(*currLt).insert((*currLt).begin(), status);
			if ((*currLt).size() > 10)
			{
				(*currLt).erase(--(*currLt).end());
			}
		}
	}
}

void Member::addStatus(string& text, bool isImg, bool isVideo)
{
	addStatusToAllLt(statusBoard.createStatus(this, text, isImg, isVideo));
}

void Member::updateLastTen(vector<Status*> otherStatusArr)
{
	vector<Status*>::iterator otherItr, currItr, otherItrEnd, currItrEnd;
	bool stopLoop;
	int counter;

	otherItr = otherStatusArr.begin();
	otherItrEnd = otherStatusArr.end();
	stopLoop = false;
	counter = 0;

	for (; otherItr != otherItrEnd; ++otherItr)
	{
		currItr = lastTen.begin();
		currItrEnd = lastTen.end();

		for (; currItr != currItrEnd && !stopLoop; ++currItr, ++counter)
		{
			if (comparetime((*currItr)->getTime(), (*otherItr)->getTime()) < 0)
			{
				lastTen.insert(currItr, *otherItr);

				if (counter == 9 || lastTen.size() > 10)
				{
					lastTen.erase(--lastTen.end());
				}

				stopLoop = true;
				currItr = lastTen.begin();
				currItrEnd = lastTen.end();
			}
		}

		if (stopLoop == false && counter < 10)
		{
			lastTen.push_back(*otherItr);
		}

		stopLoop = false;
		counter = 0;
	}
}

Member::~Member()
{
	delete bDay;
}