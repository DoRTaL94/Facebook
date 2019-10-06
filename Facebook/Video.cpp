#include "Video.h"

Video::Video()
{
	isVidUploaded = false;
	statusCreator = nullptr;
}

Video::Video(const Entity *statusCreator)
{
	this->statusCreator = statusCreator;
	isVidUploaded = true;
}

bool Video::operator==(const Status& other) const
{
	if (typeid(other).name() == typeid(Video).name())
	{
		return true;
	}

	return false;
}

bool Video::operator!=(const Status& other) const
{
	return !(*this == other);
}

void Video::uploadVideo()
{
	isVidUploaded = true;
}

void Video::printStatus() const
{
	Player player;

	player.Play(this);
}

bool Video::isVideoExist() const
{
	return isVidUploaded;
}

Video::~Video()
{

}