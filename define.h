#define cnsl 7
#define cnsl_button 8

#define usrn 11
#define pswr 12
#define log_in 13
#define reg 14
#define see_password 15
#define sign_out 16
#define your_lbr 17
#define x_btn_ 18
#define book_shelf_ 19
#define new_file_ 20
#define save_btn_ 21
#define save_edited_file_btn_ 22

#define new_file_text 600
#define file_name_ 601
#define paper 602
#define f_nm 603
#define ppr_ 604


#define max_text_length 2048


#define password 23
#define name 24
#define lastname 25
#define day 26
#define letter_d 27
#define month 28
#define letter_m 29
#define year 30
#define letter_y 31
#define mail 32
#define complete_reg 33
#define nickname 34

#define back_from_registration 41

#define max_length 24

int saved = 0;
//char str_fn[max_length] = "";
typedef long(_stdcall* WNDPROC)(HWND, unsigned int, WPARAM, LPARAM);

char Username[max_length] = "";
static char fname[max_length] = "registeredAccounts.txt";



struct filename {
	char Fname[max_length] = "";
};

struct Account {
	char Nickname[max_length];
	char Password[max_length];
	char Name[max_length];
	char Lastname[max_length];
	char Day[max_length];
	char Month[max_length];
	char Year[max_length];
	char Mail[2 * max_length];
	char File_name[max_length]="\0";
	int saved_file = false;

};



int X, Y, W, H;
int x, y, w, h;

HBITMAP background_bmp = 0, password_bmp = 0, username_bmp = 0, sign_in_bmp = 0, registration_bmp = 0, registration_details_bmp = 0, d_bmp = 0, m_bmp = 0, y_bmp = 0;
HBITMAP back_bmp, account_interface_bmp,your_library_bmp,sign_out_bmp,book_shelf_bmp,x_btn_bmp,new_file_bmp,save_btn_bmp,paper_bmp;
HDC memory_dc = 0;
HDC dc = 0;
HWND Usr, Usrnm, Psw, Psswrd, sign_in, registr;//main page handlers
HWND rgstr_dtls, ncknm, psswrd, nm, lstnm, dy, d, mnth, m, yr, yea, gmail, complete_registration, back;//registration details' handlers
HWND cons, acc_interface, info_1, info_2, info_3, info_4, see_pasword,your_library,sign_Out,hBook_shelf,x_btn,new_file_btn,new_file,save_btn,file_name,paper_btn;
HWND created_file_name, save_edited_file_,ppr,hSavedPaper;

filename f_1;

void registration(HWND);
void main_page(HWND);
void LoadImages();
void console(HWND);
void account_interface(HWND,Account);
void your_lbrry(HWND);
void save_file(HWND);
void book_shelf(HWND,Account);
void _new_file(HWND);
void created_file(HWND,int,int,int);
void open_paper(HWND,Account);
void save_edited_file(HWND, Account);
void open_saved_file(HWND, Account);


long CALLBACK Library_main_win(HWND, unsigned int, WPARAM, LPARAM);
void TogglePasswordStyle(HWND hEdit, BOOL enable);