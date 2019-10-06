#ifndef PLAYER
#define PLAYER

#pragma warning (disable: 4996)

class Status;
#include "Utilities.h"
#include "Color.h"

class Player
{
public:
	void Play(const Status* status) const;
};

#endif
