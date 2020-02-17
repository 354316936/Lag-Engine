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
