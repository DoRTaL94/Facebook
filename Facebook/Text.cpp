#include "Text.h"

Text::Text()
{
	statusCreator = nullptr;
}

Text::Text(const Entity *statusCreator,	string& text)
{
	this->text = text;
	this->statusCreator = statusCreator;
}

const string& Text::getText() const
{
	return text;
}

void Text::printStatus() const
{
	Viewer viewer;

	viewer.show(this);
}

bool Text::operator==(const Status& other) const
{
	const Text *txt = dynamic_cast<const Text*>(&other);;

	if (txt != nullptr)
	{
		return this->getText() == txt->getText();//strcmp(this->getText(), txt->getText()) == 0;
	}

	return false;
}

bool Text::operator!=(const Status& other) const
{
	return !(*this == other);
}

Text::~Text()
{

}