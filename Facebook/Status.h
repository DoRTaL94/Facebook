#ifndef STATUS
#define STATUS

class Entity;

#include "Viewer.h"
#include "Player.h"
#include "Date.h"
#include "Color.h"
#include "Utilities.h"
#include <typeinfo>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

class Status
{
protected:
	time_t currTime;
	Date status_date;
	const Entity *statusCreator;

public:
	Status();
	
	time_t getTime() const;
	const Entity *getStatusCreator() const;
	Date getDate() const; 
	virtual void printStatus() const = 0;
	virtual bool operator==(const Status& other) const = 0;
	virtual bool operator!=(const Status& other) const = 0;

	virtual ~Status();
};

#endif
