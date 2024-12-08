void book_shelf(HWND hwnd,Account acc) {
	
	if (hBook_shelf) {
		ShowWindow(hBook_shelf,SHOW_OPENWINDOW);
	}
	else {
		x = 760;
		y = 0;
		w = 340;
		h = 645;
		hBook_shelf = CreateWindowA("static", "", WS_VISIBLE | WS_CHILD | SS_BITMAP, x, y, w, h, hwnd, (HMENU)book_shelf_, 0, 0);
		SendMessageA(hBook_shelf, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)book_shelf_bmp);
	}
	if (x_btn) {
		ShowWindow(x_btn, SHOW_OPENWINDOW);
	}
	else {
		x = 1050;
		y = 10;
		w = 30;
		h = 30;
		x_btn = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)x_btn_, 0, 0);
		SendMessageA(x_btn, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)x_btn_bmp);
	}


	if (new_file_btn) {
		ShowWindow(new_file_btn, SHOW_OPENWINDOW);
	}
	else {
		x = 400;
		y = 60;
		w = 100;
		h = 21;
		new_file_btn = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)new_file_, 0, 0);
		SendMessageA(new_file_btn, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)new_file_bmp);

	}


		if (acc.saved_file) {
		created_file(hwnd,1010,70,paper);
		}
		
		if (saved == 2) {
			created_file(hwnd,560,70,paper);
		}
		

}


void created_file(HWND hwnd,int xCrd,int yCrd,int hMen) {
	
	if (paper_btn) {
		ShowWindow(paper_btn, SHOW_OPENWINDOW);
	}
	else {
		//x = 1010;
		//y = 70;
		w = 30;
		h = 50;
		paper_btn = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, xCrd, yCrd, w, h, hwnd, (HMENU)hMen, 0, 0);
		SendMessageA(paper_btn, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)paper_bmp);
	}
}

void open_paper(HWND hwnd,Account acc) {
	FILE* fl;
	errno_t err;
	size_t h1;
	char text[max_text_length] = "";
	

	
	err = fopen_s(&fl, acc.File_name, "r");
	if (fl==0 ){
		perror("error opening Fname file");
	}
			h1 = fread(text, sizeof(text), 1, fl);	
			x = 400;
			y = 200;
			w = 300;
			h = 300;
			new_file = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE, x, y, w, h, hwnd, (HMENU)ppr_, 0, 0);
			SendDlgItemMessageA(hwnd, ppr_, WM_SETTEXT, max_text_length, (LPARAM)text);

			x = 450;
			y = 540;
			w = 70;
			h = 21;
			save_edited_file_= CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)save_edited_file_btn_, 0, 0);
			SendMessageA(save_edited_file_, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)save_btn_bmp);

	fclose(fl);
	h1 = 0;

}