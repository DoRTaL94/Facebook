#ifndef DATE
#define DATE

#pragma warning (disable: 4996)

#include "Utilities.h"
#include <iostream>
using namespace std;

class Date
{
private:
	string day, month, year, timeStr, dateStr;

public:
	Date();
	
	Date(int day, int month, int year);
	const string& getDate() const;
	const string& getTime() const;
	void setDate(string currDate);
};

#endif
