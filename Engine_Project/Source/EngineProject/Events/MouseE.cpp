#include "MouseE.h"

MouseE::MouseE()
{
	Handler = EventType::MouseEvent;
	
}
MouseE::MouseE(int _x, int _y, bool _leftClick)
{
	Handler = EventType::MouseEvent;
	/*x = _x;
	y = _y;
	leftClick = _leftClick;*/
}

