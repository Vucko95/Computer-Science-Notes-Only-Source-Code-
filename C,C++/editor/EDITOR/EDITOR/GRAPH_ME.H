#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
void mouseover();
void mousedown();
void mouseover1();
void mousedown1();

void graph()
{
int x,y,d,m;
union REGS regs;
d=DETECT;
initgraph(&d,&m,"f:\\tc\\bgi");


cleardevice();
//setbkcolor(BLACK);
rectangle(20,80,200,380);//second

rectangle(250,80,600,380);//third
setfillstyle(SOLID_FILL,BLUE);
floodfill(251,81,0);
rectangle(15,10,610,40); //upper rec
setfillstyle(SOLID_FILL,BLUE);
floodfill(16,11,0);

	setfillstyle(12,LIGHTGRAY);//upper main
	bar(15,10,610,40);
	setfillstyle(11,1);//sub rectangles
	bar(250,80,600,380);
	bar(50,80,200,380);
	setfillstyle(4,6);
	bar(20,80,50,380);


outtextxy(25,100, "1:" ); outtextxy(80,100,"RIZWAN IQBAL");
outtextxy(25,200, "2:");  outtextxy(80,200,"ZIA UR REHMAN");
outtextxy(25,300, "3:");  outtextxy(80,300,"MUHAMMAD SAQIB");



settextstyle(7,0,1);
outtextxy (75,12, "PROJECT BY SAQIB, RIZWAN & ZIA UR REHMAN");

settextstyle(2,0,5);
outtextxy(280,100,"Hard working and Co-operative");
outtextxy(280,115,"Done Mouse Functions and");
outtextxy(280,130,"Graphics function which you are    ");
outtextxy(280,145,"Seeing at the moment  ");
outtextxy(280,200, "Most Lineant and Hardworker");
outtextxy(280,215, "He has done all the textmode  Graphics");
outtextxy(280, 280, "Has made all the menues and ");
outtextxy(280, 295,"All the functions related to ");
outtextxy(280,310,"Menues, Mouse, and Graphics   ");
outtextxy(280,325,"Also Combine all the functions to make  ");
{settextstyle(1,0,3);
setcolor(RED);
outtextxy(280,340,"Text Mode Graphics   ");}

{
	setfillstyle(1,LIGHTGRAY);
	bar(265,405,315,420);
	bar(330,405,390,420);
	setcolor(WHITE);
	rectangle(265,405,315,420);//button for exit
	rectangle(263,403,317,422);
	rectangle(330,405,390,420);//button for enter
	rectangle(328,403,392,422);
}
setcolor(BLACK);
settextstyle(2,0,4);
outtextxy(280,407,"EXIT"); //Buttons
outtextxy(345,407,"ENTER");



{
	setcolor(WHITE);
	settextstyle(1,1,3);
	outtextxy(210,95,"TEXT MODE GRAPHICS");
}

regs.x.ax=0;
int86(0x33,&regs,&regs);
regs.x.ax=1;
int86(0X33,&regs,&regs);
while(1)
	{
		regs.x.ax=3;
		int86(0x33,&regs,&regs);
		x=regs.x.cx;
		y=regs.x.dx;
		if(regs.x.cx&1)
		{
				if(x>270&&x<320&&y>400&&y<430)
					{
						mouseover();
					}
					else {mousedown();}
				if(x>336&&x<383&&y>400&&y<430)
					{
						mouseover1();
					}
					else {mousedown1();}

			if(regs.x.bx&1)
			{
				if(x>270&&x<320&&y>400&&y<430)
					{
						closegraph();
						exit(0);
					}
				if(x>336&&x<383&&y>400&&y<430)
					{
						closegraph();
						project1();
					}
			}
		}
	}
}


void mouseover() //Mouse over effect for Button Exit
{

	setcolor(BLACK);


	line(265,405,315,405);
	line(265,405,265,420);
	setcolor(WHITE);
	settextstyle(2,0,4);
	outtextxy(280,407,"EXIT"); //Buttons

}


void mousedown()
{
	setcolor(WHITE);
	line(265,405,315,405);
	line(265,405,265,420);
	setcolor(BLACK);
	settextstyle(2,0,4);
	outtextxy(280,407,"EXIT"); //Buttons

}

void mouseover1() //For enter button
{
	setcolor(BLACK);
	line(330,405,390,405);
	line(330,405,330,420);
	setcolor(WHITE);
	settextstyle(2,0,4);
	outtextxy(345,407,"ENTER");

}

void mousedown1() //For enter button
{
	setcolor(WHITE);
	line(330,405,390,405);
	line(330,405,330,420);
	setcolor(BLACK);
	settextstyle(2,0,4);
	outtextxy(345,407,"ENTER");



}
