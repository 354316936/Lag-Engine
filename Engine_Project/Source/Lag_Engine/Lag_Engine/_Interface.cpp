//#include "_Interface.h"
//#include "Initialization.h"
//#include<stdlib.h>
//#include <windowsx.h>
//#include <windows.h>
//#include <strsafe.h>
//
//#define IDC_MAIN_EDIT   101
//#define WIDTH 800
//#define HEIGHT 600
//#define BUFSIZE 65535 
//#define SHIFTED 0x8000 
//HINSTANCE hIns;
//LPSTR  lp;
//
//Initialization* Init;
//
//
//using namespace std;
//LONG APIENTRY MainWndProc(HWND hwndMain, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	TCHAR greeting[] = _T(" ");
//	HDC hdc;                   // handle to device context 
//	TEXTMETRIC tm;             // structure for text metrics 
//	static DWORD dwCharX;      // average width of characters 
//	static DWORD dwCharY;      // height of characters 
//	static DWORD dwClientX;    // width of client area 
//	static DWORD dwClientY;    // height of client area 
//	static DWORD dwLineLen;    // line length 
//	static DWORD dwLines;      // text lines in client area 
//	static int nCaretPosX = 0; // horizontal position of caret 
//	static int nCaretPosY = 0; // vertical position of caret 
//	static int nCharWidth = 0; // width of a character 
//	static int cch = 0;        // characters in buffer 
//	static int nCurChar = 0;   // index of current character 
//	static PTCHAR pchInputBuf; // input buffer 
//	int i, j;                  // loop counters 
//	int cCR = 0;               // count of carriage returns 
//	int nCRIndex = 0;          // index of last carriage return 
//	int nVirtKey;              // virtual-key code 
//	TCHAR szBuf[128];          // temporary buffer 
//	TCHAR ch;                  // current character 
//	PAINTSTRUCT ps;            // required by BeginPaint 
//	RECT rc;                   // output rectangle for DrawText 
//	SIZE sz;                   // string dimensions 
//	COLORREF crPrevText;       // previous text color 
//	COLORREF crPrevBk;         // previous background color
//	size_t * pcch = 0;
//
//	int wnd_x = 0;
//	int wnd_y = 0;
//
//	HWND g_hMainWnd = NULL;
//	bool g_MovingMainWnd = false;
//	POINT g_OrigCursorPos;
//	g_OrigCursorPos.x = GET_X_LPARAM(lParam);
//	g_OrigCursorPos.y = GET_Y_LPARAM(lParam);
//	POINT g_OrigWndPos;
//	g_OrigWndPos.x = GET_X_LPARAM(lParam);
//	g_OrigWndPos.y = GET_Y_LPARAM(lParam);
//
//	HRESULT hResult;
//	TCHAR MHz[] = _T("MHz: ");
//	TCHAR Type[] = _T("Type: ");
//	TCHAR BuffSize[] = _T("Buff Size: ");
//
//	CString x;
//	switch (uMsg)
//	{
//	case WM_CREATE:
//
//		// Get the metrics of the current font. 
//
//		hdc = GetDC(hwndMain);
//		GetTextMetrics(hdc, &tm);
//		ReleaseDC(hwndMain, hdc);
//		
//		// Save the average character width and height. 
//
//		dwCharX = tm.tmAveCharWidth;
//		dwCharY = tm.tmHeight;
//
//		// Allocate a buffer to store keyboard input. 
//
//		pchInputBuf = (LPTSTR)GlobalAlloc(GPTR,
//			BUFSIZE * sizeof(TCHAR));
//		return 0;
//
//	case WM_SIZE:
//
//		// Save the new width and height of the client area. 
//
//		dwClientX = LOWORD(lParam);
//		dwClientY = HIWORD(lParam);
//
//		// Calculate the maximum width of a line and the 
//		// maximum number of lines in the client area. 
//
//		dwLineLen = dwClientX - dwCharX;
//		dwLines = dwClientY / dwCharY;
//		break;
//
//
//	case WM_SETFOCUS:
//
//		// Create, position, and display the caret when the 
//		// window receives the keyboard focus. 
//
//		CreateCaret(hwndMain, (HBITMAP)1, 0, dwCharY);
//		SetCaretPos(nCaretPosX, nCaretPosY * dwCharY);
//		ShowCaret(hwndMain);
//		break;
//
//	case WM_KILLFOCUS:
//
//		// Hide and destroy the caret when the window loses the 
//		// keyboard focus. 
//
//		HideCaret(hwndMain);
//		DestroyCaret();
//		break;
//
//	case WM_CHAR:
//		// check if current location is close enough to the
//		// end of the buffer that a buffer overflow may
//		// occur. If so, add null and display contents. 
//		if (cch > BUFSIZE - 5)
//		{
//			pchInputBuf[cch] = 0x00;
//			SendMessage(hwndMain, WM_PAINT, 0, 0);
//		}
//		switch (wParam)
//		{
//		case 0x08:  // backspace 
//		case 0x0A:  // linefeed 
//		case 0x1B:  // escape 
//			MessageBeep((UINT)-1);
//			return 0;
//
//		case 0x09:  // tab 
//
//			// Convert tabs to four consecutive spaces. 
//
//			for (i = 0; i < 4; i++)
//				SendMessage(hwndMain, WM_CHAR, 0x20, 0);
//			return 0;
//
//		case 0x0D:  // carriage return 
//
//			// Record the carriage return and position the 
//			// caret at the beginning of the new line.
//
//			pchInputBuf[cch++] = 0x0D;
//			nCaretPosX = 0;
//			nCaretPosY += 1;
//			break;
//
//		default:    // displayable character 
//
//			ch = (TCHAR)wParam;
//			HideCaret(hwndMain);
//
//			// Retrieve the character's width and output 
//			// the character. 
//
//			hdc = GetDC(hwndMain);
//			GetCharWidth32(hdc, (UINT)wParam, (UINT)wParam,
//				&nCharWidth);
//			TextOut(hdc, nCaretPosX, nCaretPosY * dwCharY,
//				&ch, 1);
//			ReleaseDC(hwndMain, hdc);
//
//			// Store the character in the buffer.
//
//			pchInputBuf[cch++] = ch;
//
//			// Calculate the new horizontal position of the 
//			// caret. If the position exceeds the maximum, 
//			// insert a carriage return and move the caret 
//			// to the beginning of the next line. 
//
//			nCaretPosX += nCharWidth;
//			if ((DWORD)nCaretPosX > dwLineLen)
//			{
//				nCaretPosX = 0;
//				pchInputBuf[cch++] = 0x0D;
//				++nCaretPosY;
//			}
//			nCurChar = cch;
//			ShowCaret(hwndMain);
//			break;
//		}
//		SetCaretPos(nCaretPosX, nCaretPosY * dwCharY);
//		break;
//
//	case WM_KEYDOWN:
//		switch (wParam)
//		{
//		case VK_LEFT:   // LEFT ARROW 
//
//			// The caret can move only to the beginning of 
//			// the current line. 
//
//			if (nCaretPosX > 0)
//			{
//				HideCaret(hwndMain);
//
//				// Retrieve the character to the left of 
//				// the caret, calculate the character's 
//				// width, then subtract the width from the 
//				// current horizontal position of the caret 
//				// to obtain the new position. 
//
//				ch = pchInputBuf[--nCurChar];
//				hdc = GetDC(hwndMain);
//				GetCharWidth32(hdc, ch, ch, &nCharWidth);
//				ReleaseDC(hwndMain, hdc);
//				nCaretPosX = max(nCaretPosX - nCharWidth,
//					0);
//				ShowCaret(hwndMain);
//			}
//			break;
//
//		case VK_RIGHT:  // RIGHT ARROW 
//
//			// Caret moves to the right or, when a carriage 
//			// return is encountered, to the beginning of 
//			// the next line. 
//
//			if (nCurChar < cch)
//			{
//				HideCaret(hwndMain);
//
//				// Retrieve the character to the right of 
//				// the caret. If it's a carriage return, 
//				// position the caret at the beginning of 
//				// the next line. 
//
//				ch = pchInputBuf[nCurChar];
//				if (ch == 0x0D)
//				{
//					nCaretPosX = 0;
//					nCaretPosY++;
//				}
//
//				// If the character isn't a carriage 
//				// return, check to see whether the SHIFT 
//				// key is down. If it is, invert the text 
//				// colors and output the character. 
//
//				else
//				{
//					hdc = GetDC(hwndMain);
//					nVirtKey = GetKeyState(VK_SHIFT);
//					if (nVirtKey & SHIFTED)
//					{
//						crPrevText = SetTextColor(hdc,
//							RGB(255, 255, 255));
//						crPrevBk = SetBkColor(hdc,
//							RGB(0, 0, 0));
//						TextOut(hdc, nCaretPosX,
//							nCaretPosY * dwCharY,
//							&ch, 1);
//						SetTextColor(hdc, crPrevText);
//						SetBkColor(hdc, crPrevBk);
//					}
//
//					// Get the width of the character and 
//					// calculate the new horizontal 
//					// position of the caret. 
//
//					GetCharWidth32(hdc, ch, ch, &nCharWidth);
//					ReleaseDC(hwndMain, hdc);
//					nCaretPosX = nCaretPosX + nCharWidth;
//				}
//				nCurChar++;
//				ShowCaret(hwndMain);
//				break;
//			}
//			break;
//
//		case VK_UP:     // UP ARROW 
//		case VK_DOWN:   // DOWN ARROW 
//			MessageBeep((UINT)-1);
//			return 0;
//
//		case VK_HOME:   // HOME 
//
//			// Set the caret's position to the upper left 
//			// corner of the client area. 
//
//			nCaretPosX = nCaretPosY = 0;
//			nCurChar = 0;
//			break;
//
//		case VK_END:    // END  
//
//			// Move the caret to the end of the text. 
//
//			for (i = 0; i < cch; i++)
//			{
//				// Count the carriage returns and save the 
//				// index of the last one. 
//
//				if (pchInputBuf[i] == 0x0D)
//				{
//					cCR++;
//					nCRIndex = i + 1;
//				}
//			}
//			nCaretPosY = cCR;
//
//			// Copy all text between the last carriage 
//			// return and the end of the keyboard input 
//			// buffer to a temporary buffer. 
//
//			for (i = nCRIndex, j = 0; i < cch; i++, j++)
//				szBuf[j] = pchInputBuf[i];
//			szBuf[j] = TEXT('\0');
//
//			// Retrieve the text extent and use it 
//			// to set the horizontal position of the 
//			// caret. 
//
//			hdc = GetDC(hwndMain);
//			hResult = StringCchLength(szBuf, 128, pcch);
//			if (FAILED(hResult))
//			{
//				// TODO: write error handler
//			}
//			GetTextExtentPoint32(hdc, szBuf, *pcch,
//				&sz);
//			nCaretPosX = sz.cx;
//			ReleaseDC(hwndMain, hdc);
//			nCurChar = cch;
//			break;
//
//		default:
//			break;
//		}
//		SetCaretPos(nCaretPosX, nCaretPosY * dwCharY);
//		break;
//	case WM_LBUTTONDOWN:
//		// here you can add extra check and decide whether to start
//		// the window move or not
//		if (GetCursorPos(&g_OrigCursorPos))
//		{
//			RECT rt;
//			GetWindowRect(hwndMain, &rt);
//			g_OrigWndPos.x = rt.left;
//			g_OrigWndPos.y = rt.top;
//			g_MovingMainWnd = true;
//			SetCapture(hwndMain);
//			SetCursor(LoadCursor(NULL, IDC_SIZEALL));
//		}
//
//		return 0;
//
//		// THE RIGHT WAY OF DOING IT:
//		//*  <- Remove a slash to comment out the good version!
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//		return 0;
//	case WM_CAPTURECHANGED:
//		g_MovingMainWnd = (HWND)lParam == hwndMain;
//		return 0;
//		/**/
//
//		// THE WRONG WAY OF DOING IT:
//		/*  <- Prefix this with a slash to uncomment the bad version!
//		case WM_LBUTTONUP:
//			g_MovingMainWnd = false;
//			ReleaseCapture();
//			return 0;
//		// buggy programs usually do not handle WM_CAPTURECHANGED at all
//		case WM_CAPTURECHANGED:
//			break;
//		/**/
//
//	case WM_MOUSEMOVE:
//		
//		if (g_MovingMainWnd)
//		{
//			POINT pt;
//			if (GetCursorPos(&pt))
//			{
//				    wnd_x = g_OrigWndPos.x +
//					(pt.x - g_OrigCursorPos.x);
//				   wnd_y = g_OrigWndPos.y +
//					(pt.y - g_OrigCursorPos.y);
//				SetWindowPos(hwndMain, NULL, wnd_x,
//					wnd_y, 0, 0, SWP_NOACTIVATE |
//					SWP_NOOWNERZORDER | SWP_NOZORDER |
//					SWP_NOSIZE);
//				
//			}
//			
//		}
//
//		std::cout << g_OrigWndPos.x << ", " << g_OrigWndPos.y;
//		return 0;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hwndMain, &ps);
//
//		// Here your application is laid out.  
//		// For this introduction, we just print out "Hello, World!"  
//		// in the top left corner.  
//		x.Format("%d", Init->MHz());
//		TextOut(hdc,
//			0, 0,
//			MHz + x, _tcslen(MHz + x));
//		// End application-specific layout section.  
//		x.Format("%d", Init->Type());
//		TextOut(hdc,
//			0, 20,
//			Type + x, _tcslen(Type + x));
//		// End application-specific layout section.  
//
//		x.Format("%d", Init->BuffSize());
//		TextOut(hdc,
//			0, 40,
//			BuffSize + x, _tcslen(BuffSize + x));
//
//		TextOut(hdc,
//			0, 60,
//			Init->Name(), _tcslen(Init->Name()));
//
//		
//		TextOut(hdc,
//			0, 80,
//			"Mouse X: " + g_OrigCursorPos.x, _tcslen("Mouse X: " + g_OrigCursorPos.x));
//
//		TextOut(hdc,
//			0, 100,
//			"Mouse Y: " + g_OrigCursorPos.y, _tcslen("Mouse Y: " + g_OrigCursorPos.y));
//
//		// End application-specific layout section.  
//		EndPaint(hwndMain, &ps);
//		
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//
//		// Free the input buffer. 
//
//		GlobalFree((HGLOBAL)pchInputBuf);
//		UnregisterHotKey(hwndMain, 0xAAAA);
//		break;
//
//	default:
//		return DefWindowProc(hwndMain, uMsg, wParam, lParam);
//	}
//	return NULL;
//}
//LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	
//	PAINTSTRUCT ps;
//	HDC hdc;
//	TCHAR MHz[] = _T("MHz: ");
//	TCHAR Type[] = _T("Type: ");
//	TCHAR BuffSize[] = _T("Buff Size: ");
//	CString x;
//
//	switch (message)
//	{
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//
//		// Here your application is laid out.  
//		// For this introduction, we just print out "Hello, World!"  
//		// in the top left corner.  
//		x.Format("%d", Init->MHz());
//		TextOut(hdc,
//			0, 0,
//			MHz + x, _tcslen(MHz + x));
//		// End application-specific layout section.  
//		x.Format("%d", Init->Type());
//		TextOut(hdc,
//			0, 20,
//			Type + x, _tcslen(Type + x));
//		// End application-specific layout section.  
//
//		x.Format("%d", Init->BuffSize());
//		TextOut(hdc,
//			0, 40,
//			BuffSize + x, _tcslen(BuffSize + x));
//
//		TextOut(hdc,
//			0, 60,
//			Init->Name(), _tcslen(Init->Name()));
//		// End application-specific layout section.  
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//		break;
//	}
//
//	return 0;
//}
//


//int _Interface::WinMain(
//	_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPSTR     lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	WNDCLASSEX wClass;
//	ZeroMemory(&wClass, sizeof(WNDCLASSEX));
//	wClass.cbSize = sizeof(WNDCLASSEX);
//	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
//	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wClass.hIcon = NULL;
//	wClass.hIconSm = NULL;
//	wClass.hInstance = hInstance;
//	wClass.lpfnWndProc = (WNDPROC)MainWndProc;
//	wClass.lpszClassName = "Window Class";
//	wClass.lpszMenuName = NULL;
//	wClass.style = CS_HREDRAW | CS_VREDRAW;
//
//	if (!RegisterClassEx(&wClass)) {
//		int nResult = GetLastError();
//		MessageBox(NULL,
//			"Window class creation failed",
//			"Window Class Failed",
//			MB_ICONERROR);
//	}
//	HWND hWnd = CreateWindowEx(0,
//		"Window Class",
//		"Maybe its a game engine",
//		WS_OVERLAPPEDWINDOW,
//		200,
//		200,
//		640,
//		480,
//		NULL,
//		NULL,
//		hInstance,
//		NULL);
//
//	if (!hWnd) {
//		int nResult = GetLastError();
//
//		MessageBox(NULL,
//			"Window creation failed",
//			"Window Creation Failed",
//			MB_ICONERROR);
//	}
//
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//	MSG msg;
//	ZeroMemory(&msg, sizeof(MSG));
//
//	while (GetMessage(&msg, NULL, 0, 0)) {
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//		RedrawWindow(hWnd, 0, 0, RDW_INVALIDATE | RDW_UPDATENOW);
//	}
//	return 0;
//}


//void _Interface::onCreateWindows()
//{
//	
//	WinMain(hIns, hIns, lp, 1);
//}
//

