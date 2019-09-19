#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <shlobj.h>
#include <direct.h>
#include <atlstr.h >
#include <atlbase.h>
#define DIV 1024
#define WIDTH 7


typedef unsigned long DWORD, * PDWORD, * LPDWORD;
typedef ULONGLONG DWORDLONG, *PDWORDLONG;



using namespace std;



extern bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);


int main()
{
	//std::cout << "Hello World" << std::endl;


	if (CheckMemory(2e+6, 2e+6))
	{
		std::cout << "You have enough memory\n";
	}
	else
	{
		std::cout << "You don't have enough memory\n";

	}
	getchar();
	return 0;
}


// CheckMemory
//
bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		// you don't have enough physical memory. Tell the player to go get a real 
		// computer and give this one to his mother. 
		std::cout << "CheckMemory Failure: Not enough physical memory." << std::endl;
		return false;
	}
	else {
		std::cout << "physical memory:" << ( WIDTH ,status.ullTotalPhys / DIV) << "\n" << std::endl;
	}

	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		// you donít have enough virtual memory available. 
		// Tell the player to shut down the copy of Visual Studio running in the
		// background, or whatever seems to be sucking the memory dry.
		std::cout << "CheckMemory Failure: Not enough virtual memory." << std::endl;
		return false;
	}
	else {
		std::cout << "virtual memory:" << (WIDTH,status.ullTotalVirtual / DIV) << "\n" << std::endl;
	}

	char* buff = new char[(unsigned int)virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else
	{
		// even though there is enough memory, it isnít available in one 
		// block, which can be critical for games that manage their own memory
		std::cout << "CheckMemory Failure: Not enough contiguous available memory." << std::endl;
		return false;
	}
	return true;
}

