#ifndef VIDTXT
#define VIDTXT

#include "Video.h"
#include "Text.h"

class videoAndText : public Video, public Text
{
public:
	videoAndText(const Entity *statusCreator, string& text);

	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	virtual void printStatus() const;
};

#endif