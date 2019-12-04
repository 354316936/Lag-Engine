#pragma once
#pragma once
#ifndef __INPUT_H__
#define __INPUT_H__
#include <windows.h>
#include <tchar.h>
#include <Windowsx.h>
#include "../Lag_Engine/Initialization.h"
#include <string>

using namespace std;

class Input
{
private:
	static TCHAR WindowText[2000];
public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM param, LPARAM lparam);
	static void ChangeMessage(string message);
};
#endif 
