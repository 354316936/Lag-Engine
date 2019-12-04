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


void testFun(const Event& e) {
	if (e.descriptor == EventType::MouseClick)
	{
		char number[10];
		const MouseEvent& myMouseEvent = static_cast<const MouseEvent&>(e);
		string printing = "Mouse Clicked on (";
		snprintf(number, sizeof(number), "%d", myMouseEvent.x);
		printing += number;
		printing += ",";
		snprintf(number, sizeof(number), "%d", myMouseEvent.y);
		printing += number;
		printing += ")";
		printing = myMouseEvent.leftClick ? "Left " + printing : "Right " + printing;
		Initialization::GetInstance()->PrintToWindow(printing);
	}
}

void keyboardFun(const Event& e)
{
	if (e.descriptor == EventType::KeyboardPress)
	{
		char buffer[100];
		const KeyboardEvent& myKeyboardEvent = static_cast<const KeyboardEvent&>(e);
		string message = "Key Pressed: ";
		if (myKeyboardEvent.isChar)
			message += myKeyboardEvent.keyChar;
		else
			message += myKeyboardEvent.keyInt;
		Initialization::GetInstance()->PrintToWindow(message);
	}
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{


	Initialization* init = Initialization::GetInstance();
	if (init->InitInstance(hInstance, previousInstance, cmdLine, nCmdShow, "So damn fucking lag"))
	{

		Dispatcher::GetInstance()->Subscribe(EventType::MouseClick, &testFun);
		Dispatcher::GetInstance()->Subscribe(EventType::KeyboardPress, &keyboardFun);

		init->Run();
	}


	return 0;
}

