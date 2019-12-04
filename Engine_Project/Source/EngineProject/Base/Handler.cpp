#include "Handler.h"

Handler* Handler::instance=0;

Handler::Handler() {}

Handler* Handler::GetInstance()
{
	if (!instance)
		instance = new Handler();
	return instance;
}

void Handler::Subscribe(const EventType handler, SlotType&& slot)
{
	observers[handler].push_back(slot);
}

void Handler::Subscribe(const EventType handler, void(*slot)(const Event& e))
{

	observers2[handler].push_back(slot);
}
void Handler::Post(const Event& event)
{
	EventType type = event.Handler;

	if (observers2.find(type) == observers2.end())
		return;

	auto&& listOfFunctions = observers2.at(type);

	for (auto&& theFunction : listOfFunctions)
		theFunction(event);
}