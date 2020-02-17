#include "ScriptSystem.h"


ScriptSystem::ScriptSystem(vector<Actor*>* _actors)
{
	actors = _actors;
	lua = LuaState::Create();

}

ScriptSystem::~ScriptSystem()
{

}

void ScriptSystem::Run()
{
	int counter = 0;
	vector<Actor*>::iterator it;
	for (it = actors->begin(); it != actors->end(); it++)
	{
		ActorComponent* m_ac = (*it)->GetComponent("ScriptComponent");
		if (m_ac)
		{
			ScriptComponent* m_sc = (ScriptComponent*)m_ac;
			lua->DoFile(m_sc->GetPath().c_str());
			LuaObject table = lua->GetGlobals().GetByName("myItems");
			for (LuaTableIterator it(table); it; it.Next())
			{
				
				LuaObject key = it.GetKey();
				LuaObject value = it.GetValue();
				
				GameEngine::GetInstance()->Print(value.GetString());
				myInt = value.GetInteger();
				counter++;

			}
			
		}
	}
}