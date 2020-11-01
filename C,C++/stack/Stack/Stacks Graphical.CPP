/*
This source code is provided by Muhammad Saqib MYCPLUS Online Community WEbsite.
You are free to modify and change this code as per your requirements.

Website: http://4-tech-support.com/
Email:   msaqib@4-tech-support.com



*/


/*********************************************************************
		    STACK OPERATIONS
**********************************************************************
By:
Muhammad Saqib
*/

#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include<conio.h>
#include<process.h>

#define SIZE 6

static struct stack{
	    int top;
	    int items[SIZE];
	    }s1;

void push(struct stack *,int);
int pop(struct stack*);
int stacktop(struct stack*);
int empty(struct stack*);
int search(struct stack *,int);
void insert(struct stack *,int,int);
void replace(struct stack *,int,int);
void del(struct stack *,int);
void printline(void);
void startscreen(int,int);
void shell(int,int);
void close(void);
void start_screen();
void press_esc();

int gd=DETECT,gm,maxx,maxy;


void main()
{
	char c;
	int i,temp;
	s1.top=-1;
	initgraph(&gd,&gm,"f:\\tc\\bgi");
	maxx=getmaxx();
	maxy=getmaxy();
	startscreen(maxx,maxy);
	start_screen();
	shell(maxx,maxy);
	START:
	c=getch();
	switch (c)
	{
		case '1':   gotoxy(3,17);
			printf("What element do you wish to push?");
			scanf("%d",&temp);
			push(&s1,temp);
			break;
		case '2':   gotoxy(3,17);
			pop(&s1);
			break;
		case '3':   gotoxy(3,17);
			printf("Enter the element you wish to search?");
			scanf("%d",&temp);
			temp=search(&s1,temp);
			gotoxy(5,19);
			if (temp==-1)
				printf("Sorry! No results Found!");
			else
				printf("The element is at index %d",temp);
				getch();
				break;
		case '4':   gotoxy(3,17);
			printf("Enter the POSTION and ELEMENT you wish to insert?");
			scanf("%d %d",&i,&temp);
			insert(&s1,i,temp);
			break;
		case '5':   gotoxy(3,17);
			printf("Enter the POSTION and ELEMENT you wish to replace?");
			scanf("%d %d",&i,&temp);
			replace(&s1,i,temp);
			break;
		case '6':   gotoxy(3,17);
			printf("Enter the POSTION you wish to delete from stack?");
			scanf("%d",&temp);
			del(&s1,temp);
			break;
		default :   gotoxy(3,17);
			printf("Invalid entry! Try again!");
			break;
	}
	for (i=0;i<=6;i++)
	{
		gotoxy(3,17+i);
		printf("\t\t\t\t\t\t\t\t\t");
	}
	gotoxy(3,17);
	printf("Do You wish to contine?");
	c=getch();
	if (c=='y')
	{
		gotoxy(3,17);	printf("\t\t\t\t\t");
		goto START;
	}
	closegraph();
	close();
	restorecrtmode();
}

void push(struct stack *sx,int x)
{
	if (sx->top==SIZE-1)
	{
		gotoxy(5,22);
		printf("\tSTACT OVERFLOW\n");
		getch();
		return;
	}
	sx->items[++sx->top]=x;
	gotoxy(66,14-2*sx->top);
	printf("%d",x);
}

int pop(struct stack *sx)
{
	if (empty(sx))
	{
		gotoxy(5,22);
		printf("\t STACK UNDERFLOW\n");
		getch();
		return(0);
	}
	gotoxy(66,14-2*sx->top);
	printf("    ");
	return(sx->items[sx->top--]);
}

int stacktop(struct stack *sx)
{
	return(sx->items[sx->top]);
}

int empty(struct stack *sx)
{
	return((sx->top==-1));
}

int search(struct stack *sx,int n)
{
	int arr[20];
	int i=0,j,result=-1;
	for (j=sx->top;!(empty(sx));j--)
	{
		if (n==stacktop(sx))
		{
			result=sx->top;
			break;
		}
		arr[i++]=pop(sx);
	}
	for (j=i-1;j>=0;j--)
		push(sx,arr[j]);
	return(result);
}

void insert(struct stack *sx,int pos,int ele)
{
	int arr[20];
	int i=0,j;
	if (pos>sx->top)
	{
		gotoxy(3,19);
		printf("Invalid Position!");
		getch();
		return;
	}
	for (j=sx->top;j>=pos;j--)
		arr[i++]=pop(sx);
	push(sx,ele);
	for (j=i-1;j>=0;j--)
		push(sx,arr[j]);
}

void replace(struct stack *sx,int pos,int ele)
{
	int arr[20];
	int i=0,j;
	if (pos>sx->top)
	{
		gotoxy(3,19);
		printf("Invalid Position!");
		getch();
		return;
	}
	for (j=sx->top;j>=pos;j--)
		arr[i++]=pop(sx);
	push(sx,ele);
	for (j=i-2;j>=0;j--)
		push(sx,arr[j]);
}

void del(struct stack *sx,int pos)
{
	int arr[20];
	int i=0,j;
	if (pos>sx->top)
	{
		gotoxy(3,19);
		printf("Invalid Position!");
		getch();
		return;
	}
	for (j=sx->top;j>pos;j--)
		arr[i++]=pop(sx);
	pop(sx);
	for (j=i-1;j>=0;j--)
		push(sx,arr[j]);
}

void printline(void)
{
	int i;
	for (i=0;i<40;i++)
		printf("оп");
}

void startscreen(int x,int y)
{
	int i;
	sound(1);
	setbkcolor(1);
	setlinestyle(5,0,2);
	rectangle(0,0,x,y);
	rectangle(2,2,x-2,y-2);
	settextstyle(10,HORIZ_DIR,3);
	setcolor(YELLOW);
	outtextxy(x/10,y/3,"Loading ....... Please Wait......");
	setcolor(LIGHTGRAY);
	rectangle(x/8,2*y/3,7*x/8,2*y/3+20);
	setcolor(WHITE);
	bar(x/8+1,2*y/3+1,7*x/8-1,2*y/3+20-1);
	setfillstyle(1,LIGHTBLUE);
	delay(2000);
	for (i=4;i>=1;i--)
	{
		bar(x/8+1,2*y/3+1,7*x/8/i-1,2*y/3+20-1);
		delay(1000);
	}
	delay(500);
	nosound();
	//closegraph();
	initgraph(&gd,&gm,"f:\tc\bgi");
}

void shell(int x,int y)
{

	int i;
	setbkcolor(BLACK);
	rectangle(0,0,x,y);
	rectangle(2,2,x-2,y-2);
	settextstyle(0,HORIZ_DIR,2);
	gotoxy(18,2);
	setcolor(WHITE);
	outtextxy(x/5,y/30,"BASIC STACK OPERATIONS");
	textcolor(DARKGRAY);

	gotoxy(24,15); printf("Enter (1--6) for Stack Operations");
	gotoxy(24,4);	printf("(1)  Push");
	gotoxy(24,6);	printf("(2)  Pop");
	gotoxy(24,8);	printf("(3)  Search");
	gotoxy(24,10);	printf("(4)  Insert");
	gotoxy(24,12);	printf("(5)  Replace");
	gotoxy(24,14); printf("(6)  Delete\n\n");
	bar(0,y/2+4,x,y/2+6);
	setcolor(MAGENTA);
	setlinestyle(0,0,3);
	line(3*x/4,y/12-7,3*x/4,y/2-7);
	line(3*x/4+100,y/12-7,3*x/4+100,y/2-7);
	for (i=0;i<7;i++)
	{
		line(3*x/4,y/2-i*33-7,3*x/4+100,y/2-i*33-7);
		gotoxy(55,14-2*i);
		if (i<6)
			printf("о %d п",i);
	}
press_esc();
}

void close(void)
{
int mx, my;
/* request auto detection */
int gd= DETECT, gm;
initgraph(&gd,&gm,"f:\\tc\\bgi");
mx = (getmaxx() / 2);
my = (getmaxy() / 2);

//SET baqckground color
setfillstyle(9, 1);
bar(0,0,getmaxx(),getmaxy());

//DRAW a bar, and make it look like a 3d bar
setfillstyle(1,7);
//bar(50,20,600,400);

//DRAW lines for the top and left side
setcolor(15);
line(50,20,600,20);
line(51,21,599,21);
line(50,20,50,400);
line(51,21,51,399);

//DRAW lines for the bottom and right side
setcolor(8);
line(600,20,600,400);
line(599,21,599,400);
line(50,400,600,400);
line(51,399,600,399);

//DRAW two 3D bars for the left and right side

setfillstyle(9,8);
bar(70,40,100,380);
bar(70,40,550,70);
bar(70,350,550,379);
//getch();
bar(545,40,575,380);

//PRINT 3D text CALENDAR 2002
settextstyle(1, 0, 4);
settextjustify(1,1);
setcolor(LIGHTGREEN);
outtextxy(mx+2, my - 46, "Thank You!");
setcolor(LIGHTGREEN);
outtextxy(mx + 1, my - 45, "Thank You!");
setcolor(GREEN);
outtextxy(mx + 2, my - 44, "Thank You!");

//PRINT copyright notice
settextstyle(2, 0, 5);
setcolor(WHITE);
outtextxy(mx + 1, my + 150, "Copyright 2002 Nagina Computers");

getch(); //PAUSE for a while
closegraph();
//initgraph(&gd,&gm,"e:\tc\bgi");


}

//Start
void start_screen()
{
int mx, my;
/* request auto detection */
int gd= DETECT, gm;
initgraph(&gd,&gm,"f:\\tc\\bgi");
mx = (getmaxx() / 2);
my = (getmaxy() / 2);

//SET baqckground color
setfillstyle(9, 1);
bar(0,0,getmaxx(),getmaxy());

//DRAW a bar, and make it look like a 3d bar
setfillstyle(1,7);
//bar(50,20,600,400);

//DRAW lines for the top and left side
setcolor(15);
line(50,20,600,20);
line(51,21,599,21);
line(50,20,50,400);
line(51,21,51,399);

//DRAW lines for the bottom and right side
setcolor(8);
line(600,20,600,400);
line(599,21,599,400);
line(50,400,600,400);
line(51,399,600,399);

//DRAW two 3D bars for the left and right side

setfillstyle(9,8);
bar(70,40,100,380);
bar(70,40,550,70);
bar(70,350,550,379);
//getch();
bar(545,40,575,380);

//PRINT 3D text CALENDAR 2002
settextstyle(1, 0, 4);
settextjustify(1,1);
setcolor(LIGHTGREEN);
outtextxy(mx+2, my - 150, "!...Wel Come...!");
setcolor(LIGHTGREEN);
outtextxy(mx + 1, my - 149, "!...Wel Come...!");
setcolor(GREEN);
outtextxy(mx + 2, my - 148, "!...Wel Come...!");

setcolor(GREEN);
outtextxy(mx + 2, my - 100, "Stack Operations");


//Print 3D Text
setcolor(WHITE);
outtextxy(mx, my-50, "BY");
setcolor(DARKGRAY);
outtextxy(mx, my + 5, "Muhammad Saqib");
setcolor(DARKGRAY);
outtextxy(mx + 1, my + 6, "Muhammad Saqib");
setcolor(LIGHTGRAY);
outtextxy(mx+1, my + 7, "Muhammad Saqib");

//PRINT copyright notice
settextstyle(2, 0, 5);
setcolor(WHITE);
outtextxy(mx + 1, my + 150, "Copyright 2002 Nagina Computers");

getch(); //PAUSE for a while
closegraph();
initgraph(&gd,&gm,"e:\tc\bgi");
}

void press_esc()
{
settextstyle(2, 1, 5);
setcolor(RED);
outtextxy(600, 60,"..Press Esc to Exit..");

}