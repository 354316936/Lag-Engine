#ifndef __MOUSE_EVENT_H__
#define __MOUSE_EVENT_H__

#include "../Lag_Engine/Event.h"

class MouseEvent : public Event
{
public:
	int x;
	int y;
	bool leftClick;
	MouseEvent(int _x, int _y, bool _leftClick);
	~MouseEvent();
};

#endif