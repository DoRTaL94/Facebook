#include "videoAndText.h"

videoAndText::videoAndText(const Entity *statusCreator, string& text)
{
	this->statusCreator = statusCreator;
	this->text = text;
	isVidUploaded = true;
}

bool videoAndText::operator==(const Status& other) const
{
	const videoAndText *vat = dynamic_cast<const videoAndText*>(&other);

	if (vat != nullptr)
	{
		return this->getText() == vat->getText();
	}

	return false;
}

bool videoAndText::operator!=(const Status& other) const
{
	return !(*this == other);
}

void videoAndText::printStatus() const
{
	Viewer viewer;
	Player player;

	player.Play(this);
	viewer.show(this);
}