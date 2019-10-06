#include "Status.h"

Status::Status()
{
	char *dateStr;

	time(&currTime);
	dateStr = ctime(&currTime);

	status_date.setDate(dateStr);
}

const Entity* Status::getStatusCreator() const
{
	return statusCreator;
}

time_t Status::getTime() const
{
	return currTime;
}

Date Status::getDate() const
{
	return status_date;
}

Status::~Status()
{
	
}