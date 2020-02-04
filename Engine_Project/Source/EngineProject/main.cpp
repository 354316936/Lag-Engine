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

/*
void mouseClick(const Event& e) {
	if (e.Handler == EventType::MouseEvent)
	{
		char number[10];
		const MouseE& myMouseEvent = static_cast<const MouseE&>(e);
		string MouseEventS = "Mouse Clicked at   ";
		snprintf(number, sizeof(number), "%d", myMouseEvent.x);
		MouseEventS += number;
		MouseEventS += " ";
		snprintf(number, sizeof(number), "%d", myMouseEvent.y);
		MouseEventS += number;
		if (myMouseEvent.leftClick)
			MouseEventS = "Left " + MouseEventS;
		else
			MouseEventS = "Right " + MouseEventS;
		GameEngine::GetInstance()->PrintOnWindow(MouseEventS);
	}
}

void keyboardPress(const Event& e)
{
	if (e.Handler == EventType::KeyboardEvent)
	{
		const KeyboardE& myKeyboardEvent = static_cast<const KeyboardE&>(e);
		string message = "Pressed key: ";
		if (myKeyboardEvent.isChar)
			message += myKeyboardEvent.keyChar;
		else
			message += myKeyboardEvent.keyInt;
		GameEngine::GetInstance()->PrintOnWindow(message);
	}
}
*/
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{
	GameEngine* engine = GameEngine::GetInstance();
	if (engine->InitInstance(hInstance, previousInstance, cmdLine, nCmdShow, "Our Game"))
	{
		/*Handler::GetInstance()->Subscribe(EventType::MouseEvent, &mouseClick);
		Handler::GetInstance()->Subscribe(EventType::KeyboardEvent, &keyboardPress);*/


		
		Actor* sun = new Actor();
		CircleComponent* yellowCircle = new CircleComponent(20, sf::Color::Yellow);
		sun->AddComponent(yellowCircle);

		Actor* earth = new Actor();
		CircleComponent* blueCircle = new CircleComponent(20, sf::Color::Blue);
		earth->AddComponent(blueCircle);

		Actor* moon = new Actor();
		CircleComponent* whiteCircle = new CircleComponent(10, sf::Color::White);
		moon->AddComponent(whiteCircle);

		sun->AddChild(earth);
		earth->AddChild(moon);

		//moon->transComp->Translate(50, 0);
		//moon->transComp->Scale(0.3, 0.3);

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
