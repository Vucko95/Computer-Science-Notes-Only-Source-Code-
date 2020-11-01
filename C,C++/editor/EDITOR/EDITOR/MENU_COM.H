#define TRUE 1
#define U_ARRO 72
#define D_ARRO 80
#define MENU_WIDTH_COMP 29
#define MAX_ITEMS_COMP 6
char *menu_item_comp[MAX_ITEMS_COMP]=
{"Compile           ALT+F9"
,"Make              F9    "
,"Link                    "
,"Build all               "
,"Information...          "
,"Remove messages         "
};
void display_menu_comp(void);
void draw_box_comp (int left,int top, int width,int height);
char get_code_comp(void);
void menu_action_comp(char *item_name);
int vpos_comp;

int menu_compile (void)
{
textbackground(BLUE);
clrscr();
_setcursortype(_NOCURSOR);
while (TRUE)
{
	display_menu_comp();
	switch(get_code_comp())
	{
		case U_ARRO:
		vpos_comp=(vpos_comp>0)?--vpos_comp:MAX_ITEMS_COMP-1;
		break;
		case D_ARRO:
		vpos_comp=(vpos_comp<MAX_ITEMS_COMP-1)?++vpos_comp:0;
		break;
		case '\r':
		menu_action_comp(menu_item_comp[vpos_comp]);
		break;
	}
}
}

void display_menu_comp()
{
  int j;
  textbackground(WHITE);
  textcolor(BLACK);
  draw_box_comp(32,2,MENU_WIDTH_COMP,MAX_ITEMS_COMP+3);
  for(j=0;j<MAX_ITEMS_COMP;j++)
  {
	if (j==vpos_comp)
	  textbackground(GREEN);
	  gotoxy(5,j+3);
	  cputs(menu_item_comp[j]);
	  textbackground(WHITE);
	}
  }
  void draw_box_comp(int left,int top, int width, int height)
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
  window(30,1,80,25);
  }

  char get_code_comp(void)
  {
  char key;
  if((key=getch())==0)
  return(getch());
  else if(key=='\r')
  return (key);
  else
  return (0);
   }

   void menu_action_comp(char *item_name)
   {
   gotoxy(1,25);
   clrscr();
	if(strcmp(item_name,"Compile           ALT+F9")==0)
      exit(0);
   else if(strcmp(item_name,"Make                  F9")==0)
      exit(0);
   else if(strcmp(item_name,"Link                    ")==0)
      exit(0);
   else if(strcmp(item_name,"Build all               ")==0)
      exit(0);
   else if(strcmp(item_name,"Information...          ")==0)
      exit(0);
   else if(strcmp(item_name,"Remove messages         ")==0)
      exit(0);

   {
       _setcursortype(_NORMALCURSOR);
       exit(0);
   }
  }








