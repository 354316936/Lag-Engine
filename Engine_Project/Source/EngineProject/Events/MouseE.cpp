#include "MouseE.h"

MouseE::MouseE(int _x, int _y, bool _leftClick)
{
	Handler = EventType::MouseEvent;
	x = _x;
	y = _y;
	leftClick = _leftClick;
}

