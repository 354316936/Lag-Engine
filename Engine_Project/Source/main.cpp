#include <iostream>
#include "Lag_Engine/Lag_Engine/Initialization.h"
#include "Lag_Engine/Lag_Engine/_Interface.h"
#include "Lag_Engine/Lag_Engine/Dispatcher.h"
#include "Lag_Engine/Lag_Engine/Event.h"
#include "Lag_Engine/Lag_Engine/KeyboardEvent.h"
#include "Lag_Engine/Lag_Engine/MouseEvent.h"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <ctype.h>
#include <basetsd.h> 
#include <winnt.h>
#include <tchar.h>


void CheckMousePoint(const Event& e) {
	if (e.descriptor == EventType::MouseClick)
	{
		char size[10];
		const MouseEvent& thisMouse = static_cast<const MouseEvent&>(e);
		string text = "Mouse Position (";
		snprintf(size, sizeof(size), "%d", thisMouse.x);
		text += size;
		text += ",";
		snprintf(size, sizeof(size), "%d", thisMouse.y);
		text += size;
		text += ")";
		text = thisMouse.leftClick ? "Left " + text : "Right " + text;
		Initialization::GetInstance()->PrintToWindow(text);
	}
}

void OnPressKeyBoard(const Event& e)
{
	if (e.descriptor == EventType::KeyboardPress)
	{
		char Keys[100];
		const KeyboardEvent& thisKey = static_cast<const KeyboardEvent&>(e);
		string message = "Key Pressed: ";
		if (thisKey.isChar)
			message += thisKey.keyChar;
		else
			message += thisKey.keyInt;
		Initialization::GetInstance()->PrintToWindow(message);
	}
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{


	Initialization* init = Initialization::GetInstance();
	if (init->InitInstance(hInstance, previousInstance, cmdLine, nCmdShow, "So damn fucking lag"))
	{

		Dispatcher::GetInstance()->Subscribe(EventType::MouseClick, &CheckMousePoint);
		Dispatcher::GetInstance()->Subscribe(EventType::KeyboardPress, &OnPressKeyBoard);

		init->Run();
	}


	return 0;
}

