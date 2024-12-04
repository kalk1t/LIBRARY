
void main_page(HWND hwnd) {
	


	x = 400;
	y = 180;
	w = 200;
	h = 50;
	Usr = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, 0, 0, 0);
	SendMessageA(Usr, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)username_bmp);
	

	x = 400;
	y = 230;
	w = 100;
	h = 20;
	Usrnm=CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)usrn, 0, 0);

	x = 400;
	y = 250;
	w = 200;
	h = 50;
	Psw = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, 0, 0, 0);
	SendMessageA(Psw, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)password_bmp);
	x = 400;
	y = 300;
	w = 100;
	h = 20;
	Psswrd = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD|ES_PASSWORD, x, y, w, h, hwnd, (HMENU)pswr, 0, 0);

/*
	x = 515;
	y = 305;
	w = 10;
	h = 10;
	see_pasword=CreateWindowA("button","", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)see_password, 0, 0);
	*/

	x = 400;
	y = 330;
	w = 150;
	h = 30;
	sign_in=CreateWindowA("button", "", WS_VISIBLE | WS_CHILD|BS_BITMAP, x, y, w, h,hwnd, (HMENU)log_in, 0, 0);
	SendMessageA(sign_in, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)sign_in_bmp);

	x = 400;
	y = 370;
	w = 170;
	h = 20;
	registr=CreateWindowA("button", "", WS_VISIBLE | WS_CHILD|BS_BITMAP, x, y, w, h, hwnd, (HMENU)reg, 0, 0);
	SendMessageA(registr, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)registration_bmp);
	
}