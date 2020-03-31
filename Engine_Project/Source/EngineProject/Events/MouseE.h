#ifndef __MOUSEE_H__
#define __MOUSEE_H__

#include "../Base/Event.h"
#include <string>
using namespace std;
class MouseE : public Event
{
public:
	MouseE();
	MouseE(int _x, int _y, bool _leftClick);

};

#endif