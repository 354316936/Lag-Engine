#ifndef __KEYBOARDE_H__
#define __KEYBOARDE_H__

#include "../Base/Event.h"

class KeyboardE : public Event
{
public:
	int keyInt;
	char keyChar;
	bool isChar;
	KeyboardE(int _keyInt);
	KeyboardE(char _keyChar);
};

#endif
