
long CALLBACK Library_main_win(HWND hwnd, unsigned int message, WPARAM wp, LPARAM lp) {

	FILE* file;
	static struct Account* buf = (struct Account*)malloc(sizeof(struct Account));
	char str[max_length] = "";
	 char Pasword[max_length] = "";
	errno_t  err;
	size_t holder;
	char max_text[max_text_length] = "";


	switch (message) {
	case WM_CREATE:
	{
		Account acc;
		LoadImages();
		//registration(hwnd);
		//console(hwnd);
		main_page(hwnd);
		//account_interface(hwnd);
		memory_dc = CreateCompatibleDC(0);
		//registration(hwnd);
	}
	break;


	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		dc=BeginPaint(hwnd, &ps);
		SelectObject(memory_dc, background_bmp);
		BitBlt(dc, 0, 0, 1100, 645, memory_dc, 0, 0, SRCCOPY);
		EndPaint(hwnd, &ps);
	}
	break;

	case WM_COMMAND:
	{
		switch ((short)wp) {
		case log_in:
		{
			SendDlgItemMessageA(hwnd, usrn, WM_GETTEXT, max_length, (LPARAM)Username);
			char str1 = Username[0];
			if (str1 == 0) {
				MessageBoxA(hwnd, "NICKNAME OR PASSWORD CAN'T BE EMPTY!", "Get back", MB_OK);
				break;
			}
			SendDlgItemMessageA(hwnd, pswr, WM_GETTEXT, max_length, (LPARAM)Pasword);
			char str2 = Pasword[0];
			if (str2 == 0) {
				MessageBoxA(hwnd, "NICKNAME OR PASSWORD CAN'T BE EMPTY!", "Get back", MB_OK);
				break;
			}


			
			err = fopen_s(&file, fname, "r");
			if (file > 0) {
				int k = 0;
				//fread(buf, sizeof(struct Account), 2, file);
				while (_eof(err) != 0) {
					holder = fread(buf, sizeof(struct Account), 1, file);
					if (strstr(Username, buf->Nickname) && strstr(Pasword, buf->Password)) {
						MessageBoxA(hwnd, "COMPLETED SIGNING IN", ";)", MB_OK);
						ShowWindow(Usr, HIDE_WINDOW);
						ShowWindow(Usrnm, HIDE_WINDOW);
						ShowWindow(Psw, HIDE_WINDOW);
						ShowWindow(Psswrd, HIDE_WINDOW);
						ShowWindow(sign_in, HIDE_WINDOW);
						ShowWindow(registr, HIDE_WINDOW);
						ShowWindow(see_pasword, HIDE_WINDOW);

						

						account_interface(hwnd,(struct Account)* buf);
						
						if (buf->File_name == "\0") {
							buf->saved_file = false;
						}
						break;
					}
					else {
						k++;
					}
					if (k == max_length) {
						MessageBoxA(hwnd, "NICKNAME OR PASSWORD IS INCORRECT!", "Get back", MB_OK);
						SendDlgItemMessageA(hwnd, cnsl, WM_SETTEXT, max_length, (LPARAM)"Password or Nickname is incorrect!");
						break;
					}


				}

			}
		
			else {
				perror("error opening file");
			}

			fclose(file);
			//free(buf);
			err = 0;
			file = 0;
			
		}
		break;

		case reg:
		{//Usr, Usrnm, Psw, Psswrd, sign_in, registr
			ShowWindow(Usr, HIDE_WINDOW);
			ShowWindow(Usrnm, HIDE_WINDOW);
			ShowWindow(Psw, HIDE_WINDOW);
			ShowWindow(Psswrd, HIDE_WINDOW);
			ShowWindow(sign_in, HIDE_WINDOW);
			ShowWindow(registr, HIDE_WINDOW);
			registration(hwnd);
		}
		break;
		case complete_reg:
		{
			SendDlgItemMessageA(hwnd, nickname, WM_GETTEXT, max_length, (LPARAM)Username);
			struct Account* wc = (struct Account*)malloc(sizeof(struct Account));
			err = fopen_s(&file, fname, "r");
			BOOL excisted = false;
			if (file > 0) {
				int k = 0;
				//fread(buf, sizeof(struct Account), 2, file);
				while (_eof(err) != 0) {
					holder = fread(wc, sizeof(struct Account), 1, file);
					if (strstr(Username, wc->Nickname)) {

						MessageBoxA(hwnd, "NICKNAME ALREADY EXCISTED", "Get back", MB_OK);
						excisted = true;
						break;
					}
					else {
						k++;
					}
					if (k == max_length) {
						break;
					}
				}
			}
			fclose(file);
			file = 0;
			free(wc);

			if (excisted) {
				break;
			}



					struct Account* nw = (struct Account*)malloc(sizeof(struct Account));


					SendDlgItemMessageA(hwnd, nickname, WM_GETTEXT, max_length, (LPARAM)nw->Nickname);
					sprintf_s(Username, nw->Nickname);
					SendDlgItemMessageA(hwnd, password, WM_GETTEXT, max_length, (LPARAM)nw->Password);
					sprintf_s(Pasword, nw->Password);
					SendDlgItemMessageA(hwnd, name, WM_GETTEXT, max_length, (LPARAM)nw->Name);
					SendDlgItemMessageA(hwnd, lastname, WM_GETTEXT, max_length, (LPARAM)nw->Lastname);
					SendDlgItemMessageA(hwnd, mail, WM_GETTEXT, 2 * max_length, (LPARAM)nw->Mail);
					SendDlgItemMessageA(hwnd, day, WM_GETTEXT, max_length, (LPARAM)nw->Day);
					SendDlgItemMessageA(hwnd, month, WM_GETTEXT, max_length, (LPARAM)nw->Month);
					SendDlgItemMessageA(hwnd, year, WM_GETTEXT, max_length, (LPARAM)nw->Year);
					SendDlgItemMessageA(hwnd, year, WM_GETTEXT, max_length, (LPARAM)nw->File_name);
					char str[5] = ".txt";
					strcat_s(wc->File_name, str);

					nw->saved_file = false;
					if (strstr(nw->Password, "!") == 0) {
						MessageBoxA(hwnd, "Password must contain at least one '!' exclamation point", "TRY AGAIN", MB_OK);
						return 121;
					};

					err = fopen_s(&file, fname, "a");

					if (file > 0) {
						if (fwrite(nw, sizeof(Account), 1, file) != 1) {
							return 24;
						}

						MessageBoxA(hwnd, "Successfully registered the account", "Great!", MB_OK);
						fclose(file);
					}
					else {
						MessageBoxA(hwnd, "Error opening file", "error", MB_OK);
					}
					free(nw);
					err = 0;
					file = 0;

					ShowWindow(rgstr_dtls, HIDE_WINDOW);
					ShowWindow(ncknm, HIDE_WINDOW);
					ShowWindow(psswrd, HIDE_WINDOW);
					ShowWindow(nm, HIDE_WINDOW);
					ShowWindow(lstnm, HIDE_WINDOW);
					ShowWindow(d, HIDE_WINDOW);
					ShowWindow(dy, HIDE_WINDOW);
					ShowWindow(m, HIDE_WINDOW);
					ShowWindow(mnth, HIDE_WINDOW);
					ShowWindow(yea, HIDE_WINDOW);
					ShowWindow(yr, HIDE_WINDOW);
					ShowWindow(gmail, HIDE_WINDOW);
					ShowWindow(complete_registration, HIDE_WINDOW);
					ShowWindow(back, HIDE_WINDOW);

					main_page(hwnd);
				}
	
		break;
		case new_file_:
		{
			_new_file(hwnd);
			ShowWindow(new_file_btn, HIDE_WINDOW);
		}
		break;
		case x_btn_:
		{
			ShowWindow(hBook_shelf, HIDE_WINDOW);
			ShowWindow(x_btn, HIDE_WINDOW);
			ShowWindow(new_file_btn, HIDE_WINDOW);
			ShowWindow(hSavedPaper, HIDE_WINDOW);
			ShowWindow(save_btn, HIDE_WINDOW);
			ShowWindow(paper_btn, HIDE_WINDOW);
			ShowWindow(file_name, HIDE_WINDOW);
			ShowWindow(created_file_name, HIDE_WINDOW);
			ShowWindow(save_edited_file_, HIDE_WINDOW);
		}
		break;
		case save_btn_:
		{
			save_file(hwnd);
			
			
		}
		break;
		case save_edited_file_btn_:
		{
			save_edited_file(hwnd, (struct Account)*buf);
		}
		break;
		case sign_out:
		{
			ShowWindow(acc_interface, HIDE_WINDOW);
			ShowWindow(sign_Out, HIDE_WINDOW);
			ShowWindow(your_library, HIDE_WINDOW);
			ShowWindow(hBook_shelf, HIDE_WINDOW);
			ShowWindow(x_btn, HIDE_WINDOW);
			ShowWindow(new_file_btn, HIDE_WINDOW);
			ShowWindow(new_file, HIDE_WINDOW);
			ShowWindow(save_edited_file_, HIDE_WINDOW);
			main_page(hwnd);
		}
		break;
		case your_lbr:
		{
			
			book_shelf(hwnd,(struct Account)*buf);
		
		}
		break;
		/*
		case see_password:
		{
			TogglePasswordStyle(Psswrd, FALSE);
		}
		break;
		*/
		case paper:
		{
			if (buf->saved_file) {
				open_saved_file(hwnd, (struct Account)*buf);
				ShowWindow(new_file_btn, HIDE_WINDOW);
			}
			else {
					open_paper(hwnd, (struct Account)*buf);
			}
			
		}
		case cnsl_button:
		{
			
		}
		break;
		case back_from_registration:
		{
			ShowWindow(rgstr_dtls, HIDE_WINDOW);
			ShowWindow(ncknm, HIDE_WINDOW);
			ShowWindow(psswrd, HIDE_WINDOW);
			ShowWindow(nm, HIDE_WINDOW);
			ShowWindow(lstnm, HIDE_WINDOW);
			ShowWindow(d, HIDE_WINDOW);
			ShowWindow(dy, HIDE_WINDOW);
			ShowWindow(m, HIDE_WINDOW);
			ShowWindow(mnth, HIDE_WINDOW);
			ShowWindow(yea, HIDE_WINDOW);
			ShowWindow(yr, HIDE_WINDOW);
			ShowWindow(gmail, HIDE_WINDOW);
			ShowWindow(complete_registration, HIDE_WINDOW);
			ShowWindow(back, HIDE_WINDOW);
			if (paper) {
				ShowWindow(paper_btn, HIDE_WINDOW);
			}

			main_page(hwnd);
		}
		break;
		//command //buttons
		}
	}
	break;


	case WM_DESTROY:
	{
		free(buf);
		PostQuitMessage(9);
		exit(9);

	}
	break;

	}


	return DefWindowProc(hwnd, message, wp, lp);
}
