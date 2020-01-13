#include "ScriptSystem.h"


ScriptSystem::ScriptSystem(vector<Actor*>* _actors)
{
	actors = _actors;
	
}

ScriptSystem::~ScriptSystem()
{

}

void ScriptSystem::Run()
{
	vector<Actor*>::iterator it;
	for (it = actors->begin(); it != actors->end(); it++)
	{
		ActorComponent* ac = (*it)->GetComponent("ScriptComponent");
		if (ac)
		{
			ScriptComponent* sc2 = (ScriptComponent*)ac;
		
			
		}
	}
}