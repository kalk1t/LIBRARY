#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>



#include "define.h"
#include "main_page.h"
#include "Library_main_win.h"
#include "load_images.h"
#include "registration.h"
#include "console.h"
#include "acc_interface.h"
#include "book_shelf.h"
#include "new_file.h"

#pragma warning(disable:4996 6031 6011 6387)

void main() {

	WNDCLASSA lbr={ 0 };

	lbr.hbrBackground = CreateSolidBrush(RGB(0, 221, 0));
	lbr.lpszClassName = "library";
	lbr.lpfnWndProc = Library_main_win;
	DWORD style = WS_VISIBLE
		| WS_OVERLAPPED
		| WS_CAPTION
		| WS_SYSMENU
		| WS_CLIPSIBLINGS
		|WS_CLIPCHILDREN
		;
	if (!RegisterClassA(&lbr)) {
		return;
	}
		

	X = 50;
	Y = 50;
	W = 1100;
	H = 645;
	CreateWindowA(lbr.lpszClassName, "Library", style, X, Y, W, H, 0, 0, 0, 0);
	


	//SetWindowLongPtr(firstWin, GWL_WNDPROC, (LONG)Library_main_win);
	//CallWindowProcA(Library_main_win, firstWin, WPARAM, LPARAM);
	//SendMessageA(firstWin, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)background_bmp);
	
	//SetWindowLongA(firstWin, GWL_WNDPROC, (long)Library_main_win);
	//SendMessageA(firstWin, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)background_bmp);
	
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessageA(&msg);
		TranslateMessage(&msg);
	}

}



void TogglePasswordStyle(HWND hEdit, BOOL enable) {
	RECT rc = { 0 };
	rc.left = 10;
	rc.right = 100;
	rc.top = 100;
	rc.bottom = 100;
	LONG currentStyle = GetWindowLong(hEdit, GWL_STYLE);

	if (enable) {
		SetWindowLong(hEdit, GWL_STYLE, currentStyle | ES_PASSWORD); // Add style
	}
	else {
		SetWindowLong(hEdit, GWL_STYLE, currentStyle & ~ES_PASSWORD); // Remove style
	}
	RedrawWindow(Psswrd, &rc, 0, 0);
	//SetWindowPos(hEdit, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}