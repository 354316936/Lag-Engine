#include <iostream>
#include "Lag_Engine/Lag_Engine/Initialization.h"

Initialization Init;

int DisplayResourceNAMessageBox()
{
	int msgboxID = MessageBox(
		NULL,
		"You can't open two windows?",
		" ",
		MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
	);

	switch (msgboxID)
	{
	case IDOK:
		exit(0);
		break;
	case IDTRYAGAIN:
		exit(0);
		break;
	case IDCANCEL:
		exit(0);
		break;
	}

	return msgboxID;
}
void Check()
{
	Init.ReadCPUSpeed();
	if (Init.CheckStorage(307200))//can pass the function to if() directly
	{
		std::cout << "You have 300 MB available storage\n";
	}
	else
	{
		std::cout << "No enought space to install the game\n";
	}
	if (Init.CheckMemory(2e+6, 2e+6))
	{
		std::cout << "You have enough memory\n";
	}
	else
	{
		std::cout << "You don't have enough memory\n";

	}
	const TCHAR* Title = "Game";
	if (Init.IsOnlyInstance(Title))
	{
		std::cout << "Game SUCCESS \n";
	}
	else if (!Init.IsOnlyInstance(Title)) {
		std::cout << "Game Fails \n";
		DisplayResourceNAMessageBox();
	}

	
}


int main()
{
	
	//std::cout << "Hello World" << std::endl;
	Check();
	getchar();
	
	return 0;
}

