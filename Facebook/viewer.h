#ifndef VIEWER
#define VIEWER

#pragma warning (disable: 4996)

#include "Utilities.h"
#include "Color.h"
#include <typeinfo.h>
class Status;

class Viewer
{
public:
	void show(const Status* status) const;
};

#endif
