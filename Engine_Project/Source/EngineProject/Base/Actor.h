#ifndef __BASE_ACTOR_H__
#define __BASE_ACTOR_H__
#include <string>
#include <windows.h>
#include "ActorComponent.h"
#include <vector>
using namespace std;
namespace sf
{
	class Transform;
}
class TransformComponent;

class Actor
{
private:
	vector<ActorComponent*> components;

public:
	Actor();
	~Actor(void);
	void AddComponent(ActorComponent* _component);
	ActorComponent* GetComponent(string componentName);
	void SetTransform(sf::Transform matrix);
	sf::Transform* GetLocalTransform(); 
	sf::Transform* GetWorldTransform(); 
	void SetParent(Actor* m_p);
	void AddChild(Actor* s);
	virtual void Update(float msec);
	TransformComponent* transComp;
	
protected:
	Actor* parent;
	sf::Transform* worldTransform;
	sf::Transform* localTransform;
	vector<Actor*> children;
};

#endif
