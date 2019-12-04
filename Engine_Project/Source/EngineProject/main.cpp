#include "windows.h"
#include "GameEngine.h"
#include "Base/Handler.h"
#include "Base/Event.h"
#include "Events/MouseE.h"
#include "Events/KeyboardE.h"
#include "LuaPlus.h"

void mouseClick(const Event& e);
void keyboardPress(const Event& e);
using namespace std;
using namespace LuaPlus;




int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{
	LuaState* pLuaState = LuaState::Create();

	GameEngine* engine = GameEngine::GetInstance();
	if (engine->InitInstance(hInstance, previousInstance, cmdLine, nCmdShow, "Our Game"))
	{
		Handler::GetInstance()->Subscribe(EventType::MouseEvent, &mouseClick);
		Handler::GetInstance()->Subscribe(EventType::KeyboardEvent, &keyboardPress);
		pLuaState->DoString("MyTable = { Hi = 5, Hello = 10, Yo = 6 }");

		LuaObject obj = pLuaState->GetGlobals()["MyTable"];
		for (LuaTableIterator it(obj); it; it.Next())
		{
			const char* key = it.GetKey().GetString();
			int num = it.GetValue().GetInteger();
			engine->PrintOnWindow(key);

		}
		

		
		engine->Run();
	}
	LuaState::Destroy(pLuaState);
	pLuaState = NULL;
	return 0;
}
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
		MouseEventS = myMouseEvent.leftClick ? "Left " + MouseEventS : "Right " + MouseEventS;
		GameEngine::GetInstance()->PrintOnWindow(MouseEventS);
	}
}

void keyboardPress(const Event& e)
{
	if (e.Handler == EventType::KeyboardEvent)
	{
		char buffer[100];
		const KeyboardE& myKeyboardEvent = static_cast<const KeyboardE&>(e);
		string message = "Pressed key: ";
		if (myKeyboardEvent.isChar)
			message += myKeyboardEvent.keyChar;
		else
			message += myKeyboardEvent.keyInt;
		GameEngine::GetInstance()->PrintOnWindow(message);
	}
}