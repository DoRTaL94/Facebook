#include "Date.h"

Date::Date()
{
	
}

Date::Date(int day, int month, int year)
{
	string::iterator itr;

	if (day > 9)
	{
		this->day = to_string(day);
	}
	else
	{
		itr = this->day.begin();
		this->day.insert(itr, '0');
		this->day.insert(++itr, '0' + day);
	}

	if (month > 9)
	{
		this->month = to_string(month);
	}
	else
	{
		itr = this->month.begin();
		this->month.insert(itr, '0');
		this->month.insert(++itr, '0' + month);
	}

	this->year = to_string(year);

	dateStr = this->day;
	dateStr += "/";
	dateStr += this->month;
	dateStr += "/";
	dateStr += this->year;
}

void Date::setDate(string currDate)
//Fri Nov 23 18:37:00 2018
{
	char *buffer, *str;
	char deli = ' ';
	
	str = (char*)currDate.c_str();

	buffer = strtok(str, &deli);
	buffer = strtok(NULL, &deli);
	this->month = buffer;
	buffer = strtok(NULL, &deli);
	this->day = buffer;
	buffer = strtok(NULL, &deli);
	this->timeStr = buffer;
	buffer = strtok(NULL, &deli);
	this->year = buffer;
}

const string& Date::getDate() const
{
	return dateStr;
}

const string& Date::getTime() const
{
	return timeStr;
}