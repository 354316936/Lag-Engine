#ifndef __EVENT_H__
#define __EVENT_H__

enum EventType
{
	MouseEvent,
	KeyboardEvent,
	PLUS
};

class Event
{
public:
	EventType Handler;
};

#endif