#ifndef BOARD
#define BOARD

#pragma warning (disable: 4996)
#include "imageAndText.h"
#include "videoAndText.h"

class Board
{
private:
	vector<Status*> statusArr;
	
public:
	Board();

	Status* createStatus(const Entity *statusCreator, string& text, bool isImg, bool isVideo);
	void printAll() const; // Printing all statuses in status arr.
	const vector<Status*>& getStatusArr() const;

	~Board();
};

#endif