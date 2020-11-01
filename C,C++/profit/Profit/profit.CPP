/*
This source code is provided by Muhammad Saqib MYCPLUS Online Community WEbsite.
You are free to modify and change this code as per your requirements.

Website: http://4-tech-support.com/
Email:   msaqib@4-tech-support.com



*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
class button
{
private:
int x1,y1,x2,y2;
long inc,exp,pro;
public:
void draw(int x3x1,int y3y1,int x3x2,int y3y2)
{
x1 = x3x1;
y1 = y3y1;
x2 = x3x2;
y2 = y3y2;
setcolor(15);
rectangle(x1,y1,x2,y2);
setfillstyle(1,7);
floodfill(x1+1,y1+1,7);
setcolor(15);
setlinestyle(1,0,5);
line(x1,y1,x2,y1);
line(x2,y2,x2,y2);
setcolor(0);
setlinestyle(1,2,5);
line(x1,y1,x1,y2);
line(x1,y2,x2,y2);
}
void bar()
{
setcolor(3);
settextstyle(1,0,2);
outtextxy(255,85,"enter the data for month");
outtextxy(255,120,"enter income");
gotoxy(53,9);
cin>>inc;
gotoxy(35,11);
outtextxy(255,150,"enter expences");
gotoxy(53,11);
cin>>exp;
outtextxy(255,180,"prophit =");
pro=inc-exp;
gotoxy(53,13);
cout<<pro;
gotoxy(35,15);
}
void gra()
{
setcolor(4);
line(255,375,580,375);
line(255,375,255,100);
long j,n,m=260;
n=inc/1000;
setcolor(10);
setfillstyle(4,11);
bar3d(10+m,375-n,30+m,375,6,5);
n=exp/1000;
setcolor(9);
setfillstyle(4,13);
bar3d(50+m,375-n,70+m,375,6,5);
n=pro/1000;
setcolor(4);
setfillstyle(4,2);
bar3d(90+m,375-n,110+m,375,6,5);
}
void tab()
{
setcolor(4);
rectangle(260,100,590,370);
line(260,130,590,130);
settextstyle(1,0,2);
outtextxy(300,100,"tabuler form of data");
line(400,130,400,370);
outtextxy(310,140,"income");
outtextxy(310,220,"expences");
outtextxy(310,300,"profit");
gotoxy(60,10);
cout<<inc;
gotoxy(60,15);
cout<<exp;
gotoxy(60,20);
cout<<pro,
line(260,200,590,200);
line(260,285,590,285);
}
void clear()
{
setcolor(1);
bar3d(250,80,600,380,0,0);
setfillstyle(SOLID_FILL,1);
floodfill(251,81,1);
}
void pie()
{
long a,b,c;
a=inc/1000;
b=exp/1000;
c=pro/1000;
pieslice(380,230,0,a,80);
setfillstyle(SOLID_FILL,RED);
pieslice(380,230,0,b,80);
setfillstyle(SOLID_FILL,YELLOW);
pieslice(380,230,b,a,80);
setfillstyle(SOLID_FILL,RED);
pieslice(500,180,0,40,20);
setcolor(4);
settextstyle(0,0,0);
outtextxy(530,180,"expences");
setfillstyle(SOLID_FILL,YELLOW);
pieslice(500,210,0,40,20);
outtextxy(530,210,"prophit");
}
};

void main()
{
int x,y,d,m;
union REGS regs;
d=DETECT;
initgraph(&d,&m,"F:\\tc\\bgi");
button bt;
while(1)
{
cleardevice();
//setbkcolor(4);
bt.draw(580,20,600,35);
line(600,35,580,20);
line(600,20,580,35);
rectangle(580,20,600,35);
rectangle(545,20,566,35);
line(530,35,510,35);
rectangle(50,120,200,380);//second
rectangle(50,100,200,120);//second and small
rectangle(170,105,180,115);
rectangle(185,105,195,115);
line(185,105,195,115);
line(195,105,185,115);
bt.draw(80,140,180,170); //inside
outtextxy(82,150,"enter data");
bt.draw(80,180,180,210);
outtextxy(82,190,"tabuler form");
bt.draw(80,220,180,250);
outtextxy(82,230,"bar graph");
bt.draw(80,260,180,290);
outtextxy(82,270,"pie graph");
bt.draw(80,300,180,330);
outtextxy(82,310,"line graph");
bt.draw(160,115,150,115);
rectangle(250,80,600,380);//third
setfillstyle(SOLID_FILL,1);
floodfill(251,81,0);
rectangle(15,10,610,40); //upper rec
setfillstyle(SOLID_FILL,4);
floodfill(16,11,0);
rectangle(15,43,610,450);// big one
bt.draw(270,400,320,430);
outtextxy(275,410,"exit");
bt.draw(330,400,390,430);
outtextxy(340,410,"clear");
settextstyle(4,0,1);
outtextxy (50,10, "program by zahid");
//setbkcolor(4);
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
if(regs.x.bx&1)
{
if( x>80 && x<160 && y>180 && y<210)
{
bt.tab();
}
if(x>80&&x<160&&y>260&&y<290)
{
bt.pie();
}
if(x>270&&x<320&&y>400&&y<430)
{
exit(0);
}
if(x>580&&x<600&&y>20&&y<35)
{
cleardevice();
}
if(x>330&&x<390&&y>400&&y<430)
{
bt.clear();
}
if(x>80 && x<160 && y>220 && y<250)
{
bt.gra();

}
if(x>80 && x<160 && y>140&&y<170)
{
bt.bar();
}
}
}
}

}

