#include "Board.h"

Board::Board()
{

}

const vector<Status*>& Board::getStatusArr() const
{
	return statusArr;
}

Status* Board::createStatus(const Entity *statusCreator, string& text, bool isImg, bool isVideo)
{
	if (!text.empty())
	{
		if (isImg)
		{
			imageAndText *iat = new imageAndText(statusCreator, text);
			statusArr.push_back(iat);
		}
		else if (isVideo)
		{
			videoAndText *vat = new videoAndText(statusCreator, text);
			statusArr.push_back(vat);
		}
		else
		{
			Text *txt = new Text(statusCreator, text);
			statusArr.push_back(txt);
		}
	}
	else if (isImg)
	{
		Image *img = new Image(statusCreator);
		statusArr.push_back(img);
	}
	else if (isVideo)
	{
		Video *vid = new Video(statusCreator);
		statusArr.push_back(vid);
	}

	return *(--statusArr.end());
}

void Board::printAll() const
{
	int size;
	Viewer viewer;
	Player player;

	size = statusArr.size();

	if (size == 0)
	{
		setTextColor(RED);
		cout << "There is no status to print." << endl;
		setTextColor(LIGHTGREY);
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Status #" << size - i << ": ";
		player.Play(statusArr[size - i - 1]);
		viewer.show(statusArr[size - i - 1]);
		cout << endl;
	}
}

Board::~Board()
{
	for (vector<Status*>::iterator it = statusArr.begin(); it != statusArr.end(); it++)
	{
		delete *it;
	}

	statusArr.clear();
}