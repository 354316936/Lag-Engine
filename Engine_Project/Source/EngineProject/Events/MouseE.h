#ifndef __MOUSEE_H__
#define __MOUSEE_H__

#include "../Base/Event.h"

class MouseE : public Event
{
public:
	int x;
	int y;
	bool leftClick;
	MouseE(int _x, int _y, bool _leftClick);
};

#endif