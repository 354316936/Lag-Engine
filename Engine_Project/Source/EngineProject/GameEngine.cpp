#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include <iostream>
#include <windows.h>
#include <direct.h>
#include <intrin.h>
#include <strsafe.h>
#include <tchar.h>
#include <string>
#include "Systems/ScriptSystem.h"

using namespace std;

GameEngine* GameEngine::instance = 0;
GameEngine* GameEngine::GetInstance()
{
	if (!instance)
	{
		instance = new GameEngine();
	}
	return instance;
}
GameEngine::GameEngine()
{
}
void GameEngine::Print(string message)
{
	message += "\n";
	char buf[1000];
	sprintf_s(buf, message.c_str());
}
bool GameEngine::IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd)
		{
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd); SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			MessageBox(NULL, _T("You connot open multiple instances!"), _T("Error"), NULL);
			return false;
		}
	}
	Print("Multiple Instances check succeeded!");
	return true;
}

bool GameEngine::CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters =
		diskSpaceNeeded /
		(diskfree.sectors_per_cluster * diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters)
	{
		TCHAR pszDest[260] = _T("");
		sprintf_s(pszDest, 260, TEXT("You donot have enough storage to run the game."), diskSpaceNeeded / MB);
		MessageBox(NULL, pszDest, _T("Failure"), NULL);
	}
	return true;
}

bool GameEngine::CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	BOOL result = GlobalMemoryStatusEx(&status);

	cout << "Physical Memory: You have " << status.ullAvailPhys / MB << " MB free" << endl;
	cout << "Virtual Memory: You have " << status.ullAvailVirtual / MB << " MB free" << endl;
	if (status.ullTotalPhys < physicalRAMNeeded) {
		TCHAR pszDest[260] = _T("");
		sprintf_s(pszDest, 260, TEXT("You donot have enough physical memory to run the game."), physicalRAMNeeded / MB);
		MessageBox(NULL, pszDest, _T("Failure"), NULL);
		return false;
	}
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		TCHAR pszDest[260] = _T("");
		sprintf_s(pszDest, 260, TEXT("You donot have enough virtual memory to run the game."), virtualRAMNeeded / MB);
		MessageBox(NULL, pszDest, _T("Failure"), NULL);
		return false;
	}
	return true;
}

void GameEngine::ReadCPU()
{
	int CPUInfo[4] = { -1 };
	unsigned   nExIds, i = 0;
	char CPUBrandString[0x40];
	__cpuid(CPUInfo, 0x80000000);
	nExIds = CPUInfo[0];

	for (i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		if (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}

	string cpuType = "Your CPU Type is: ";
	cpuType += CPUBrandString;
	cpuType += "\nNumber of Cores: ";

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	char convertBuffer[32];
	wsprintf(convertBuffer, "%d", sysInfo.dwNumberOfProcessors);
	cpuType += convertBuffer;

	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "~MHz", NULL,&type, (LPBYTE)&dwMHz, &BufSize);
		cpuType += "\nIts speed is: ";
		wsprintf(convertBuffer, "%d", dwMHz);
		cpuType += convertBuffer;
		cpuType += " MHz\n";
	}
	Print(cpuType);
}

bool GameEngine::InitInstance(HINSTANCE _hInstance, HINSTANCE _previousInstance, PSTR _cmdLine, INT _nCmdShow, string _szTitle)
{
	hInstance = _hInstance;
	previousInstance = _previousInstance;
	cmdLine = _cmdLine;
	nCmdShow = _nCmdShow;
	szTitle = _szTitle;

	if (IsOnlyInstance(szTitle.c_str()))
	{
		Print("Starting system check...");
		bool result = CheckStorage(DISK_SPACE_NEEDED) && CheckMemory(PHYSICAL_MEMORY_NEEDED, VIRTUAL_MEMORY_NEEDED);
		if (result) { ReadCPU(); }
		return result;
	}
	else
	{
		return false;
	}

	
}

void GameEngine::Run()
{
	RenderingSystem rs(szTitle);
	ScriptSystem ss(&actors);

	MSG msg;
	ss.Run();
	while (rs.IsWindowOpen())
	{
		sf::Event event;
		while (rs.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				rs.WindowClose();
		}
		rs.RenderActors(&actors);
	}
}
void GameEngine::AddActor(Actor* _actor)
{
	actors.push_back(_actor);
}
