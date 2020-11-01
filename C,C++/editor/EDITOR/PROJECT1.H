#include<help.h>
#include<open.h>
#define LEFT 2
#define TOP 3
#define RIGHT 77
#define BOT 22
#define WIDTH (RIGHT-LEFT+1)
#define HEIGHT (BOT-TOP+1)
#define TRUE 1
#define ESC 27
#define L_ARRO 75
# define R_ARRO 77
#define U_ARRO 72
#define D_ARRO 80
#define INS 82
#define DEL 83
#define ALT_H 35
#define ALT_L 38
#define ALT_U 22
#define ALT_F 33
#define ALT_G 34
#define ALT_E 18
#define ALT_S 31
#define ALT_R 19
#define ALT_C 46
#define BKSP 8
#define ENTER 13
#define ALT_T 20
int buff [WIDTH][HEIGHT];
void  *m[50][50];
void project1()
{
int mx,my;
union REGS regis;
regis.x.ax = 0;
int86(0x33,&regis,&regis);
regis.x.ax = 1;
int86(0x33,&regis,&regis);

textmode(C80);
window(1,1,80,1);
textcolor(0);
textbackground(WHITE);
clrscr();
cout<<"  ð   File  Edit  Search  Run  Compile  Debug  Project  Option   Window  Help   ";

//////////////////////////Window starts/////////////////////////////////
window(1,2,80,24);
textcolor(WHITE);
textbackground(BLUE);
clrscr();
textcolor(10);
clrscr();
cout<<"ÉÍÍÍ[þ]ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ C:SRZ.cpp ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ3Í[ ]ÍÍ»"<<endl;
cout<<"º                                                                             "<<endl;
cout<<"º								              °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             þ"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             °"<<endl;
cout<<"º                                                                             "<<endl;
cout<<"ÈÍÍÍ34:23ÍÍÍÍÍÍþ°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°ÄÙ"<<endl;


window(1,25,80,25);
textcolor(BLACK);
textbackground(WHITE);
clrscr();
cout<<" F1 Help  F2 Save  F3 Open  ALT-F9 Compile  F10 Menue";

	{

////////////////Start of the Editor///////////////////////
int x,y;
char key,keyb;
textcolor(WHITE);


textbackground(BLUE);
x=2;y=2;
gotoxy(2,2);
window(LEFT,TOP,RIGHT,BOT);

while(key!=ESC)
{
	if(kbhit())
	{
		key =  getch();

	if(key==0)
	{
		switch(getch())
		{
			case ALT_F:
			menu_file();
			break;
			case 61:
			gettext(1,1,80,25,m);
			{openfile();
			getch();
			}
			puttext(1,1,80,25,m);
			gotoxy(1,1);
			break;
			case 60:
			gettext(1,1,80,25,m);
			{about();
			getch();
			}
			puttext(1,1,80,25,m);
			gotoxy(x,y);
			break;
			case ALT_E:
			menu_edit();
			break;
			case ALT_S:
			menu_search();
			break;
			case ALT_R:
			menu_run();

			break;
			case ALT_C:
			menu_compile();
			break;
			case 59:
			gettext(1,1,80,25,m);
			{help();
			getch();}
			puttext(1,1,80,25,m);
			gotoxy(x,y);
			break;
			case L_ARRO:
			if (x>1)
				gotoxy(--x,y);
			break;
			case R_ARRO:
			if(x<WIDTH)
				gotoxy(++x,y);
			break;
			case U_ARRO:
			if (y>1)
				gotoxy(x,--y);
			break;
			case D_ARRO:
			if (y<HEIGHT)
				gotoxy(x,++y);
			break;
			case INS:
			gettext(LEFT,TOP,RIGHT,BOT,buff);
			gotoxy(1,++y);
			insline();

			break;
			case DEL:
			gettext(LEFT,TOP,RIGHT,BOT,buff);
			gotoxy(1,y);
			delline();
			break;
			case ALT_H:
			highvideo();
			break;
			case ALT_L:
			lowvideo();
			break;
			case ALT_T:
			textcolor(getch()-'0');
			break;
			case ALT_U:
			puttext(LEFT,TOP,RIGHT,BOT,buff);
			break;

			}
		}

			else
		{
			putch(key);
			x=wherex();
			y=wherey();
		}
       }	else

	{
		regis.x.ax=3;
		int86(0x33,&regis,&regis);
		mx=regis.x.cx;
		my=regis.x.dx;
		if (regis.x.bx&1)
		{
			if (mx>=30&& mx<80 && my>=0&&my<5)
			{
				menu_file();
				break;
			}
			if (mx>=83&& mx<130 &&my>=0&&my<5)
			{
				menu_edit();
				break;
			}
			if(mx>=130&& mx<200 &&my>=0&&my<5)
			{
				menu_search();
			}
			if(mx>=200&&mx<230&&my>=0&&my<5)
			{
				menu_run();
			}
		}
	}
}
exit(0);
getch();
}
}

