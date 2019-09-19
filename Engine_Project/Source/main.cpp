#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <shlobj.h>
#include <direct.h>


typedef unsigned long DWORD, * PDWORD, * LPDWORD;
typedef ULONGLONG DWORDLONG, *PDWORDLONG;


using namespace std;

//extern bool CheckStorage(const DWORDLONG diskSpaceNeeded);
extern DWORD ReadCPUSpeed();
//extern bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
//extern bool IsOnlyInstance(const TCHAR* gameTitle);

int main()
{
	//std::cout << "Hello World" << std::endl;
	ReadCPUSpeed();
	//if (CheckStorage(307200))//can pass the function to if() directly
	//{
	//	std::cout << "You have 300 MB available storage\n";
	//}
	//else
	//{
	//	std::cout << "No enought space to install the game\n";
	//}
	//if (!IsOnlyInstance)
	//{
	//	std::cout << "Hey! don't try to cheat on the game\n";
	//}

	//if (CheckMemory(2e+6, 2e+6))
	//{
	//	std::cout << "You have enough memory\n";
	//}
	//else
	//{
	//	std::cout << "You don't have enough memory\n";
	//}
	//return 0;
}
DWORD ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, L"~MHz", NULL, &type, (LPBYTE)& dwMHz, &BufSize);
		std::cout << "MHz: " << dwMHz << "\n" << std::endl;
		std::cout << "hKey: " << hKey << "\n" << std::endl;
		std::cout << "type: " << type << "\n" << std::endl;
		std::cout << "BufSize: " << BufSize << "\n" << std::endl;
	}
	return dwMHz;
}
// CheckMemory
//
//bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
//{
//	MEMORYSTATUSEX status;
//	GlobalMemoryStatusEx(&status);
//	if (status.ullTotalPhys < physicalRAMNeeded)
//	{
//		// you donít have enough physical memory. Tell the player to go get a real 
//		// computer and give this one to his mother. 
//		std::cout << "CheckMemory Failure: Not enough physical memory." << std::endl;
//		return false;
//	}
//	else {
//		std::cout << "physical memory:" << status.ullTotalPhys << "\n" << std::endl;
//	}
//
//	// Check for enough free memory.
//	if (status.ullAvailVirtual < virtualRAMNeeded)
//	{
//		// you donít have enough virtual memory available. 
//		// Tell the player to shut down the copy of Visual Studio running in the
//		// background, or whatever seems to be sucking the memory dry.
//		std::cout << "CheckMemory Failure: Not enough virtual memory." << std::endl;
//		return false;
//	}
//	else {
//		std::cout << "virtual memory:" << status.ullAvailVirtual << "\n" << std::endl;
//	}
//
//	char* buff = new char[(unsigned int)virtualRAMNeeded];
//	if (buff)
//		delete[] buff;
//	else
//	{
//		// even though there is enough memory, it isnít available in one 
//		// block, which can be critical for games that manage their own memory
//		std::cout << "CheckMemory Failure: Not enough contiguous available memory." << std::endl;
//		return false;
//	}
//	return true;
//}

//bool CheckStorage(const DWORDLONG diskSpaceNeeded)
//{
//	// Check for enough free disk space on the current disk.
//	int const drive = _getdrive();
//	struct _diskfree_t diskfree = { 0 };
//
//	_getdiskfree(drive, &diskfree);
//
//	unsigned __int64 const neededClusters =
//		diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);
//
//	if (diskfree.avail_clusters < neededClusters)
//	{
//		// if you get here you donít have enough disk space!
//		std::cout << "CheckStorage Failure: Not enough physical storage." << std::endl;
//		return false;
//	}
//	return true;
//}




//bool IsOnlyInstance(const TCHAR* gameTitle)
//{
//	// Find the window.  If active, set and return false
//	// Only one game instance may have this mutex at a time...
//
//	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
//
//	// Does anyone else think 'ERROR_SUCCESS' is a bit of an oxymoron?
//	if (GetLastError() != ERROR_SUCCESS)
//	{
//		HWND hWnd = FindWindow(gameTitle, NULL);
//		if (hWnd)
//		{
//			// An instance of your game is already running.
//			ShowWindow(hWnd, SW_SHOWNORMAL);
//			SetFocus(hWnd);
//			SetForegroundWindow(hWnd);
//			SetActiveWindow(hWnd);
//			return false;
//		}
//	}
//	return true;
//}