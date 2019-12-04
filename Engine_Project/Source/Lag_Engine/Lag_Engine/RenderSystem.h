#pragma once
#ifndef __RENDERSYSTEM_H__
#define __RENDERSYSTEM_H__
#include <windows.h>
#include <tchar.h>
#include <string>
#include "Input.h"

using namespace std;

class RenderSystem
{
private:
	HINSTANCE hInstance;
	HINSTANCE previousInstance;
	PSTR cmdLine;
	INT nCmdShow;
	string szTitle;

public:
	RenderSystem(HINSTANCE _hInstance, HINSTANCE _previousInstance, PSTR _cmdLine, INT _nCmdShow, string _szTitle);
	~RenderSystem();
	void WindowCreate();
};

#endif 