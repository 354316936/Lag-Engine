
#include <vector>
#include "../Base/Actor.h"
#include "../Components/ScriptComponent/ScriptComponent.h"
#include "../GameEngine.h"

class ScriptSystem
{
public:
	ScriptSystem(vector<Actor*>* _actors);
	~ScriptSystem();
	void Run();

private:
	vector<Actor*>* actors;
	
};


