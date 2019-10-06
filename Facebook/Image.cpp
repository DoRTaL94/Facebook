#include "Image.h"

Image::Image()
{
	isImgUploaded = false;
	statusCreator = nullptr;
}

Image::Image(const Entity *statusCreator)
{
	this->statusCreator = statusCreator;
	isImgUploaded = true;
}

bool Image::operator==(const Status& other) const
{
	const Image *temp = dynamic_cast<const Image*>(&other);

	if (temp != nullptr)
	{
		return true;
	}

	return false;
}

bool Image::operator!=(const Status& other) const
{
	return !(*this == other);
}



void Image::uploadImage()
{
	isImgUploaded = true;
}

void Image::printStatus() const
{
	Viewer viewer;

	viewer.show(this);
}

bool Image::isImgExist() const
{
	return isImgUploaded;
}

Image::~Image()
{

}