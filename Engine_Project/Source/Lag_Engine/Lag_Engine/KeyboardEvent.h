#ifndef __KEYBOARD_EVENT_H__
#define __KEYBOARD_EVENT_H__

#include "Event.h"

class KeyboardEvent : public Event
{
public:
	int keyInt;
	char keyChar;
	bool isChar;
	KeyboardEvent(int _keyInt);
	KeyboardEvent(char _keyChar);
	~KeyboardEvent();
};

#endif
