void LoadImages() {
	background_bmp = (HBITMAP)LoadImageA(0, "bitmaps//background.bmp", IMAGE_BITMAP, 1100, 645, LR_LOADFROMFILE);


	password_bmp= (HBITMAP)LoadImageA(0, "bitmaps//password.bmp", IMAGE_BITMAP, 200, 50, LR_LOADFROMFILE);
	username_bmp = (HBITMAP)LoadImageA(0, "bitmaps//username.bmp", IMAGE_BITMAP, 200, 50, LR_LOADFROMFILE);
	sign_in_bmp= (HBITMAP)LoadImageA(0, "bitmaps//sign_in.bmp", IMAGE_BITMAP, 150,30, LR_LOADFROMFILE);
	registration_bmp= (HBITMAP)LoadImageA(0, "bitmaps//registration.bmp", IMAGE_BITMAP, 170, 20, LR_LOADFROMFILE);


	registration_details_bmp = (HBITMAP)LoadImageA(0, "bitmaps//registration_details.bmp", IMAGE_BITMAP, 160, 360, LR_LOADFROMFILE);
	d_bmp= (HBITMAP)LoadImageA(0, "bitmaps//d.bmp", IMAGE_BITMAP, 20, 20, LR_LOADFROMFILE);
	m_bmp= (HBITMAP)LoadImageA(0, "bitmaps//m.bmp", IMAGE_BITMAP, 20, 20, LR_LOADFROMFILE);
	y_bmp = (HBITMAP)LoadImageA(0, "bitmaps//y.bmp", IMAGE_BITMAP, 20, 20, LR_LOADFROMFILE);
	back_bmp = (HBITMAP)LoadImageA(0, "bitmaps//back.bmp", IMAGE_BITMAP, 70, 20, LR_LOADFROMFILE);
	account_interface_bmp= (HBITMAP)LoadImageA(0, "bitmaps//account_interface_1.bmp", IMAGE_BITMAP, 350, 645, LR_LOADFROMFILE);
	your_library_bmp = (HBITMAP)LoadImageA(0, "bitmaps//collection.bmp", IMAGE_BITMAP, 230, 50, LR_LOADFROMFILE);
	sign_out_bmp = (HBITMAP)LoadImageA(0, "bitmaps//sign_out.bmp", IMAGE_BITMAP, 80, 20, LR_LOADFROMFILE);
	book_shelf_bmp = (HBITMAP)LoadImageA(0, "bitmaps//book_shelf.bmp", IMAGE_BITMAP,340, 645, LR_LOADFROMFILE);
	x_btn_bmp = (HBITMAP)LoadImageA(0, "bitmaps//x_btn.bmp", IMAGE_BITMAP, 30, 30, LR_LOADFROMFILE);
	new_file_bmp = (HBITMAP)LoadImageA(0, "bitmaps//new_file.bmp", IMAGE_BITMAP, 100, 21, LR_LOADFROMFILE);
	save_btn_bmp = (HBITMAP)LoadImageA(0, "bitmaps//save_btn.bmp", IMAGE_BITMAP, 80, 21, LR_LOADFROMFILE);
	paper_bmp = (HBITMAP)LoadImageA(0, "bitmaps//paper.bmp", IMAGE_BITMAP, 30, 50, LR_LOADFROMFILE);
}