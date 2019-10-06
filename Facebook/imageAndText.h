#ifndef IMGTXT
#define IMGTXT

#include "Image.h"
#include "Text.h"

class imageAndText : public Image, public Text
{
public:
	imageAndText(const Entity *statusCreator, string& text);

	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	virtual void printStatus() const;
};

#endif