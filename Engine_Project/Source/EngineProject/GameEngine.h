#pragma once
#ifndef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__
#include <windows.h>
#include <tchar.h>
#include <string>
#include "Systems/RenderingSystem.h"
#include "Base/Actor.h"

using namespace std;

class GameEngine
{
private:
	GameEngine();
	bool IsOnlyInstance(LPCTSTR windowName);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	void ReadCPU();
	const DWORDLONG MB = 1024 * 1024;
	const DWORDLONG DISK_SPACE_NEEDED = 500 * MB;
	const DWORDLONG PHYSICAL_MEMORY_NEEDED = 500 * MB;
	const DWORDLONG VIRTUAL_MEMORY_NEEDED = 500 * MB;
	static GameEngine* instance;
	HINSTANCE hInstance;
	HINSTANCE previousInstance;
	PSTR cmdLine;
	INT nCmdShow;
	string szTitle;
	vector<Actor*> actors;
public:
	static GameEngine* GetInstance();
	bool InitInstance(HINSTANCE _hInstance, HINSTANCE _previousInstance, PSTR _cmdLine, INT _nCmdShow, string _szTitle);
	void Print(string message);
	void Run();
	void AddActor(Actor* _actor);
	void PrintToWindow(string message);

};
#endif

