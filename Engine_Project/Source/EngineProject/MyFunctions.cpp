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
#include "MyFunctions.h"




using namespace std;
using namespace LuaPlus;


void mouseClick(const Event& e) {

	if (e.Handler == EventType::MouseEvent)
	{
		string printing = "Mouse Clicked";
		GameEngine::GetInstance()->Print(printing);
	}

}

void keyboardPress(const Event& e)
{

	if (e.Handler == EventType::KeyboardEvent)
	{
		string message = "Key Pressed";
		GameEngine::GetInstance()->Print(message);
	}

}

//void mouseClick(const Event& e) {
//	string test = "test";
//	GameEngine::GetInstance()->Print(test);
//	if (e.Handler == EventType::MouseEvent)
//	{
//		char number[10];
//		const MouseE& myMouseEvent = static_cast<const MouseE&>(e);
//		string printing = "Mouse Clicked on (";
//		snprintf(number, sizeof(number), "%d", myMouseEvent.x);
//		printing += number;
//		printing += ",";
//		snprintf(number, sizeof(number), "%d", myMouseEvent.y);
//		printing += number;
//		printing += ")";
//		printing = myMouseEvent.leftClick ? "Left " + printing : "Right " + printing;
//		GameEngine::GetInstance()->Print(printing);
//	}
//	
//}
//
//void keyboardPress(const Event& e)
//{
//
//
//	if (e.Handler == EventType::KeyboardEvent)
//	{
//		char buffer[100];
//		const KeyboardE& myKeyboardEvent = static_cast<const KeyboardE&>(e);
//		string message = "Key Pressed: ";
//		if (myKeyboardEvent.isChar)
//			message += myKeyboardEvent.keyChar;
//		else
//			message += myKeyboardEvent.keyInt;
//		GameEngine::GetInstance()->Print(message);
//	}
//	
//}