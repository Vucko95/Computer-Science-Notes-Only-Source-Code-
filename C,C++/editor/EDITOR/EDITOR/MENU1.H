#define TRUE 1
#define U_ARRO 72
#define D_ARRO 80
#define MENU_WIDTH 20
#define MAX_ITEMS 9
char *menu_item[MAX_ITEMS]=
{"New             "
,"Open...       F3"
,"Save...       F2"
,"Save as         "
,"Save all        "
,"Change dir...   "
,"Print           "
,"Dos shell       "
,"Quit            "
};
void message_box();
void display_menu(void);
void draw_box (int left,int top, int width,int height);
char get_code(void);
void menu_action(char *item_name);
int vpos;

void menu_file (void)
{
textbackground(BLUE);
clrscr();
_setcursortype(_NOCURSOR);
while (TRUE)
{
	display_menu();
	switch(get_code())
	{
		case U_ARRO:
		vpos=(vpos>0)?--vpos:MAX_ITEMS-1;
		break;
		case D_ARRO:
		vpos=(vpos<MAX_ITEMS-1)?++vpos:0;
		break;
		case '\r':
		menu_action(menu_item[vpos]);
		break;


	}
}
}

void display_menu()
{
  int j;
  textbackground(WHITE);
  textcolor(BLACK);
  draw_box(5,2,MENU_WIDTH,MAX_ITEMS+3);
  for(j=0;j<MAX_ITEMS;j++)
  {
	if (j==vpos)
	  textbackground(GREEN);
	  gotoxy(5,j+3);
	  cputs(menu_item[j]);
	  textbackground(WHITE);
	}
  }
  void draw_box(int left,int top, int width, int height)
  {
  int j;
  char string[81];
  window(left,top,left+width-1,top+height-1);
  clrscr();
  window(left,top,left+width-1,top+height);
  for (j=1;j<width;j++)
  string[j]='\xC4';
  string[width]='\0';
  string[0]='\xDA';
  string[width-1]='\xBF';
  gotoxy(1,1);
  cputs(string);
  string[0]='\xC0';
  string[width-1]='\xD9';
  gotoxy(1,height);
  cputs(string);
  for (j=2;j<height;j++)
  {
	gotoxy(1,j);
	putch('\xB3');
	gotoxy(width,j);
	putch('\xB3');
  }
  window(3,1,40,15);
  }

  char get_code(void)
  {
  char key;
  if((key=getch())==0)
  return(getch());
  else if(key=='\r')
  return (key);
  else
  return (0);
   }

   void menu_action(char *item_name)
   {
   gotoxy(1,25);
   clrscr();
     if (strcmp(item_name,"New             ")==0)
    exit(0);
   else if(strcmp(item_name,"Open...       F3")==0)
      exit(0);
   else if(strcmp(item_name,"Save...       F2")==0)
      exit(0);
   else if(strcmp(item_name,"Save as         ")==0)
      exit(0);
	 else if(strcmp(item_name,"Save all        ")==0)
      exit(0);
	 else if(strcmp(item_name,"Change dir...   ")==0)
      exit(0);
	 else if(strcmp(item_name,"Print           ")==0)
      exit(0);
	 else if(strcmp(item_name,"Dos shell       ")==0)
      exit(0);
   else if(strcmp(item_name,"Quit            ")==0)
   {
       _setcursortype(_NORMALCURSOR);
       exit(0);
   }
   }

      void make_textbox(struct textbox);
void draw_box_message(int left, int top,int width, int height);
struct textbox
{
	int left;
	int top;
	int width;
	int height;
	char title[40];
	char text[40];
};
void message_box(void)
{
	struct textbox aboutbox={10,3,62,15,"Open Dialogue Box","Enter File name to open"};
	struct textbox errorbox={20,7,40,9,"Error","Sorry! Unable to open the File"};
	_setcursortype(_NOCURSOR);
	textbackground(BLUE);
	clrscr();
	make_textbox(aboutbox);
	getch();
	textbackground(BLUE);
	clrscr();
	make_textbox(errorbox);
	getch();
	_setcursortype(_NOCURSOR);
}
void make_textbox(struct textbox box)
{
   textbackground(LIGHTGRAY);
   textcolor(WHITE);
   draw_box_message(box.left,box.top,box.width,box.height);
   gotoxy(box.left+(box.width-strlen(box.title))/2-1,box.top);
   cputs(box.title);
   gotoxy(box.left+(box.width-strlen(box.text))/2-1,box.top+(box.height-1)/2);
   cputs(box.text);
}
 void draw_box_message(int left, int top, int width, int height)
 {
	int j;
	char string[81];
	window(left,top,left+width-1,top+height-1);
	clrscr();
	window(left,top,left+width-1,top+height);

	for(j=1;j<width-1;j++)
	string[j]='\xC4';
	string[width]='\0';
	string[0]='\xDA';
	string[width-1]='\xBF';
	gotoxy(1,1);
	cputs(string);
	string[0]='\xC0';
	string[width-1]='\xD9';
	gotoxy(1, height);
	cputs(string);
	for(j=2;j<height;j++)
	{
	gotoxy(1,j);
	putch('\xB3');
	gotoxy(width, j);
	putch('\xB3');
	}
	window(1,1,80,25);
 }









