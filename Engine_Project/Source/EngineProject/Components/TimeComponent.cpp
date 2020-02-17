#include "TimeComponent.h"

TimeComponent::TimeComponent()
{
	
}

float TimeComponent::getDeltaTime()
{
	sf::Clock clock;
	sf::Time elapsed1 = clock.getElapsedTime();
	dt = elapsed1.asSeconds();
	clock.restart();
	return dt;
}
