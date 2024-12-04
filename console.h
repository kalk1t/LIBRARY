void console(HWND hwnd) {
	x = 700;
	y = 200;
	w = 300;
	h = 200;
	cons=CreateWindowA("edit", "", WS_CHILD | WS_VISIBLE|ES_MULTILINE, x, y, w, h, hwnd, (HMENU)cnsl, 0, 0);

	x = 700;
	y = 50;
	w = 50;
	h = 50;
	CreateWindowA("button", "console", WS_CHILD | WS_VISIBLE , x, y, w, h, hwnd, (HMENU)cnsl_button, 0, 0);
}