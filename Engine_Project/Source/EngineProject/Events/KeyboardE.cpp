#include "KeyboardE.h"

KeyboardE::KeyboardE(int _keyInt)
{
	Handler = EventType::KeyboardEvent;
	keyInt = _keyInt;
	isChar = false;
}

KeyboardE::KeyboardE(char _keyChar)
{
	Handler = EventType::KeyboardEvent;
	keyChar = _keyChar;
	isChar = true;
}
KeyboardE::KeyboardE()
{
	Handler = EventType::KeyboardEvent;
	
}
