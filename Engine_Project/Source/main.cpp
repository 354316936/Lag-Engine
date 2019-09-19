#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <shlobj.h>
#include <direct.h>




























































typedef unsigned long DWORD, * PDWORD, * LPDWORD;
typedef ULONGLONG DWORDLONG, *PDWORDLONG;


using namespace std;

extern DWORD ReadCPUSpeed();


int main()
{
	//std::cout << "Hello World" << std::endl;
	ReadCPUSpeed();
	getchar();
	return 0;
}
DWORD ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)& dwMHz, &BufSize);
		std::cout << "MHz: " << dwMHz << "\n" << std::endl;
		std::cout << "hKey: " << hKey << "\n" << std::endl;
		std::cout << "type: " << type << "\n" << std::endl;
		std::cout << "BufSize: " << BufSize << "\n" << std::endl;
	}
	return dwMHz;
}
