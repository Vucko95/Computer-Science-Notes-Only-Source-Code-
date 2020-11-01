/*******************************************************
*     MYCPLUS Sample Code - http://www.mycplus.com     *
*                                                     *
*   This code is made available as a service to our   *
*      visitors and is provided strictly for the      *
*               purpose of illustration.              *
*                                                     *
* Please direct all inquiries to saqib at mycplus.com *
*******************************************************/



#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<malloc.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
void intro(void);
int main_menu(void);
void new_account(void);
void new_account_gui(void);
int getaccount_no(char *);
void sav_account(int,char*,int,char*,int,int,int,int,int);
void update_main(char *);
void process(void);
void list_all(void);
void print_it(char*);
void list_all_gui(void);
void trans_menu(void);
int trans_gui(void);
void show_trans(void);
void mod_trans(void);
void see_it(void);
void report(void);
void dep_gui(void);
void deposite(void);
void mod_choice(void);
void withdraw(void);
main(){
intro();
process();
return 0;
}
void process(void){
int option;
option=main_menu();
if(option==1)
new_account();
if(option==2)
list_all();
if(option==3)
trans_menu();
if(option==4)
exit(0);
}
void intro(void){
void *image;
int size;
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
size=imagesize(140,140,500,250);
image=malloc(size);
setfillstyle(SOLID_FILL,GREEN);
circle(200,200,50);
floodfill(200,200,WHITE);
setcolor(LIGHTGRAY);
circle(200,200,19);
setcolor(WHITE);
circle(200,200,18);
circle(200,200,49);
circle(200,200,53);
circle(200,200,20);

arc(215,215,350,90,30);
arc(210,182,90,194,30);
arc(180,195,180,300,30);
settextstyle(1,HORIZ_DIR,1);
setcolor(LIGHTGRAY);
outtextxy(270,180,"National Bank");

outtextxy(270,185,"___________________");
outtextxy(270,210,"Of Pakistan Pvt Ltd.");
settextstyle(0,HORIZ_DIR,0);
setcolor(DARKGRAY);
outtextxy(270,240,"COPYRIGHT 2002");
getimage(141,141,499,259,image);
cleardevice();
for(int count=1;count<300;count+=2)
putimage(1+count,100,image,COPY_PUT);
for(int down=0;down<640;++down)
{
delay(5);
line(1,220,1+down,220);
}
setcolor(BLUE);
for(int bottom=0;bottom<300;bottom+=4)
line(1,220+bottom,640,220+bottom);
free(image);
getch();
closegraph();
}
// ----------------- m a i n - m e n u ---------------------
int main_menu(void){
int option;
int size;
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
void *main_window,*button_down;
size=imagesize(10,70,251,351);
main_window=malloc(size);
size=imagesize(10,310,251,351);
button_down=malloc(size);
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,200,100);
setcolor(WHITE);
line(9,69,9,99);
line(10,69,200,69);
setcolor(BLACK);
outtextxy(30,80,"M A I N   M E N U");
setcolor(DARKGRAY);
rectangle(10,110,250,150);
setcolor(BLACK);
rectangle(10,110,251,151);
setcolor(WHITE);
line(10,110,10,150);
line(10,110,250,110);
setcolor(BLACK);
outtextxy(40,130,"1.  Create new account");
setcolor(DARKGRAY);
rectangle(10,160,250,200);
setcolor(BLACK);
rectangle(10,160,251,201);
setcolor(WHITE);
line(10,160,10,200);
line(10,160,250,160);
setcolor(BLACK);
outtextxy(40,180,"2.  List all accounts");
setcolor(DARKGRAY);
rectangle(10,210,250,250);
setcolor(BLACK);
rectangle(10,210,251,251);
setcolor(WHITE);
line(10,210,10,250);
line(10,210,250,210);
setcolor(BLACK);
outtextxy(40,230,"3.  Show individual info");
setcolor(DARKGRAY);
rectangle(10,260,250,300);
setcolor(BLACK);
rectangle(10,260,251,301);
setcolor(WHITE);
line(10,260,10,300);
line(10,260,250,260);
setcolor(BLACK);
outtextxy(40,280,"4.  Quit");
setcolor(LIGHTGRAY);
rectangle(10,310,250,350);
getimage(10,70,251,351,main_window);
setcolor(WHITE);
rectangle(10,310,251,351);
setcolor(DARKGRAY);
line(10,310,10,350);
line(11,311,11,350);
line(10,310,250,310);
line(11,311,250,311);
setcolor(BLACK);
getimage(10,310,251,351,button_down);
cleardevice();
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
putimage(10,70,main_window,COPY_PUT);
char check;
setcolor(BLACK);
check=getch();
if(check==49)
{
putimage(10,110,button_down,COPY_PUT);
outtextxy(40,130,"1.  Create new account");
option=1;
delay(600);
}
if(check==50)
{
putimage(10,160,button_down,COPY_PUT);
outtextxy(40,180,"2.  List all accounts");
option=2;
delay(600);
}
if(check==51)
{
putimage(10,210,button_down,COPY_PUT);
outtextxy(40,230,"3.  Show individual info");
option=3;
delay(600);
}
if(check==52)
{
putimage(10,260,button_down,COPY_PUT);
outtextxy(40,280,"4.  Quit");
option=4;
delay(600);
}
free(main_window);
free(button_down);
cleardevice();
closegraph();
return(option);
}
void new_account(void){
int withdraw=0;
int deposit=0;
int account_no=888;
int balance=0;
char address[25];
char name[10]={'D','E','F','A','U','L','T'};
struct date dat;
getdate(&dat);
account_no=getaccount_no(name);
int year=dat.da_year;
int day=dat.da_day;
int month=dat.da_mon;
--account_no;
new_account_gui();
gotoxy(20,9);
cout<<account_no;
gotoxy(42,9);
cout<<day<<" of "<<month<<" "<<year;
gotoxy(40,13);
cout<<" ";
cin>>name;
gotoxy(40,17);
cout<<" ";
cin>>balance;
gotoxy(40,21);
cout<<" ";
cin>>address;
sav_account(account_no,name,balance,address,day,month,year,deposit,withdraw);
cleardevice();
closegraph();
process();
}
int getaccount_no(char *name)
{
char string[10];
int count=0;
int account_no=0;
ifstream pfile("main");
if(pfile==NULL)
{
account_no=2;
pfile.close();
ofstream pfile2("main");
pfile2<<name;
pfile2.close();
return account_no;
}
ifstream pfile3("main");
while(string[0]!=NULL)
{
pfile3>>string;
++count;
}
pfile3.close();
account_no=count;
return account_no;
}
void sav_account(int account_no,char *name,int balance,char *address,int day,int month,int year,int deposit,int withdraw){
ofstream pfile(name);
pfile<<account_no;
pfile<<endl;
pfile<<name;
pfile<<endl;
pfile<<balance;
pfile<<endl;
pfile<<address;
pfile<<endl;
pfile<<day<<"of"<<month<<"-"<<year;
pfile<<endl;
pfile<<deposit;
pfile<<endl;
pfile<<withdraw;
pfile.close();
update_main(name);
}
void update_main(char *name){
ofstream pfile;
pfile.open("main",ios::app);
pfile<<endl;
pfile<<name;
pfile.close();
}
void new_account_gui(void)
{
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,200,100);
 outtextxy(20,80,"N E W   A C C O U N T");
 setcolor(WHITE);
 line(9,70,9,100);
 line(10,69,200,69);
 setcolor(DARKGRAY);
 rectangle(10,110,500,400);
 setcolor(WHITE);
 line(11,111,11,399);
 line(11,111,499,111);
 setcolor(DARKGRAY);
 outtextxy(40,130,"ACCOUNT NO                  DATED ");
 setcolor(DARKGRAY);
 rectangle(130,125,200,150);
 rectangle(310,125,450,150);
 setcolor(WHITE);
 line(199,149,131,149);
 line(199,149,199,126);
 line(449,149,311,149);
 line(449,149,449,126);
 setcolor(DARKGRAY);
 line(130,125,130,150);
 line(130,125,200,125);
 line(310,125,310,150);
 line(310,125,450,125);

 line(30,160,470,160);
 setcolor(WHITE);
 line(30,161,470,161);
 setcolor(DARKGRAY);
 outtextxy(30,200,"Enter your name (10 char max)");
  outtextxy(30,270,"Enter your balance (1000 min)");
  outtextxy(30,340,"Enter your address (25 char max)");
 setcolor(WHITE);
 rectangle(300,190,470,210);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,195,WHITE);
 line(472,212,472,189);
 line(472,212,299,212);
 setcolor(DARKGRAY);
 line(300,190,300,210);
 line(300,190,470,190);
 line(299,189,299,211);
 line(299,189,471,189);
  setcolor(WHITE);
 rectangle(300,260,470,280);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,265,WHITE);
 line(472,282,472,259);
 line(472,282,299,282);
 setcolor(DARKGRAY);
 line(300,260,300,280);
 line(300,260,470,260);
 line(299,259,299,281);
 line(299,259,471,259);
  setcolor(WHITE);
 rectangle(300,330,470,350);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,335,WHITE);
 line(472,352,472,329);
 line(472,352,299,352);
 setcolor(DARKGRAY);
 line(300,330,300,350);
 line(300,330,470,330);
 line(299,329,299,351);
 line(299,329,471,329);
 }
void list_all(void){
struct date d;
getdate(&d);
list_all_gui();
ifstream pfile("main");
int count=0;
char string[10];
while(string[0]!=NULL){
pfile>>string;
++count;
}
--count;
pfile.close();
ifstream pfile2("main");
for(int var=count;var>0;--var)
{
pfile2>>string;
if((var!=count)&&(string!=NULL))
print_it(string);
}
pfile2.close();

gotoxy(80,25);
getch();
cleardevice();
closegraph();
process();
}
void print_it(char *name){
static value=0;
char address[25];
char account_no[5];
char balance[5];
char withdraw[30];
char date[20];
char deposit[30];
ifstream pfile(name);
pfile>>account_no;
pfile>>name;
pfile>>balance;
pfile>>address;
pfile>>date;
pfile>>deposit;
pfile>>withdraw;
pfile.close();
gotoxy(6,10+value);
cout<<"#";
gotoxy(10,value+10);
cout<<account_no;
gotoxy(14,value+10);
cout<<name;
gotoxy(25,value+10);
cout<<balance;
gotoxy(35,value+10);
cout<<address;
gotoxy(50,value+10);
cout<<date;
++value;
}
void list_all_gui(void){
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,300,100);
setcolor(WHITE);
line(9,69,9,100);
line(10,69,300,69);
setcolor(DARKGRAY);
outtextxy(30,80,"A C C O U N T  L I S T I N G S");
setcolor(WHITE);
rectangle(30,110,610,450);
setfillstyle(SOLID_FILL,WHITE);
floodfill(35,115,WHITE);
line(612,452,612,109);
line(612,452,29,452);
setcolor(DARKGRAY);
line(30,110,30,450);
line(30,110,610,110);
line(29,110,29,450);
line(29,109,610,109);
}
void trans_menu(void)
{
int check;
check=trans_gui();

if(check==1)
{
show_trans();
see_it();
}
if(check==2)
{
mod_choice();
}
getch();
cleardevice();
closegraph();
process();
}
int trans_gui(void){
int dr=9,mode=2,option;
initgraph(&dr,&mode,"..\\bgi");
void *main_menu,*button_down;
int size;
size=imagesize(10,110,251,201);
main_menu=malloc(size);
size=imagesize(10,310,251,351);
button_down=malloc(size);
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,300,100);
setcolor(WHITE);
line(9,69,9,100);
line(10,69,300,69);
setcolor(DARKGRAY);
outtextxy(30,80,"  ACCOUNT  TRANSACTION  MENU");
setcolor(DARKGRAY);
rectangle(10,110,250,150);
setcolor(BLACK);
rectangle(10,110,251,151);
setcolor(WHITE);
line(10,110,10,150);
line(10,110,250,110);
setcolor(BLACK);
outtextxy(40,130,"1. View transaction");
setcolor(DARKGRAY);
rectangle(10,160,250,200);
setcolor(BLACK);
rectangle(10,160,251,201);
setcolor(WHITE);
line(10,160,10,200);
line(10,160,250,160);
setcolor(BLACK);
outtextxy(40,180,"2. Modify transaction");
getimage(10,110,251,201,main_menu);

setcolor(WHITE);
rectangle(10,310,251,351);
setcolor(DARKGRAY);
line(10,310,10,350);
line(11,311,11,350);
line(10,310,250,310);
line(11,311,250,311);
setcolor(BLACK);
getimage(10,310,251,351,button_down);
rectangle(10,310,251,351);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,315,BLACK);

setcolor(LIGHTGRAY);
rectangle(10,310,251,351);
setcolor(BLACK);
char check;
check=getch();
if(check==49)
{
putimage(10,110,main_menu,COPY_PUT);
putimage(10,110,button_down,COPY_PUT);
outtextxy(40,130,"1. View transaction");
option=1;
delay(600);
}
if(check==50)
{
putimage(10,110,main_menu,COPY_PUT);
putimage(10,160,button_down,COPY_PUT);
outtextxy(40,180,"2. Modify transaction");
option=2;
delay(600);
}
free(main_menu);
free(button_down);
cleardevice();
closegraph();
return(option);
}
void show_trans(void)
{
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,200,100);
 outtextxy(20,80,"SHOW TRANSACTION");
 setcolor(WHITE);
 line(9,70,9,100);
 line(10,69,200,69);
 setcolor(DARKGRAY);
 line(30,170,610,170);
 setcolor(WHITE);
 line(30,171,610,171);
 setcolor(DARKGRAY);
 outtextxy(30,200,"Enter your account holder's name");
  setcolor(WHITE);
 rectangle(300,190,470,210);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,195,WHITE);
 line(472,212,472,189);
 line(472,212,299,212);
 setcolor(DARKGRAY);
 line(300,190,300,210);
 line(300,190,470,190);
 line(299,189,299,211);
 line(299,189,471,189);
 }
 void mod_trans(void)
 {
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,200,100);
 outtextxy(20,80,"MODIFY ACCOUNT");
 setcolor(WHITE);
 line(9,70,9,100);
 line(10,69,200,69);
 setcolor(DARKGRAY);
 line(30,170,610,170);
 setcolor(WHITE);
 line(30,171,610,171);
 setcolor(DARKGRAY);
 outtextxy(30,200,"Enter your account holder's name");
  setcolor(WHITE);
 rectangle(300,190,470,210);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,195,WHITE);
 line(472,212,472,189);
 line(472,212,299,212);
 setcolor(DARKGRAY);
 line(300,190,300,210);
 line(300,190,470,190);
 line(299,189,299,211);
 line(299,189,471,189);
 }
void see_it(void){
char name[10];
char address[25];
char account_no[5];
char balance[5];
char withdraw[30];
char date[20];
char deposit[30];
gotoxy(40,13);
cout<<" ";
cin>>name;
ifstream pfile(name);
pfile>>account_no;
pfile>>name;
pfile>>balance;
pfile>>address;
pfile>>date;
pfile>>deposit;
pfile>>withdraw;
pfile.close();
report();
gotoxy(20,10);
cout<<"ACCOUNT HOLDER NAME: "<<name<<endl;
gotoxy(20,11);
cout<<"DATE OF ISSUE: "<<date<<endl;
gotoxy(20,12);
cout<<"BALANCE LEFT: "<<balance<<endl;
gotoxy(20,13);
cout<<"ADDRESS: "<<address<<endl;
cout<<endl;
gotoxy(20,15);
cout<<"TRANSACTION REPORT"<<endl;
gotoxy(20,16);
cout<<"DEPOSIT REPORT: "<<deposit<<endl;
gotoxy(20,17);
cout<<"WITH DRAW REPORT: "<<withdraw<<endl;
}
void report(void)
{
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,300,100);
setcolor(WHITE);
line(9,69,9,100);
line(10,69,300,69);
setcolor(DARKGRAY);
outtextxy(30,80,"TRANSACTION REPORT");
setcolor(WHITE);
rectangle(30,110,610,450);
setfillstyle(SOLID_FILL,WHITE);
floodfill(35,115,WHITE);
line(612,452,612,109);
line(612,452,29,452);
setcolor(DARKGRAY);
line(30,110,30,450);
line(30,110,610,110);
line(29,110,29,450);
line(29,109,610,109);
}
void deposite(void){
char name[10];
gotoxy(40,13);
cout<<" ";
cin>>name;
int val_dep;
char tmp_dep[5];
char address[25];
char dat[10];
char deposit[30];
char withdraw[40];
int  account_no;
int balance;
ifstream pfile(name);
pfile>>account_no;
pfile>>name;
pfile>>balance;
pfile>>address;
pfile>>dat;
pfile>>deposit;
pfile>>withdraw;
dep_gui();
gotoxy(5,8);
cout<<account_no<<name<<balance<<dat<<deposit<<address<<withdraw<<endl;
pfile.close();
strcat(deposit,"#");
gotoxy(40,13);
cout<<" ";
cin>>tmp_dep;
strcat(deposit,tmp_dep);
val_dep=atoi(tmp_dep);
balance+=val_dep;
ofstream pfile2(name);
pfile2<<account_no<<endl;
pfile2<<name<<endl;
pfile2<<balance<<endl;
pfile2<<address<<endl;
pfile2<<dat<<endl;
pfile2<<deposit<<endl;
pfile2<<withdraw;
pfile2.close();
cleardevice();
closegraph();
process();
}
void dep_gui(void)
{
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,200,100);
 outtextxy(20,80,"MODIFY ACCOUNT");
   setcolor(WHITE);
 rectangle(30,110,610,130);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,115,WHITE);
 line(612,132,612,109);
 line(612,132,29,132);
 setcolor(DARKGRAY);
 line(30,110,30,130);
 line(30,110,610,110);
 line(29,109,29,131);
 line(29,109,611,109);
 setcolor(WHITE);
 line(9,70,9,100);
 line(10,69,200,69);
 setcolor(DARKGRAY);
 line(30,170,610,170);
 setcolor(WHITE);
 line(30,171,610,171);
 setcolor(DARKGRAY);
 outtextxy(30,200,"Enter the amount to deposite");
  setcolor(WHITE);
 rectangle(300,190,470,210);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(310,195,WHITE);
 line(472,212,472,189);
 line(472,212,299,212);
 setcolor(DARKGRAY);
 line(300,190,300,210);
 line(300,190,470,190);
 line(299,189,299,211);
 line(299,189,471,189);
 }
int mod_menu(void)
{
int dr=9,mode=2;
initgraph(&dr,&mode,"..\\bgi");
void *main_menu,*button_down;
int size;
size=imagesize(10,110,251,201);
main_menu=malloc(size);
size=imagesize(10,310,251,351);
button_down=malloc(size);
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(DARKGRAY);
rectangle(1,1,640,480);
floodfill(3,3,DARKGRAY);
setcolor(WHITE);
line(1,1,1,480);
line(1,1,640,1);
setcolor(BLUE);
rectangle(3,3,637,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(5,5,BLUE);
setcolor(DARKGRAY);
rectangle(620,4,635,14);
rectangle(602,4,617,14);
rectangle(585,4,599,14);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(586,6,DARKGRAY);
floodfill(604,6,DARKGRAY);
floodfill(624,6,DARKGRAY);
setcolor(BLACK);
line(622,6,633,12);
line(633,6,622,12);
rectangle(604,6,615,12);
line(587,12,597,12);
setcolor(WHITE);
line(620,4,620,14);
line(620,4,635,4);
line(602,4,617,4);
line(602,4,602,14);
line(584,4,599,4);
line(584,4,584,14);
outtextxy(8,5,"BANKING SYSTEM");
setcolor(WHITE);
line(5,30,635,30);
line(5,60,635,60);
setcolor(DARKGRAY);
line(5,29,635,29);
line(5,59,635,59);
setcolor(DARKGRAY);
outtextxy(40,40,"B A N K I N G   S Y S T E M  designed for national bank of pakistan");
rectangle(10,70,300,100);
setcolor(WHITE);
line(9,69,9,100);
line(10,69,300,69);
setcolor(DARKGRAY);
outtextxy(30,80,"MODIFY ACCOUNT");
setcolor(DARKGRAY);
rectangle(10,110,250,150);
setcolor(BLACK);
rectangle(10,110,251,151);
setcolor(WHITE);
line(10,110,10,150);
line(10,110,250,110);
setcolor(BLACK);
outtextxy(40,130,"1. Want to deposite");
setcolor(DARKGRAY);
rectangle(10,160,250,200);
setcolor(BLACK);
rectangle(10,160,251,201);
setcolor(WHITE);
line(10,160,10,200);
line(10,160,250,160);
setcolor(BLACK);
outtextxy(40,180,"2. Want to withdraw");
getimage(10,110,251,201,main_menu);

setcolor(WHITE);
rectangle(10,310,251,351);
setcolor(DARKGRAY);
line(10,310,10,350);
line(11,311,11,350);
line(10,310,250,310);
line(11,311,250,311);
setcolor(BLACK);
getimage(10,310,251,351,button_down);
rectangle(10,310,251,351);
setfillstyle(SOLID_FILL,LIGHTGRAY);
floodfill(15,315,BLACK);
int option;
setcolor(LIGHTGRAY);
rectangle(10,310,251,351);
setcolor(BLACK);
char check;
check=getch();
if(check==49)
{
putimage(10,110,main_menu,COPY_PUT);
putimage(10,110,button_down,COPY_PUT);
outtextxy(40,130,"1. Want to deposite");
option=1;
delay(600);
}
if(check==50)
{
putimage(10,110,main_menu,COPY_PUT);
putimage(10,160,button_down,COPY_PUT);
outtextxy(40,180,"2. Want to withdraw");
option=2;
delay(600);
}
free(main_menu);
free(button_down);
return(option);
}
void mod_choice(void)
{
int check;
check=mod_menu();
if(check==1)
{
mod_trans();
deposite();
}
if(check==2)
{
mod_trans();
withdraw();
}
}
void withdraw(void){
int tmp;
char name[10];
char tmp_with[10];
char address[25];
char dat[10];
char deposit[40];
char withdraw[40];
int  account_no;
int balance;
gotoxy(40,13);
cout<<" ";
cin>>name;
ifstream pfile(name);
pfile>>account_no;
pfile>>name;
pfile>>balance;
pfile>>address;
pfile>>dat;
pfile>>deposit;
pfile>>withdraw;
withdraw[0]=32;
cout<<account_no<<name<<balance<<dat<<deposit<<address<<withdraw<<endl;
pfile.close();
strcat(withdraw,"#");
gotoxy(40,13);
cout<<" ";
cin>>tmp;
itoa(tmp,tmp_with,10);
strcat(withdraw,tmp_with);
balance-=tmp;
ofstream pfile2(name);
pfile2<<account_no<<endl;
pfile2<<name<<endl;
pfile2<<balance<<endl;
pfile2<<address<<endl;
pfile2<<dat<<endl;
pfile2<<deposit<<endl;
pfile2<<withdraw;
pfile2.close();
cleardevice();
closegraph();
process();
}