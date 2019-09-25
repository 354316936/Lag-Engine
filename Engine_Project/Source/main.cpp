#include <iostream>
#include "Lag_Engine/Lag_Engine/Initialization.h"

Initialization Init;
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

	const TCHAR* Title = "Game";
	if (Init.IsOnlyInstance(Title))
	{
		std::cout << "Game SUCCESS \n";
	}
	else if (!Init.IsOnlyInstance(Title)) {
		std::cout << "Game Fails \n";
		exit(0);
	}

	if (Init.CheckMemory(2e+6, 2e+6))
	{
		std::cout << "You have enough memory\n";
	}
	else
	{
		std::cout << "You don't have enough memory\n";

	}
}


int main()
{
	
	//std::cout << "Hello World" << std::endl;
	Check();
	getchar();
	
	return 0;
}

