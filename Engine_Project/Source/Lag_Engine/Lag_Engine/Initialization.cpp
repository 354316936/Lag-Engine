#include <shlobj.h>
#include <direct.h>
#include "Initialization.h"


using namespace std;

DWORD Initialization::ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	DWORD dwType = REG_SZ;
	char value[256];
	DWORD dwCount = sizeof(value);
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, ("~MHZ"), NULL, &type, (LPBYTE)& dwMHz, &BufSize);
		std::cout << "MHz: " << dwMHz << "\n" << std::endl;
		std::cout << "type: " << type << "\n" << std::endl;
		std::cout << "BufSize: " << BufSize << "\n" << std::endl;
		std::cout << "Name: " << BufSize << "\n" << std::endl;
		(RegQueryValueEx(hKey, "ProcessorNameString", NULL, &type, (LPBYTE)&value, &dwCount) != ERROR_SUCCESS);
		std::cout << "Name: " << value << "\n" << std::endl;
		
	}
	return dwMHz;
	return BufSize;
	return	type;
}
// CheckMemory
//
bool Initialization::CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
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
		std::cout << "physical memory:" << (WIDTH, status.ullTotalPhys / DIV) << "\n" << std::endl;
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
		std::cout << "virtual memory:" << (WIDTH, status.ullTotalVirtual / DIV) << "\n" << std::endl;
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

bool Initialization::CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree = { 0 };

	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters =
		diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		// if you get here you donít have enough disk space!
		std::cout << "CheckStorage Failure: Not enough physical storage." << std::endl;
		return false;
	}
	return true;
}

bool Initialization::IsOnlyInstance(LPCTSTR gameTitle)
{
	// Find the window.  If active, set and return false
	// Only one game instance may have this mutex at a time...

	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);

	// Does anyone else think 'ERROR_SUCCESS' is a bit of an oxymoron?
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd)
		{
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);

			return false;
		}
		return 0;
	}

	return true;

}

Initialization::Initialization()
{
}

Initialization::~Initialization()
{
}
