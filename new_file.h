void _new_file(HWND hwnd) {
	if (new_file) {
		ShowWindow(new_file, SHOW_OPENWINDOW);
	}
	else {
		x = 400;
		y = 200;
		w = 300;
		h = 300;
		new_file = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE, x, y, w, h, hwnd, (HMENU)new_file_text, 0, 0);
	}

	if (save_btn) {
		ShowWindow(save_btn, SHOW_OPENWINDOW);
	}
	else {
		x = 450;
		y = 540;
		w = 70;
		h = 21;
		save_btn = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)save_btn_, 0, 0);
		SendMessageA(save_btn, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)save_btn_bmp);
	}

	if (file_name) {
		ShowWindow(file_name, SHOW_OPENWINDOW);
	}
	else {
		x = 400;
		y = 170;
		w = 100;
		h = 20;
		file_name = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)file_name_, 0, 0);
	}
}

void save_file(HWND hwnd) {
	char max_text[max_text_length] = "";

	char str[max_length] = ".txt";
	char fileName[max_length] = "";
	SendDlgItemMessageA(hwnd, new_file_text, WM_GETTEXT, max_text_length, (WPARAM)max_text);
	SendDlgItemMessageA(hwnd, file_name_, WM_GETTEXT, max_length, (WPARAM)fileName);
	strcat_s(fileName, str);
	strcat_s(f_1.Fname, fileName);


	FILE* newFile;
	errno_t errn;

	errn = fopen_s(&newFile, fileName, "a");
	if (newFile > 0) {
		if (fwrite(max_text, sizeof(max_text), 1, newFile) != 1) {
			return;
		}
		MessageBoxA(hwnd, "Successfully created new file", "Great", MB_OK);
		ShowWindow(new_file, HIDE_WINDOW);
		ShowWindow(save_btn, HIDE_WINDOW);
		ShowWindow(file_name, HIDE_WINDOW);
		ShowWindow(hBook_shelf, HIDE_WINDOW);
		ShowWindow(x_btn, HIDE_WINDOW);
		ShowWindow(new_file_btn, HIDE_WINDOW);
		saved++;
	}
	else {
		MessageBoxA(hwnd, "Error opening file", "error", MB_OK);
	}
	fclose(newFile);
	errn = 0;
	newFile = 0;
	FILE* nf;
	errno_t errn_2;
	struct Account* wc = (struct Account*)malloc(sizeof(struct Account));
	size_t hld;

	int k = 0;
	errn = fopen_s(&newFile, fname, "r");
	errn_2 = fopen_s(&nf, "temp.txt", "w");
	if (newFile > 0) {
		while (_eof(errn) != 0) {
			
			fread(wc, sizeof(struct Account), 1, newFile);
			if (strstr(Username, wc->Nickname)) {
				SendDlgItemMessageA(hwnd, file_name_, WM_GETTEXT, max_length, (LPARAM)wc->File_name);
				char str[5] = ".txt";
				strcat_s(wc->File_name, str);
				wc->saved_file = true;
				saved++;
				fwrite(wc, sizeof(struct Account), 1, nf);
				break;
			}
			else {
				k++;
			}


			if (k == max_length) {
				MessageBoxA(hwnd, "couldnt find a file", "", MB_OK);
				break;
			}
		}
		
	}
	else {
		perror("couldnt open a file");
	}


	fclose(newFile);
	fclose(nf);

	remove(fname);
	rename("temp.txt", fname);

	errn = 0;
	newFile = 0;

}

void save_edited_file(HWND hwnd, Account acc) {
	char max_text[max_text_length] = "";

	char fn[max_length] = "tmp.txt";

	FILE* newFile;
	errno_t errn;

	SendDlgItemMessageA(hwnd, ppr_, WM_GETTEXT, max_text_length, (LPARAM)max_text);

	errn = fopen_s(&newFile, fn, "a+");
	if (newFile > 0) {
		if (fwrite(max_text, strlen(max_text), 1, newFile) != 1) {
			return;
		}
		MessageBoxA(hwnd, "Successfully saved a file", "Great", MB_OK);
		ShowWindow(new_file, HIDE_WINDOW);
		ShowWindow(save_edited_file_, HIDE_WINDOW);
		//ShowWindow(hBook_shelf, HIDE_WINDOW);
		//ShowWindow(x_btn, HIDE_WINDOW);
		ShowWindow(new_file_btn, SHOW_OPENWINDOW);
		//ShowWindow(paper_btn, HIDE_WINDOW);
		ShowWindow(ppr, HIDE_WINDOW);
		ShowWindow(hSavedPaper, HIDE_WINDOW);
		
	}
	else {
		MessageBoxA(hwnd, "Error opening file", "error", MB_OK);
	}
	fclose(newFile);
	errn = 0;
	newFile = 0;

	remove(acc.File_name);
	rename(fn, acc.File_name);
}

void open_saved_file(HWND hwnd, Account acc) {
	char txt[max_text_length] = "";
	FILE* f;
	errno_t err;
	size_t hl;

	err = fopen_s(&f, acc.File_name, "r");
	if (f > 0) {


		hl = fread(txt, sizeof(txt), 1, f);

		if (hSavedPaper) {
			ShowWindow(hSavedPaper, SHOW_OPENWINDOW);
		}
		else {
			x = 400;
			y = 200;
			w = 300;
			h = 300;
			hSavedPaper = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE, x, y, w, h, hwnd, (HMENU)ppr_, 0, 0);
			SendDlgItemMessageA(hwnd, ppr_, WM_SETTEXT, strlen(txt), (LPARAM)txt);
		}
		DWORD er;
		er=GetLastError();

		if (save_edited_file_) {
			ShowWindow(save_edited_file_,SHOW_OPENWINDOW);
		}
		else {
			x = 450;
			y = 540;
			w = 70;
			h = 21;
			save_edited_file_ = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_BITMAP, x, y, w, h, hwnd, (HMENU)save_edited_file_btn_, 0, 0);
			SendMessageA(save_edited_file_, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)save_btn_bmp);
		}
	}
	else {
		perror("opening file");
	}
	fclose(f);
}