#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent(int _keyInt)
{
	descriptor = EventType::KeyboardPress;
	keyInt = _keyInt;
	isChar = false;
}

KeyboardEvent::KeyboardEvent(char _keyChar)
{
	descriptor = EventType::KeyboardPress;
	keyChar = _keyChar;
	isChar = true;
}

KeyboardEvent::~KeyboardEvent()
{
}