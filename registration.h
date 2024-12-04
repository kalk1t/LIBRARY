
void registration(HWND hwnd) {
	
	x = 0;
	y = 0;
	w = 60;
	h = 360;
	rgstr_dtls = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, 0, 0, 0);
	SendMessageA(rgstr_dtls, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)registration_details_bmp);

	x = 160;
	y = 60;
	w = 300;
	h = 20;
	ncknm = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)nickname, 0, 0);
	

	x = 160;
	y = 105;
	w = 300;
	h = 20;
	psswrd = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)password, 0, 0);
	
	x = 160;
	y = 150;
	w = 300;
	h = 20;
	nm = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)name, 0, 0);

	x = 160;
	y = 205;
	w = 300;
	h = 20;
	lstnm = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)lastname, 0, 0);

	x = 160;
	y = 260;
	w = 20;
	h = 20;
	d = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, (HMENU)letter_d, 0, 0);
	SendMessageA(d, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)d_bmp);
	x = 180;
	dy = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)day, 0, 0);

	x = 200;
	y = 260;
	w = 20;
	h = 20;
	m = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, (HMENU)letter_m, 0, 0);
	SendMessageA(m, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_bmp);
	x = 220;
	mnth = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)month, 0, 0);

	x = 240;
	y = 260;
	w = 20;
	h = 20;
	yea = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, (HMENU)letter_y, 0, 0);
	SendMessageA(yea, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)y_bmp);
	x = 260;
	w = 40;
	yr = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)year, 0, 0);

	x = 160;
	y = 310;
	w = 300;
	h = 20;
	gmail = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)mail, 0, 0);

	x = 200;
	y = 370;
	w = 170;
	h = 20;
	complete_registration = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)complete_reg, 0, 0);
	SendMessageA(complete_registration, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)registration_bmp);


	x = 300;
	y = 500;
	w = 55;
	h = 20;
	back = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)back_from_registration, 0, 0);
	SendMessageA(back, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)back_bmp);

	


}