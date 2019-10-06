#ifndef TEXT
#define TEXT

#pragma warning (disable: 4996)
#include "Status.h"

class Text : virtual public Status
{
protected:
	string text;

public:
	Text();
	Text(const Entity *statusCreator, string& text);
	
	virtual void printStatus() const;
	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	const string& getText() const;
	
	virtual ~Text();
};

#endif