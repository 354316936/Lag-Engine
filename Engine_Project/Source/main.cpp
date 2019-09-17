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


int main()
{
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

