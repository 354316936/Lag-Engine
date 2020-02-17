#include "Handler.h"

Handler* Handler::instance = 0;

Handler::Handler() {}

Handler* Handler::GetInstance()
{
	if (!instance)
		instance = new Handler();
	return instance;
}

void Handler::Subscribe(const EventType descriptor, void(*slot)(const Event& e))
{

	observers[descriptor].push_back(slot);
}

void Handler::Post(const Event& event)
{
	EventType type = event.Handler;
	if (observers.find(type) == observers.end())
		return;
	auto&& listOfFunctions = observers.at(type);
	for (auto&& theFunction : listOfFunctions)
		theFunction(event);
}