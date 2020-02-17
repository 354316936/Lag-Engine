#include <SFML/Graphics.hpp>
#include "windows.h"
#include "GameEngine.h"
#include "Base/Handler.h"
#include "Base/Event.h"
#include "Events/MouseE.h"
#include "Events/KeyboardE.h"
#include "LuaPlus.h"
#include "Base/Actor.h"
#include "Components/ScriptComponent/ScriptComponent.h"
#include "Components/CircleComponent.h"
#include "Components/TransformComponent.h"




using namespace std;
using namespace LuaPlus;
void mouseClick(const Event& e);
void keyboardPress(const Event& e);
