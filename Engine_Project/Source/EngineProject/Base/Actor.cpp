//#include "SFML/Graphics/Transform.hpp"
#include "../Components/TransformComponent.h"
#include "Actor.h"
#include <windows.h>

Actor::Actor()
{
	
	parent = NULL;
	transComp = new TransformComponent();
	worldTransform = new sf::Transform();
	localTransform = &(transComp->transform);
}

Actor::~Actor(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void Actor::AddComponent(ActorComponent* _component)
{
	components.push_back(_component);
}

ActorComponent* Actor::GetComponent(string componentName)
{
	vector<ActorComponent*>::iterator it;
	for (it = components.begin(); it != components.end(); it++)
	{
		if ((*it)->componentID == componentName)
		{
			return *it;
		}
	}
	return NULL;
}

void Actor::SetTransform(sf::Transform matrix)
{
	*localTransform = matrix;
}

sf::Transform * Actor::GetLocalTransform()
{
	return localTransform;
}

sf::Transform * Actor::GetWorldTransform()
{
	return worldTransform;
}

void Actor::SetParent(Actor * m_p)
{
	parent = m_p;
}

void Actor::AddChild(Actor* s)
{
	children.push_back(s);
	s->SetParent(this);
}

void Actor::Update(float msec)
{
	if (parent)
	{
		*worldTransform = *(parent->worldTransform) * *(localTransform);
	}
	else
	{
		worldTransform = localTransform;
	}
}
