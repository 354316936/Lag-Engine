#pragma once
#include <Windows.h>
#include <windowsx.h>
#include <shlobj.h>
#include <direct.h>
#include <atlstr.h >
#include <atlbase.h>
#include <iostream>
#define DIV 1024
#define WIDTH 7

class Initialization{
public:
		Initialization();
		~Initialization();

		typedef unsigned long DWORD, *PDWORD, *LPDWORD;
		typedef ULONGLONG DWORDLONG, *PDWORDLONG;




		 bool CheckStorage(const DWORDLONG diskSpaceNeeded);
		 DWORD ReadCPUSpeed();
		 bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
		 bool IsOnlyInstance(LPCTSTR gameTitle);

};
