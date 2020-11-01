#define TRUE 1
#define U_ARRO 72
#define D_ARRO 80
#define MENU_WIDTH_RUN 28
#define MAX_ITEMS_RUN 6
char *menu_item_run[MAX_ITEMS_RUN]=
{"Run            Ctrl+F9"
,"Program reset  Ctrl+F2"
,"Go to cursor        F4"
,"Trace in to         F7"
,"Step over           F8"
,"Arguments...          "
};
void display_menu_run(void);
void draw_box_run (int left,int top, int width,int height);
char get_code_run(void);
void menu_action_run(char *item_name_run);
int vpos_run;

int menu_run (void)
{
textbackground(BLUE);
clrscr();
_setcursortype(_NOCURSOR);
while (TRUE)
{
	display_menu_run();
	switch(get_code_run())
	{
		case U_ARRO:
		vpos_run=(vpos_run>0)?--vpos_run:MAX_ITEMS_RUN-1;
		break;
		case D_ARRO:
		vpos_run=(vpos_run<MAX_ITEMS_RUN-1)?++vpos_run:0;
		break;
		case '\r':
		menu_action_run(menu_item_run[vpos_run]);
		break;
	}
}
}

void display_menu_run()
{
  int j;
  textbackground(WHITE);
  textcolor(BLACK);
  draw_box_run(27,2,MENU_WIDTH_RUN,MAX_ITEMS_RUN+3);
  for(j=0;j<MAX_ITEMS_RUN;j++)
  {
	if (j==vpos_run)
	  textbackground(GREEN);
	  gotoxy(5,j+3);
	  cputs(menu_item_run[j]);
	  textbackground(WHITE);
	}
  }
  void draw_box_run(int left,int top, int width, int height)
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
  window(25,1,80,25);
  }

  char get_code_run(void)
  {
  char key;
  if((key=getch())==0)
  return(getch());
  else if(key=='\r')
  return (key);
  else
  return (0);
   }

   void menu_action_run(char *item_name_run)
   {
   gotoxy(1,25);
   clrscr();
	if (strcmp(item_name_run,"Run            Ctrl+F9")==0)
      exit(0);
   else if(strcmp(item_name_run,"Program reset  Ctrl+F2")==0)
      exit(0);
   else if(strcmp(item_name_run,"Go to cursor        F4")==0)
      exit(0);
   else if(strcmp(item_name_run,"Trace in to         F7")==0)
      exit(0);
   else if(strcmp(item_name_run,"Step over           F8")==0)
      exit(0);

   else if(strcmp(item_name_run,"Arguments...          ")==0)
   {
       _setcursortype(_NORMALCURSOR);
       exit(0);
   }
  }









