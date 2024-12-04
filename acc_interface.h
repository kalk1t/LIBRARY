#pragma once

void account_interface(HWND hwnd,Account acc) {
	f_1.Fname == acc.File_name;

	x = 0;
	y = 0;
	w = 350;
	h = 645;
	acc_interface = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, (HMENU)999, 0, 0);
	SendMessageA(acc_interface, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)account_interface_bmp);

	x = 100;
	y = 22;
	w = 100;
	h = 20;
	CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_READONLY, x, y, w, h, acc_interface, (HMENU)998, 0, 0);
	SendDlgItemMessageA(acc_interface, 998, WM_SETTEXT, max_length, (LPARAM)acc.Name);

	x = 100;
	y = 80;
	w = 100;
	h = 20;
	CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_READONLY, x, y, w, h, acc_interface, (HMENU)997, 0, 0);
	SendDlgItemMessageA(acc_interface, 997, WM_SETTEXT, max_length, (LPARAM)acc.Lastname);

	x = 100;
	y = 182;
	w = 250;
	h = 20;
	CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_READONLY, x, y, w, h, acc_interface, (HMENU)996, 0,  0);
	SendDlgItemMessageA(acc_interface, 996, WM_SETTEXT, max_length, (LPARAM)acc.Mail);

	x = 100;
	y = 130;
	w = 150;
	h = 20;
	CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_READONLY, x, y, w, h, acc_interface, (HMENU)995, 0, 0);
	SendDlgItemMessageA(acc_interface, 995,EM_REPLACESEL, max_length, (LPARAM)acc.Day);
	SendDlgItemMessageA(acc_interface, 995, EM_REPLACESEL, max_length, (LPARAM)"/");
	SendDlgItemMessageA(acc_interface, 995, EM_REPLACESEL, max_length, (LPARAM)acc.Month);
	SendDlgItemMessageA(acc_interface, 995, EM_REPLACESEL, max_length, (LPARAM)"/");
	SendDlgItemMessageA(acc_interface, 995, EM_REPLACESEL, max_length, (LPARAM)acc.Year);

	your_lbrry(hwnd);

}

void your_lbrry(HWND hwnd) {

	x = 60;
	y = 330;
	w = 230;
	h = 50;

	your_library = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)your_lbr, 0, 0);
	SendMessageA(your_library, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)your_library_bmp);

	x = 250;
	y = 570;
	w = 80;
	h = 20;
	sign_Out = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)sign_out, 0, 0);
	SendMessageA(sign_Out, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)sign_out_bmp);
}