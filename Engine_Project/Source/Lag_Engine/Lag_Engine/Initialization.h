#pragma once
#ifndef __Initialization_H__
#define __Initialization_H__
#include <windows.h>
#include <tchar.h>
#include <string>
#include "RenderSystem.h"

using namespace std;

class Initialization{

private:
	bool IsOnlyInstance(LPCTSTR windowName);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	void ReadCPUSpeed();
	void ErrorExit(const char* lpszFunction);
	//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM param, LPARAM lparam);
	/*
	 * For some unusual reason we always need 300 MB everywhere.
	 * Curious, isn't it?
	 */
	const DWORDLONG MB = 1024 * 1024;
	const DWORDLONG DISK_SPACE_NEEDED = 300 * MB;
	const DWORDLONG PHYSICAL_MEMORY_NEEDED = 300 * MB;
	const DWORDLONG VIRTUAL_MEMORY_NEEDED = 300 * MB;
	HINSTANCE hInstance;
	HINSTANCE previousInstance;
	PSTR cmdLine;
	INT nCmdShow;
	string szTitle;
	Initialization();
	~Initialization();
	static Initialization* instance;
public:
	static Initialization* GetInstance();
	bool InitInstance(HINSTANCE _hInstance, HINSTANCE _previousInstance, PSTR _cmdLine, INT _nCmdShow, string _szTitle);
	void Run();
	void Print(string message);
	void PrintToWindow(string message);
};
#endif 