#include "Utilities.h"
#include <Windows.h>

void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}

int comparetime(time_t time1, time_t time2)
{
	return difftime(time1, time2) > 0.0 ? 1 : -1;
}