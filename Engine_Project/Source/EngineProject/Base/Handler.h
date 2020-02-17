#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "Event.h"
#include <functional>
#include <map>
#include <vector>

class Handler
{
public:
	void Subscribe(const EventType descriptor, void(*slot)(const Event& e));
	void Post(const Event& event);
	static Handler* GetInstance();

private:
	std::map<EventType, std::vector<void(*)(const Event&)>> observers;
	static Handler* instance;
	Handler();
};

#endif
