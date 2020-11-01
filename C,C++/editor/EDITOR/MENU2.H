
#define TRUE 1
#define U_ARRO 72
#define D_ARRO 80
#define MENU_WIDTH_EDIT 28
#define MAX_ITEMS_EDIT 8

char *menu_item_edit[MAX_ITEMS_EDIT]=
{"Undo            Alt+BkSp"
,"Redo      Shift+Alt+BkSp"
,"Cut            Shift+Del"
,"Copy            Ctrl+Ins"
,"Paste          Shift+Ins"
,"Clear           Ctrl+Del"
,"Copy example            "
,"Show clipboard          "
};
void display_menu_edit(void);
void draw_box_edit (int left,int top, int width,int height);
char get_code_edit(void);
void menu_action_edit(char *item_name);
int vpos_edit;
int menu_edit (void)
{
char key;
textbackground(BLUE);
clrscr();
_setcursortype(_NOCURSOR);
while(1)
{


	display_menu_edit();
	switch(getch())
	{
		case U_ARRO:
		vpos_edit=(vpos_edit>0)?--vpos_edit:MAX_ITEMS_EDIT-1;
		break;
		case D_ARRO:
		vpos_edit=(vpos_edit<MAX_ITEMS_EDIT-1)?++vpos_edit:0;
		break;
		case '\r':
		menu_action_edit(menu_item_edit[vpos_edit]);
		break;
		case 27:
		//puttext(1,1,80,25,m);
		gotoxy(1,1);
		break;

	}
}
}

void display_menu_edit()
{
  int j;
  textbackground(WHITE);
  textcolor(BLACK);
  draw_box_edit(13,2,MENU_WIDTH_EDIT,MAX_ITEMS_EDIT+3);
  for(j=0;j<MAX_ITEMS_EDIT;j++)
  {
	if (j==vpos_edit)
	  textbackground(GREEN);
	  gotoxy(5,j+3);
	  cputs(menu_item_edit[j]);
	  textbackground(WHITE);
	}
  }
  void draw_box_edit(int left,int top, int width, int height)
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
  window(11,1,MENU_WIDTH_EDIT+10,MAX_ITEMS_EDIT+3);
  }

  char get_code_edit(void)
  {
  char key;
  if((key=getch())==0)
  return(getch());
  else if (key=='\r')
  return (key);
  else
  return(0);
   }

   void menu_action_edit(char *item_name)
   {
   gotoxy(1,25);
   clrscr();
   if (strcmp(item_name,"Undo            Alt+BkSp")==0)
      exit(0);
   else if(strcmp(item_name,"Redo      Shift+Alt+BkSp")==0)
      exit(0);
   else if(strcmp(item_name,"Cut            Shift+Del")==0)
      exit(0);
   else if(strcmp(item_name,"Copy            Ctrl+Ins")==0)
      exit(0);
   else if(strcmp(item_name,"Paste          Shift+Ins")==0)
      exit(0);
   else if(strcmp(item_name,"Clear           Ctrl+Del")==0)
      exit(0);
   else if(strcmp(item_name,"Copy example            ")==0)
      exit(0);
   else if(strcmp(item_name,"Show clipboard          ")==0)

   {
       _setcursortype(_NORMALCURSOR);
       exit(0);
   }
  }








