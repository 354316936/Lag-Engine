#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <tchar.h>
const DWORDLONG storageNeed = 300;
const DWORDLONG pRAMNeed = 1;
const DWORDLONG vRAMNeed = 1;

using namespace std;
bool IsOnlyInstance(LPCTSTR gameTitle);
bool CheckStorage(const DWORDLONG diskSpaceNeeded);


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