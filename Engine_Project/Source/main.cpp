#include <iostream>
#include "Lag_Engine/Lag_Engine/Initialization.h"
#include "Lag_Engine/Lag_Engine/_Interface.h"
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  

Initialization Init;
_Interface UI;

int main()
{
	
	//std::cout << "Hello World" << std::endl;
	Init.Check();
	UI.onCreateWindows();
	getchar();
	
	return 0;
}

