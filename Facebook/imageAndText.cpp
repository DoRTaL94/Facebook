#include "imageAndText.h"

imageAndText::imageAndText(const Entity *statusCreator, string& text)
{
	this->statusCreator = statusCreator;
	this->text = text;
	isImgUploaded = true;
}

bool imageAndText::operator==(const Status& other) const
{
	const imageAndText *iat = dynamic_cast<const imageAndText*>(&other);

	if (iat != nullptr)
	{
		return this->getText() == iat->getText();
	}

	return false;
}

bool imageAndText::operator!=(const Status& other) const
{
	return !(*this == other);
}

void imageAndText::printStatus() const
{
	Viewer viewer;

	viewer.show(this);
}