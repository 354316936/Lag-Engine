#include "MouseEvent.h"

MouseEvent::MouseEvent(int _x, int _y, bool _leftClick)
{
	descriptor = EventType::MouseClick;
	x = _x;
	y = _y;
	leftClick = _leftClick;
}

MouseEvent::~MouseEvent()
{
}
