#define TRUE 1
#define U_ARRO 72
#define D_ARRO 80
#define MENU_WIDTH_SEARCH 29
#define MAX_ITEMS_SEARCH 7
char *menu_item_search[MAX_ITEMS_SEARCH]=
{"Find...                 "
,"Replace...              "
,"Search again      Ctrl+L"
,"Go to Line number...    "
,"Previous error    Alt+F7"
,"Next error        Alt+F8"
,"Location function       "
};
void display_menu_search(void);
void draw_box_search (int left,int top, int width,int height);
char get_code_search(void);
void menu_action_search(char *item_name);
int vpos_search;

int menu_search (void)
{
textbackground(BLUE);
clrscr();
_setcursortype(_NOCURSOR);
while (TRUE)
{
	display_menu_search();
	switch(get_code_search())
	{
		case U_ARRO:
		vpos_search=(vpos_search>0)?--vpos_search:MAX_ITEMS_SEARCH-1;
		break;
		case D_ARRO:
		vpos_search=(vpos_search<MAX_ITEMS_SEARCH-1)?++vpos_search:0;
		break;
		case '\r':
		menu_action_search(menu_item_search[vpos_search]);
		break;
	}
}
}

void display_menu_search()
{
  int j;
  textbackground(WHITE);
  textcolor(BLACK);
  draw_box_search(19,2,MENU_WIDTH_SEARCH,MAX_ITEMS_SEARCH+3);
  for(j=0;j<MAX_ITEMS_SEARCH;j++)
  {
	if (j==vpos_search)
	  textbackground(GREEN);
	  gotoxy(5,j+3);
	  cputs(menu_item_search[j]);
	  textbackground(WHITE);
	}
  }
  void draw_box_search(int left,int top, int width, int height)
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
  window(16,1,80,25);
  }

  char get_code_search(void)
  {
  char key;
  if((key=getch())==0)
  return(getch());
  else if(key=='\r')
  return (key);
  else
  return (0);
   }

   void menu_action_search(char *item_name)
   {
   gotoxy(1,25);
   clrscr();
   if (strcmp(item_name,"Find...                 ")==0)
      exit(0);
   else if(strcmp(item_name,"Replace...              ")==0)
      exit(0);
   else if(strcmp(item_name,"Go to Line number...    ")==0)
      exit(0);
   else if(strcmp(item_name,"Previous error    Alt+F7")==0)
      exit(0);
   else if(strcmp(item_name,"Next error        Alt+F8")==0)
      exit(0);
   else if(strcmp(item_name,"Location function...    ")==0)
      exit(0);
   else if(strcmp(item_name,"Copy example            ")==0)
      exit(0);

   {
       _setcursortype(_NORMALCURSOR);
       exit(0);
   }
  }








