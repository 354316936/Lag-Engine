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
		ActorComponent* m_ac = (*it)->GetComponent("ScriptComponent");
		if (m_ac)
		{
			ScriptComponent* m_sc = (ScriptComponent*)m_ac;
		
			
		}
	}
}