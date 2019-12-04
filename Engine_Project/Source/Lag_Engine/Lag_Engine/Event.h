#ifndef __EVENT_H__
#define __EVENT_H__

enum EventType
{
	MouseClick,
	KeyboardPress
};

class Event
{
public:
	EventType descriptor;
};

#endif