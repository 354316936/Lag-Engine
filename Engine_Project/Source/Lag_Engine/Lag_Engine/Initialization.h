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


typedef unsigned long DWORD, *PDWORD, *LPDWORD;
typedef ULONGLONG DWORDLONG, *PDWORDLONG;




extern bool CheckStorage(const DWORDLONG diskSpaceNeeded);
extern DWORD ReadCPUSpeed();
extern bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
extern bool IsOnlyInstance(LPCTSTR gameTitle);
