#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <tchar.h>
const DWORDLONG storageNeed= 300;
const DWORDLONG pRAMNeed = 1;
const DWORDLONG vRAMNeed = 1;

using namespace std;
bool IsOnlyInstance(LPCTSTR gameTitle);
DWORD ReadCPUSpeed();
bool CheckStorage(const DWORDLONG diskSpaceNeeded);
bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);


int main() 
{
	bool instanceCheck;
	LPCTSTR GT = "Engine";
	instanceCheck=IsOnlyInstance(GT);
	if (instanceCheck = 1)
	{
	cout << "The game instance check success!" << endl;
	}


	DWORD displayCPU;
	displayCPU = ReadCPUSpeed();
	cout << displayCPU << endl;

	bool storageCheck;
	storageCheck = CheckStorage(storageNeed);
	if (storageCheck == true)
	{
		cout << "You hava enough storage!" << endl;
	}
	bool memoryCheck;

	memoryCheck = CheckMemory(pRAMNeed, vRAMNeed);

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


DWORD ReadCPUSpeed() 
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",0,KEY_READ,&hKey);

	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "MHz",NULL,&type,(LPBYTE)&dwMHz, &BufSize);	}	return dwMHz;}bool CheckStorage(const DWORDLONG diskSpaceNeeded) 
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
		cout<<"CheckStorage Failure: Not enough physical storage."<<endl;
		return false;

	}
	return true;
}



bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded) 
{
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded) {
		
		cout<<"CheckMemory Failure: Not enough physical memory."<<endl;
		return false;
	}
	cout << "There are " << status.ullTotalPhys << " physical memory avaliable" << endl;
	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		
			cout<<"CheckMemory Failure: Not enough virtual memory."<<endl;
		return false;
	}
	cout << "There are " << status.ullAvailVirtual << " virtual memory avaliable" << endl;

	char *buff = new char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else {
		
			cout<<"CheckMemory Failure: Not enough contiguous memory."<<endl;
		return false;	}}