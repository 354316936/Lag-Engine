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
#include "Components/AudioComponent.h"
#include "MyFunctions.h"
#include <iostream>


using namespace std;
using namespace LuaPlus;


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

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{
	GameEngine* engine = GameEngine::GetInstance();
	if (engine->InitInstance("Our Game"))
	{
		
		Handler::GetInstance()->Subscribe(EventType::MouseEvent, &mouseClick);
		Handler::GetInstance()->Subscribe(EventType::KeyboardEvent, &keyboardPress);

		/*AudioComponent myAudio;
		myAudio.playMusic("Assets/orchestral.ogg", true);*/

		Actor* sun = new Actor();
		CircleComponent* yellowCircle = new CircleComponent(20, sf::Color::Yellow);
		sun->AddComponent(yellowCircle);
		sun->AddComponent(new ScriptComponent("Assets/testScript.lua"));

		Actor* earth = new Actor();
		CircleComponent* blueCircle = new CircleComponent(20, sf::Color::Blue);
		earth->AddComponent(blueCircle);

		Actor* moon = new Actor();
		CircleComponent* whiteCircle = new CircleComponent(10, sf::Color::White);
		moon->AddComponent(whiteCircle);

		sun->AddChild(earth);
		earth->AddChild(moon);

		moon->transComp->Translate(50, 0);
		moon->transComp->Scale(0.3, 0.3);

		earth->transComp->Translate(50, 0);
		earth->transComp->Scale(0.5, 0.5);

		sun->transComp->Translate(100, 500);
		sun->transComp->Scale(5, 5);

		engine->AddActor(sun);
		engine->AddActor(earth);
		engine->AddActor(moon);

		engine->Run();
		
	}
	
	return 0;
}
