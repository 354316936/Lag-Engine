
#include <vector>
#include "../Base/Actor.h"
#include "../Components/ScriptComponent/ScriptComponent.h"
#include "../GameEngine.h"
#include "LuaPlus.h"
using namespace LuaPlus;

class ScriptSystem
{
public:
	ScriptSystem(vector<Actor*>* _actors);
	~ScriptSystem();
	void Run();
	int myInt = 0 ;
private:
	vector<Actor*>* actors;
	LuaState* lua;
	

};


