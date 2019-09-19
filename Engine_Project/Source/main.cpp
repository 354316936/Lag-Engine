#include <iostream>
#include <Windows.h>
#include <direct.h>


typedef unsigned long DWORD, * PDWORD, * LPDWORD;
typedef ULONGLONG DWORDLONG, *PDWORDLONG;


#include <stdio.h>
#include <tchar.h>
const DWORDLONG storageNeed = 300;
const DWORDLONG pRAMNeed = 1;
const DWORDLONG vRAMNeed = 1;


using namespace std;
bool IsOnlyInstance(LPCTSTR gameTitle);
bool CheckStorage(const DWORDLONG diskSpaceNeeded);


extern DWORD ReadCPUSpeed();


int main()
{
	//std::cout << "Hello World" << std::endl;
	ReadCPUSpeed();
	getchar();
	return 0;
}
DWORD ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);


int main()
{
	bool storageCheck;
	storageCheck = CheckStorage(storageNeed);
	if (storageCheck == true)
	{
		cout << "You hava enough storage!" << endl;
	}


	bool instanceCheck;
	LPCTSTR GT = "Engine";
	instanceCheck = IsOnlyInstance(GT);
	if (instanceCheck = 1)
	{

		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)& dwMHz, &BufSize);
		std::cout << "MHz: " << dwMHz << "\n" << std::endl;
		std::cout << "hKey: " << hKey << "\n" << std::endl;
		std::cout << "type: " << type << "\n" << std::endl;
		std::cout << "BufSize: " << BufSize << "\n" << std::endl;

		cout << "The game instance check success!" << endl;

	}
	return 0;
}



bool IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}



bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 neededClusters;
	neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster *
			diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "CheckStorage Failure: Not enough physical storage." << endl;
		return false;

	}
	return true;
}

