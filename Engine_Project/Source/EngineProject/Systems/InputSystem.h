#pragma once
#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__
#include <windows.h>
#include <tchar.h>
#include <Windowsx.h>
#include "../GameEngine.h"
#include <string>

using namespace std;

class InputSystem
{
private:
	static TCHAR WindowText[1000];
public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM param, LPARAM lparam);
	static void ChangeMessage(string message);
};

#endif 
