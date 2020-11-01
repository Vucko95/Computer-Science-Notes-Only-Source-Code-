/*
Title:MyPiano.exe
Compiler Used:Turbo C++ 3.0

System Requirements:
Pentium Processor,1 MB HDD,32 MB RAM,Serial Mouse
EGAVGA supported card(16 colors)
Resolution:640 X 480

Source File:MyPiano.cpp
Graphics Driver:EGAVGA.BGI

Credits:
Renjith Joseph
Application Progammer & Designer

Licence:Unregistered copy
Previous Version:GPIANO.exe

 New Features:
* Improved Graphics Quality
* Ease of use
* Exciting controls
* Permanent skin control settings
* System lock facility
* More options
* Frequecy graph & 2D spectrum
* Log file tracing,viewing and clearing facility
* One touch recording
* Detailed help
* Online assistance

Details and functions of support files used:
-
-
-
-
-
-
-

*/

		/* Source code of MyPiano.cpp; compiled in TC++ 3.0.*/

//Including all requied libraries
#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
//Defining variables
#define OFF 0
#define ON 1
#define MAINWINDOW 0
#define RECORDWINDOW 1
#define OPTIONSWINDOW 2
#define HELPWINDOW 3
#define EXITWINDOW 4
class Graphics
		 {
		  public:
		  REGS regs;
		  //For opening multiwindow
		  void initGraphics()
				  {
					int gd=DETECT,gm;initgraph(&gd,&gm,"");
				  }
		  void initTextMode()
				  {
					textmode(3);
				  }

		  void drawButton(int,int,char[],int);
		  void drawCloseButton(int,int,char[],int);
		  void drawMsgBox(int,int,char[]);
		  void drawErrorBox(int,int,char[]);
		  void playBeep();
		  //Mouse Control Functions
		  void initMouse();
		  void showMouse();
		  void hideMouse();
		 };
void Graphics::drawButton(int x,int y,char caption[20],int clicked)
		{
		 //Hiding Mouse
		 hideMouse();
		 int length=strlen(caption);
		 bar(x,y,x+(length*10),y+18);
		 outtextxy(x+15,y+5,caption);
		 //3D effect
		 if(clicked==0)
			{
			 setcolor(15);
			 line(x,y,x+(length*10),y);line(x,y,x,y+18);
			 setcolor(0);
			 line(x,y+18,x+(length*10),y+18);
			 line(x+(length*10),y,x+(length*10),y+18);
			}
		 else
			{
			 setcolor(0);
			 line(x,y,x+(length*10),y);line(x,y,x,y+18);
			 setcolor(15);
			 line(x,y+18,x+(length*10),y+18);
			 line(x+(length*10),y,x+(length*10),y+18);
			 delay(10);
			 setcolor(15);
			 line(x,y,x+(length*10),y);line(x,y,x,y+18);
			 setcolor(0);
			 line(x,y+18,x+(length*10),y+18);
			 line(x+(length*10),y,x+(length*10),y+18);
			 setlinestyle(0,0,0);
			 setcolor(7);rectangle(x+3,y+3,x+(length*10)-3,y+15);
			 setlinestyle(0,0,0);
			}
		 //Showing Mouse
		 showMouse();
		}

void Graphics::drawCloseButton(int x,int y,char caption[20],int clicked)
		{
		 //Hiding Mouse
		 hideMouse();
		 bar(x,y,x+12,y+12);setcolor(15);
		 outtextxy(x+3,y+3,caption);
		 //3D effect
		 if(clicked==0)
			{
			 setcolor(15);
			 line(x,y,x+12,y);line(x,y,x,y+12);
			 setcolor(0);
			 line(x,y+12,x+12,y+12);
			 line(x+12,y,x+12,y+12);
			}
		 else
			{
			 hideMouse();
			 setcolor(0);
			 line(x,y,x+12,y);line(x,y,x,y+12);
			 setcolor(15);
			 line(x,y+12,x+12,y+12);
			 line(x+12,y,x+12,y+12);
			 delay(100);
			 setcolor(15);
			 line(x,y,x+12,y);line(x,y,x,y+12);
			 setcolor(0);
			 line(x,y+12,x+12,y+12);
			 line(x+12,y,x+12,y+12);
			}
		 //Showing Mouse
		 showMouse();
		}


void Graphics::drawMsgBox(int x,int y,char *msg)
		{
		  //Hiding Mouse
		  hideMouse();
		  //Drawing message box
		  setfillstyle(1,7);bar(x,y,x+210,y+80);
		  //title bar
		  setfillstyle(1,1);bar(x,y,x+210,y+20);
		  //Close button
		  setcolor(15);outtextxy(x+196,y+8,"X");
		  line(x+192,y+5,x+205,y+5);line(x+192,y+5,x+192,y+17);
		  setcolor(8);
		  line(x+192,y+17,x+205,y+17);line(x+205,y+6,x+205,y+17);
		  //3D effect
		  setcolor(15);
		  line(x,y,x+210,y);line(x,y,x,y+80);
		  setcolor(0);
		  line(x+210,y,x+210,y+80);line(x,y+80,x+210,y+80);
		  setcolor(11);outtextxy(x+5,y+7,"My Piano 3.0");
		  //Printing caption
		  setcolor(15);outtextxy(x+45,y+30,msg);
		  //drawing information symbol
		  settextstyle(1,0,1);
		  setcolor(0);
		  setfillstyle(1,1);fillellipse(x+20,y+40,14,14);
		  setcolor(14);outtextxy(x+17,y+36,"I");
		  //Drawing button
		  setfillstyle(1,7);setcolor(15);
		  drawButton(x+80,y+55," OK   ",0);
		  //Showing Mouse
		  showMouse();
		  getch();
		  setfillstyle(1,8);setcolor(15);
		  drawButton(x+80,y+55," OK   ",1);
		  //Showing Mouse
		  showMouse();
		}


void Graphics::drawErrorBox(int x,int y,char *msg)
		{
		  //Hiding Mouse
		  hideMouse();
		  //Drawing message box
		  setfillstyle(1,7);bar(x,y,x+260,y+80);
		  //title bar
		  setfillstyle(1,1);bar(x,y,x+260,y+20);
		  //Close button
		  //3D effect
		  setcolor(15);
		  line(x,y,x+260,y);line(x,y,x,y+80);
		  setcolor(7);
		  line(x+260,y,x+260,y+80);line(x,y+80,x+260,y+80);
		  setcolor(15);outtextxy(x+5,y+7,"ERROR");
		  //Printing caption
		  setcolor(15);outtextxy(x+45,y+30,msg);
		  //drawing information symbol
		  settextstyle(1,0,1);
		  setcolor(0);
		  setfillstyle(1,4);fillellipse(x+20,y+40,14,14);
		  setcolor(15);outtextxy(x+17,y+36,"X");
		  //Drawing button
		  setfillstyle(1,7);setcolor(14);
		  drawButton(x+100,y+55," OK   ",0);
		  //Showing Mouse
		  showMouse();
		  getch();
		  setfillstyle(1,8);setcolor(14);
		  drawButton(x+100,y+55," OK   ",1);
		  //Showing Mouse
		  showMouse();
		}

void Graphics::playBeep()
		{
		 sound(1000);delay(300);nosound();
		 getch();
		}




void Graphics::initMouse()
		{regs.x.ax=0;int86(0x33,&regs,&regs);}
void Graphics::showMouse()
		{
		 regs.x.ax=1;int86(0x33,&regs,&regs);
		 regs.x.ax=3;int86(0x33,&regs,&regs);
		}
void Graphics::hideMouse()
		{
		 regs.x.ax=2;int86(0x33,&regs,&regs);
		}

class Database
		 {
		  public:
		  unsigned int sound_flag;
		  unsigned int time_delay;
		  int system_status;
		  unsigned int current_freq;
		  unsigned int freq_buffer[21];
		  //values for storing skin colors
		  FILE *f_skin,*f_mini_show;
		  FILE *log;
		  FILE *pwd_flag;
		  FILE *pwd;
		  FILE *reg;
		  FILE *record;
		  int record_buffer[200];
		  char filename[12];
		  int reg_status;
		  int rec_flag;
		  char pass[8];
		  int mini_show;
		  char password[8];
		  int pwd_enabled;
		  int bug;
		  int f_skin_control_panel;
		  void initValues();
		  void skinControl();
		  void createLog(char[]);
		 };
void Database::initValues()
		{
		 sound_flag=1;
		 time_delay=50;
		 system_status=ON;
		 current_freq=100;
		 rec_flag=0;
		 bug=0;
		 for(int buffer_count=0;buffer_count<=21;buffer_count++)
			{
			 freq_buffer[buffer_count]=100;
			}
		 //Opening registraion file for status
		 reg=fopen("reg.reg","r");
		 reg_status=getw(reg);
		 /*
		 //Creating reg code
		 reg=fopen("reg.reg","w");
		 putw(1980,reg);
		 */
		 fclose(reg);
		}

void Database::skinControl()
		{
		 //Opening support files
		 //Skin_1.skn: for control panel color
		 //Skin_2.skn: for mini window color
		 //Skin_3.skn: for mini window show option
		 //Default color
		 f_skin=fopen("skin_1.skn","r");
		 f_skin_control_panel=getw(f_skin);
		 fclose(f_skin);
		 /*opening mini window show file*/
		 f_mini_show=fopen("skin_3.skn","r");
		 mini_show=getw(f_mini_show);
		 fclose(f_mini_show);
		}

void Database::createLog(char *msg)
		{
		 time_t times;time(&times);
		 log=fopen("log.log","a+");
		 fputs(msg,log);fputs(ctime(&times),log);
		 fclose(log);
		}


class MyPiano:private Graphics,public Database
		 {
		  public:
		  //For storing button count in Options Window
		  int main_v;
		  int btn_h;
		  int btn_v;
		  int pwd_h,pwd_v;
		  int rec_h;
		  int win_flag;
		  int rec_count;
		  int play_flag;
		  int play_count;
		  MyPiano()
				 {
				  initGraphics();
				  initValues();
				  main_v=0;
				  btn_h=0;
				  btn_v=0;
				  pwd_h=0,pwd_v=0;
				  rec_h=0;
				  rec_count=0;
				  play_flag=0;
				  play_count=0;
				  skinControl();
				  //Initializing Mouse driver
				  initMouse();
				 }
		  //Mouse Control Function
		  void readMouse();
		  void loadFiles();
		  void checkPassword();
		  void mainWindow();
		  void userKeyPress(char);
		  void optionsWindow();
		  void recordWindow();
		  void recordBox();
		  void playBox();
		  void helpWindow();
		  void playSound(int);
		  void drawMainBody();
		  void drawControlPanel();
		  void drawMiniWindow();
		  void pwdWindow();
		  void regWindow();
		  void aboutWindow();
		  void printTime();
		  void drawSpectrum();
		  void drawGraph();
		  void drawSwitchPanel();
		  void drawSwitch(int,int,double);
		  void drawProgressBar(int,int,int,int);
		 };

void MyPiano::readMouse()
		{
		/*
		 Mouse is restricted to main window only.
		 Next version includes mouse control every.
		 I made functions for show and hide mouse.
		 it helps to present paths. if we are not using
		 hide mouse . it makes some problem with graphics.
		*/
		 showMouse();
		 //Record Button Click Reading
		 if(regs.x.cx>485&&regs.x.cx<575&&regs.x.dx>=80&&regs.x.dx<95&&regs.x.bx==1&&win_flag==MAINWINDOW)
		  {
			main_v=0;
			//Button Click Effect Setting
			setcolor(15);setfillstyle(1,1);
			drawButton(489,78," Record  ",1);
			recordWindow();mainWindow();
		  }
		//Options Button Clicking
		if(regs.x.cx>485&&regs.x.cx<575&&regs.x.dx>=98&&regs.x.dx<112&&regs.x.bx==1&&win_flag==MAINWINDOW)
		 {
			main_v=1;
		  //Click Effect
			setcolor(15);setfillstyle(1,1);
			setcolor(15);
			drawButton(489,95," Options ",1);
		  optionsWindow();mainWindow();
		 }
		//Help button clicking
		if(regs.x.cx>485&&regs.x.cx<575&&regs.x.dx>=115&&regs.x.dx<130&&regs.x.bx==1&&win_flag==MAINWINDOW)
		 {
		  main_v=2;
		  //Click Effect
		  setcolor(15);setfillstyle(1,1);
		  setcolor(15);
		  drawButton(489,113,"  Help   ",1);
		  helpWindow();mainWindow();
		 }
		//Reading mouse click for close button in main window
		if(regs.x.cx>565&&regs.x.cx<575&&regs.x.dx>=58&&regs.x.dx<68&&regs.x.bx==1&&win_flag==MAINWINDOW)
		 {
		  setfillstyle(1,8);
		  drawCloseButton(565,58,"X",1);
		  fcloseall();
		  //Logging
		  createLog("Exited:");
		  closegraph();exit(0);
		 }
	  //Reading mouse click for Help button in main window
	  if(regs.x.cx>550&&regs.x.cx<560&&regs.x.dx>=58&&regs.x.dx<68&&regs.x.bx==1&&win_flag==MAINWINDOW)
		 {
		  //Click Effect
		  setfillstyle(1,8);
		  drawCloseButton(550,58,"?",1);
		  //Logging
		  createLog("Help Window Opened:");
		  setcolor(15);setfillstyle(1,1);
		  drawButton(489,113,"  Help   ",1);
		  helpWindow();
		  mainWindow();
		 }
		//Reading mouse click for Help button in main window
		if(regs.x.cx>168&&regs.x.cx<180&&regs.x.dx>=308&&regs.x.dx<316&&regs.x.bx==1&&mini_show==1)
		  {
			setfillstyle(1,f_skin_control_panel);
			drawCloseButton(168,305,"X",1);
			cleardevice();mini_show=0;mainWindow();
		  }
		/********************************************************************/
		//Reading mouse for piano switches
		if(regs.x.cx>60&&regs.x.cx<80&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('q');
			}
		if(regs.x.cx>82&&regs.x.cx<100&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('w');
			}
		if(regs.x.cx>102&&regs.x.cx<120&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('e');
			}
		if(regs.x.cx>122&&regs.x.cx<140&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('r');
			}
		if(regs.x.cx>142&&regs.x.cx<158&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('t');
			}
		if(regs.x.cx>162&&regs.x.cx<178&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('y');
			}
		if(regs.x.cx>180&&regs.x.cx<198&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('u');
			}
		if(regs.x.cx>200&&regs.x.cx<218&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('i');
			}
		if(regs.x.cx>220&&regs.x.cx<238&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('o');
			}
		if(regs.x.cx>240&&regs.x.cx<258&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('p');
			}
		if(regs.x.cx>260&&regs.x.cx<278&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('[');
			}
		if(regs.x.cx>280&&regs.x.cx<298&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress(']');
			}

		if(regs.x.cx>300&&regs.x.cx<318&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('a');
			}
		if(regs.x.cx>320&&regs.x.cx<338&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('s');
			}
		if(regs.x.cx>340&&regs.x.cx<358&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('d');
			}


		if(regs.x.cx>360&&regs.x.cx<378&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('f');
			}
		if(regs.x.cx>380&&regs.x.cx<398&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('g');
			}
		if(regs.x.cx>400&&regs.x.cx<418&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('h');
			}
		if(regs.x.cx>420&&regs.x.cx<438&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('j');
			}
		if(regs.x.cx>440&&regs.x.cx<458&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('k');
			}
		if(regs.x.cx>460&&regs.x.cx<478&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('l');
			}
		if(regs.x.cx>480&&regs.x.cx<498&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress(';');
			}
		if(regs.x.cx>500&&regs.x.cx<518&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('z');
			}
		if(regs.x.cx>520&&regs.x.cx<538&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('x');
			}
		if(regs.x.cx>540&&regs.x.cx<558&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('c');
			}
		if(regs.x.cx>560&&regs.x.cx<578&&regs.x.dx>=165&&regs.x.dx<298&&regs.x.bx==1&&mini_show==1)
			{
			 userKeyPress('v');
			}




	  }//Closing Read Mouse Function



void MyPiano::loadFiles()
					{
					 initGraphics();
					 //Drawing main window
					 setfillstyle(1,0);bar(50,50,590,425);
					 setcolor(15);
					 line(50,50,590,50);line(50,50,50,425);
					 setcolor(8);
					 line(50,425,590,425);line(590,50,590,425);
					 //Printing title
					 settextstyle(8,0,7);setcolor(15);
					 for(int i=0;i<20;i++)
					  {outtextxy(110-i,100-i,"MYPiano 3.0");}
					 setcolor(1);
					 for(i=0;i<20;i++)
					  {outtextxy(90+i,80+i,"MYPiano 3.0");}
					 setcolor(11);
					 outtextxy(90+i,80+i,"MYPiano 3.0");
					 //Printing programming details

					 //Loading and verifying files
					 setcolor(15);rectangle(51,300,588,423);
					 settextstyle(0,0,0);setcolor(11);
					 outtextxy(60,290,"Checking for support files...");
					 //Drawing checking box
					 setfillstyle(1,0);bar(52,301,587,422);
					 //Checking files
					 setcolor(15);
					 FILE *check;
					 //EGAVGA.BGI
					 outtextxy(60,310,"Egavga.Bgi...");
					 check=fopen("Egavga.bgi","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,310,"Egavga.Bgi... Done    Driver");}
					 else
					  {drawErrorBox(200,200,"EGAVGA.BGI File Missing.");exit(0);}
					 //PWD.PWD
					 outtextxy(60,320,"Pwd.Pwd...");
					 check=fopen("pwd.pwd","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,320,"Pwd.Pwd... Done       System File");}
					 else
					  {drawErrorBox(200,200,"Pwd.pwd File Missing.");exit(0);}
					 //Pwd_flag.pwd
					 outtextxy(60,330,"Pwd_flag.pwd...");
					 check=fopen("Pwd_flag.pwd","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,330,"Pwd_flag.pwd... Done  System File");}
					 else
					  {drawErrorBox(200,200,"Pwd_Flag.pwd File Missing.");exit(0);}
					 //Skin_1.skn
					 outtextxy(60,340,"Skin_1.skn...");
					 check=fopen("Skin_1.skn","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,340,"Skin_1.skn... Done    Skin File");}
					 else
					  {drawErrorBox(200,200,"Skin_1.Skn File Missing.");exit(0);}
					 //Skin_2.skn
					 outtextxy(60,350,"Skin_3.skn...");
					 check=fopen("Skin_3.skn","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,350,"Skin_2.skn... Done    Skin File");}
					 else
					  {drawErrorBox(200,200,"Skin_3.Skn File Missing.");exit(0);}
					 //Reg.reg
					 outtextxy(60,360,"Reg.Reg...");
					 check=fopen("reg.reg","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,360,"Reg.Reg... Done       System File ");}
					 else
					  {drawErrorBox(200,200,"Reg.Reg File Missing.");exit(0);}
					 //Log.Log
					 outtextxy(60,370,"Log.Log...");
					 check=fopen("log.log","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,370,"Log.Log... Done       Log File");}
					 else
					  {drawErrorBox(200,200,"Log.Log File Missing.");exit(0);}
					 //Bold.chr
					 outtextxy(60,380,"Bold.Chr...");
					 check=fopen("Bold.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,380,"Bold.Chr... Done      Font File");}
					 else
					  {drawErrorBox(200,200,"Bold.Chr File Missing.");exit(0);}
					 //Euro.chr
					 outtextxy(60,390,"Euro.Chr...");
					 check=fopen("Euro.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,390,"Euro.Chr... Done      Font File");}
					 else
					  {drawErrorBox(200,200,"Euro.Chr File Missing.");exit(0);}
					 //Goth.chr
					 outtextxy(60,400,"Goth.Chr...");
					 check=fopen("Goth.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,400,"Goth.Chr... Done      Font File");}
					 else
					  {drawErrorBox(200,200,"Goth.Chr File Missing.");exit(0);}
					 //Lcom.chr
					 outtextxy(60,410,"Lcom.Chr...");
					 check=fopen("Lcom.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(60,410,"Lcom.Chr... Done      Font File");}
					 else
					  {drawErrorBox(200,200,"Lcom.Chr File Missing.");exit(0);}
					 //Litt.chr
					 outtextxy(360,310,"Litt.Chr...");
					 check=fopen("Litt.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(360,310,"Litt.Chr... Done  Font File");}
					 else
					  {drawErrorBox(200,200,"Litt.Chr File Missing.");exit(0);}
					 //Sans.chr
					 outtextxy(360,320,"Sans.Chr...");
					 check=fopen("Sans.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(360,320,"Sans.Chr... Done  Font File");}
					 else
					  {drawErrorBox(200,200,"Sans.Chr File Missing.");exit(0);}
					 //Scri.chr
					 outtextxy(360,330,"Scri.Chr...");
					 check=fopen("Scri.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(360,330,"Scri.Chr... Done  Font File");}
					 else
					  {drawErrorBox(200,200,"Scri.Chr File Missing.");exit(0);}
					 //Simp.chr
					 outtextxy(360,340,"Simp.Chr...");
					 check=fopen("Simp.chr","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(360,340,"Simp.Chr... Done  Font File");}
					 else
					  {drawErrorBox(200,200,"Simp.Chr File Missing.");exit(0);}
					 //HowtoU~1.txt
					 outtextxy(360,350,"HowtoU~1.txt...");
					 check=fopen("HowtoU~1.txt","r");delay(200);fclose(check);
					 if(check!=NULL){outtextxy(360,350,"HowtoU~1.txt... Done");}
					 else
					  {drawErrorBox(200,200,"HowtoU~1.txtFile Missing.");exit(0);}



					 //System Status
					 outtextxy(360,370,"Checking Completed.Status:OK");
					 outtextxy(360,390,"Loading...");
					 //Loading bar
					 setfillstyle(1,7);
					 for(int count=0;count<=20;count++)
					  {drawProgressBar(360,400,count,10);delay(random(100));}
					  cleardevice();mainWindow();
					}




void MyPiano::checkPassword()
					{
					  initTextMode();
					  //Opening password enabled file
					  pwd_flag=fopen("pwd_flag.pwd","r");
					  pwd_enabled=getw(pwd_flag);
					  fclose(pwd_flag);
					  //Opening password stored file
					  pwd=fopen("pwd.pwd","r");
					  fgets(password,9,pwd);
					  fclose(pwd);
					  //checking for password enabled flag
					  Check:
					  char *pass;
					  if(pwd_enabled==1)
						{
						 //Asking Password
						 gotoxy(30,15);cout<<"User Password:";
						 gets(pass);
						 int cmp=strcmp(password,pass);
						 //Compared value if Same
						 if(cmp==0){loadFiles();}
						 //If password are wrong
						 else
							{
							 clrscr();
							 gotoxy(30,15);cout<<"Invalid Password";
							 sound(1000);delay(100);
							 nosound();clrscr();
							 checkPassword();
							}
						 }
					 //If passwords are disabled open piano
					 else
						 {loadFiles();}
					}



void MyPiano::userKeyPress(char input)
					{
					  switch(input)
							  {
								//Key press Music Playing
								case 'q':
								drawSwitch(61,165,9);
								playSound(100);
								break;
								case 'w':
								drawSwitch(81,165,9);
								playSound(120);
								break;
								case'e':
								drawSwitch(101,165,9);
								playSound(150);
								break;
								case 'r':
								drawSwitch(121,165,9);
								playSound(170);
								break;
								case 't':
								drawSwitch(141,165,9);
								playSound(190);
								break;
								case 'y':
								drawSwitch(161,165,9);
								playSound(210);
								break;
								case 'u':
								drawSwitch(181,165,9);
								playSound(230);
								break;
								case 'i':
								drawSwitch(201,165,9);
								playSound(250);
								break;
								case 'o':
								drawSwitch(221,165,9);
								playSound(270);
								break;
								case 'p':
								drawSwitch(241,165,9);
								playSound(290);
								break;
								case '[':
								drawSwitch(261,165,9);
								playSound(310);
								break;
								case ']':
								drawSwitch(281,165,9);
								playSound(330);
								break;
								case 'a':
								drawSwitch(301,165,9);
								playSound(350);
								break;
								case 's':
								drawSwitch(321,165,9);
								playSound(370);
								break;
								case 'd':
								drawSwitch(341,165,9);
								playSound(390);
								break;
								case 'f':
								drawSwitch(361,165,9);
								playSound(410);
								break;
								case 'g':
								drawSwitch(381,165,9);
								playSound(430);
								break;
								case 'h':
								drawSwitch(401,165,9);
								playSound(450);
								break;
								case 'j':
								drawSwitch(421,165,9);
								playSound(470);
								break;
								case 'k':
								drawSwitch(441,165,9);
								playSound(490);
								break;
								case 'l':
								drawSwitch(461,165,9);
								playSound(510);
								break;
								case ';':
								drawSwitch(481,165,9);
								playSound(530);
								break;
								case 'z':
								drawSwitch(501,165,9);
								playSound(550);
								break;
								case 'x':
								drawSwitch(521,165,9);
								playSound(570);
								break;
								case 'c':
								drawSwitch(541,165,9);
								playSound(590);
								break;
								case 'v':
								drawSwitch(561,165,9);
								playSound(600);
								break;
								case 'Q':
								drawSwitch(61,165,9);
								playSound(100);
								break;
								case 'W':
								drawSwitch(81,165,9);
								playSound(120);
								break;
								case'E':
								drawSwitch(101,165,9);
								playSound(150);
								break;
								case 'R':
								drawSwitch(121,165,9);
								playSound(170);
								break;
								case 'T':
								drawSwitch(141,165,9);
								playSound(190);
								break;
								case 'Y':
								drawSwitch(161,165,9);
								playSound(210);
								break;
								case 'U':
								drawSwitch(181,165,9);
								playSound(230);
								break;
								case 'I':
								drawSwitch(201,165,9);
								playSound(250);
								break;
								case '{':
								drawSwitch(261,165,9);
								playSound(310);
								break;
								case '}':
								drawSwitch(281,165,9);
								playSound(330);
								break;
								case 'A':
								drawSwitch(301,165,9);
								playSound(350);
								break;
								case 'S':
								drawSwitch(321,165,9);
								playSound(370);
								break;
								case 'D':
								drawSwitch(341,165,9);
								playSound(390);
								break;
								case 'F':
								drawSwitch(361,165,9);
								playSound(410);
								break;
								case 'G':
								drawSwitch(381,165,9);
								playSound(430);
								break;
								case 'L':
								drawSwitch(461,165,9);
								playSound(510);
								break;
								case ':':
								drawSwitch(481,165,9);
								playSound(530);
								break;
								case 'Z':
								drawSwitch(501,165,9);
								playSound(550);
								break;
								case 'X':
								drawSwitch(521,165,9);
								playSound(570);
								break;
								case 'C':
								drawSwitch(541,165,9);
								playSound(590);
								break;
								case 'V':
								drawSwitch(561,165,9);
								playSound(600);
								break;
								default:
								current_freq=100;
								break;
							  }//Switch Closed
					 mainWindow();
					}


void MyPiano::mainWindow()
					{
					 //Window Variable
					 win_flag=MAINWINDOW;
					 //Record Box
					 if(rec_flag==1)
					  {recordBox();}
					 //Drawing main body
					 drawMainBody();
					 drawControlPanel();
					 //Checking which button is selected
					 //By using the variable main_v
					 //if main_v=0 Button=Record
					 if(main_v==0)
					  {
						setcolor(15);setfillstyle(1,1);
						drawButton(489,78," Record  ",1);
					  }
					 //Options Button
					 if(main_v==1)
					  {
						setcolor(15);setfillstyle(1,1);
						drawButton(489,95," Options ",1);
					  }
					 //Help Button
					 if(main_v>1)
					  {
						setcolor(15);setfillstyle(1,1);
						drawButton(489,113,"  Help   ",1);
					  }
					 if(mini_show==1){drawMiniWindow();}
					 fclose(f_mini_show);
					 /*drawing switch panel*/
					 drawSwitchPanel();
					 //Updating each second (Graph & Spectrum)
					 drawGraph();
					 drawSpectrum();
					 //Drawing Spectrum (OFF STATUS)
					 int yaxis=130;
					 for(int bars=0;bars<(600/55);bars++)
					  {
						setfillstyle(1,8);
						bar(228,yaxis,238,yaxis-3);
						bar(243,yaxis,253,yaxis-3);
						bar(258,yaxis,268,yaxis-3);
						bar(273,yaxis,283,yaxis-3);
						bar(288,yaxis,298,yaxis-3);
						bar(303,yaxis,313,yaxis-3);
						yaxis-=5;
					  }
					 //Shwoing mini window
					 if(mini_show==1){drawMiniWindow();}
					 //Showing Mouse
					 showMouse();
					 for(	;	;	)
					 {
					  //Printing time
					  printTime();
					  //Reading mouse actions
					  readMouse();
					  //Prompting user to press a key to play
					  if(play_flag==1)
						{setcolor(15);outtextxy(250,330,"Press Any Key To Play");}
					  while(kbhit())
						  {
							if(play_flag==0)
							 {
							  //Checking for keyboard press
							  char input=getch();
							  switch(input)
									{
									 //Increasing Delay
									case '+':
									if(time_delay<1000){time_delay+=50;}
									else
									  {time_delay=1000;}
									break;
									//Decreasing Delay
									case '-':
									if(time_delay>50){time_delay-=50;}
									else
									  {time_delay=50;}
									break;
									//Increasing freq
									case 77:
									if(sound_flag<4){sound_flag++;}
									else
									  {sound_flag=4;}
									break;
									//Decreasing freq
									case 75:
									if(sound_flag>0){sound_flag--;}
									else
									  {sound_flag=0;}
									break;
									//Up Arrow For Checking Which button is selected
									//in main window
									case 72:
									if(main_v>0){main_v--;}else{main_v=0;}
									break;
									//Down Arrow
									case 80:
									if(main_v<2){main_v++;}else{main_v=0;}
									break;
									//Options window
									case 13:
									//Record Window
									if(main_v==0)
									 {
									  //Logging
									  createLog("Record Window Opened:");
									  setcolor(15);setfillstyle(1,1);
									  drawButton(489,78," Record  ",1);
									  recordWindow();
									 }
									//Options Window
									if(main_v==1)
									 {
									  //Logging
									  createLog("Options Window Opened:");
									  setcolor(15);setfillstyle(1,1);
									  drawButton(489,95," Options ",1);
									  optionsWindow();
									 }
									//Help Window
									if(main_v==2)
									 {
									  //Logging
									 createLog("Help Window Opened:");
									 setcolor(15);setfillstyle(1,1);
									 drawButton(489,113,"  Help   ",1);
									 helpWindow();
									 }
									break;
									//CTRL+O
									case 15:
									//Logging
									createLog("Options Window Opened:");
									setcolor(15);setfillstyle(1,1);
									drawButton(489,95," Options ",1);
									optionsWindow();
									break;
									//Record Window
									//Key Code CTRL+R
									case 18:
									//Logging
									createLog("Record Window Opened:");
									setcolor(15);setfillstyle(1,1);
									drawButton(489,78," Record  ",1);
									recordWindow();
									break;
									//Help Window
									//CTRL+H
									case 8:
									//Logging
									createLog("Help Window Opened:");
									setcolor(15);setfillstyle(1,1);
									drawButton(489,113,"  Help   ",1);
									helpWindow();
									break;
									//Exit condition
									case 27:
									//Check for record status
									if(rec_flag==1)
									 {
									  for(int temp=0;temp<=rec_count;temp++)
										{putw(record_buffer[temp],record);}
									  rec_flag=0;rec_count=0;fclose(record);
									  drawMsgBox(215,240,"Recording Completed.");
									  cleardevice();mainWindow();
									 }
									break;
									//CTRL+X Exit Command
									case 24:
									fcloseall();
									//Logging
									createLog("Exited:");
									closegraph();exit(0);
									break;
									//Checking for Ctrl+Q key press
									//Finding which window is opened and closing that
									case 17:
									//Main Window
									if(win_flag==MAINWINDOW){exit(0);}
									break;
									default:
									userKeyPress(input);
									break;
								  }//Switch Closed

							  mainWindow();
							 }//If Closed
							 //If Play Flag equals play back then play recorded file
							else
							  {
								playBox();
								int fre;
								rec_count=0;
								//Counting file chars size
								do
								 {
								  //Reading notes from file
								  fre=getw(record);
								  //Setting max limit
								  if(fre>0&&fre<=600){play_count++;}
								 }while(getw(record)!=EOF);
								 //Closing and opening file again
								 fclose(record);record=fopen(filename,"r");
								//Reading contents from file
								do
								 {
								  rec_count++;
								  playBox();
								  //Clearing previous spectrum display
								  int yaxis=130;
								  for(int bars=0;bars<(current_freq/55);bars++)
									 {
									  setfillstyle(1,8);
									  bar(228,yaxis,238,yaxis-3);
									  bar(243,yaxis,253,yaxis-3);
									  bar(258,yaxis,268,yaxis-3);
									  bar(273,yaxis,283,yaxis-3);
									  bar(288,yaxis,298,yaxis-3);
									  bar(303,yaxis,313,yaxis-3);
									  yaxis-=5;
									 }//For loop closed(SPECTRUM)
								  //Clearing previous graph display
								  setfillstyle(1,8);bar(322,78,478,132);
								  //Reading notes from file
								  fre=getw(record);
								  //Setting max limit
								  if(fre>0&&fre<=3000){playSound(fre);}
								 }while(getw(record)!=EOF);
								 rec_count=0;play_count=0;
								 fclose(record);
								 getch();
								 drawMsgBox(200,200,"Playback Completed.");
								 play_flag=0;rec_count=0;
								 cleardevice();mainWindow();
							  }//else closed
							}//while closed
					  }//For Loop Closed
					}//Function closed


void MyPiano::optionsWindow()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Drawing main window
					 setfillstyle(1,7);bar(150,200,480,400);
					 setcolor(15);
					 line(150,200,480,200);line(150,200,150,400);
					 setcolor(8);
					 line(150,400,480,400);line(480,200,480,400);
					 //Title bar
					 setfillstyle(1,1);bar(151,201,479,217);
					 setcolor(0);line(151,218,479,218);
					 setcolor(14);settextstyle(1,0,1);
					 outtextxy(155,206,"Piano Settings");
					 //Close button
					 setfillstyle(1,1);drawCloseButton(462,203,"X",0);
					 //Box
					 setcolor(0);rectangle(152,220,478,398);
					 //Drawing other components
					 //Skin Color Tab
					 setfillstyle(1,7);setcolor(15);
					 rectangle(155,235,475,275);
					 setcolor(15);
					 drawButton(160,225,"Skin Color ",0);
					 //Drawing color boxes
					 setfillstyle(1,3);
					 drawButton(170,250,"  ",0);
					 setfillstyle(1,4);
					 drawButton(200,250,"  ",0);
					 setfillstyle(1,5);
					 drawButton(230,250,"  ",0);
					 setfillstyle(1,6);
					 drawButton(260,250,"  ",0);
					 setfillstyle(1,8);
					 drawButton(290,250,"  ",0);
					 setfillstyle(1,9);
					 drawButton(320,250,"  ",0);
					 setfillstyle(1,10);
					 drawButton(350,250,"  ",0);
					 setfillstyle(1,11);
					 drawButton(380,250,"  ",0);
					 setfillstyle(1,12);
					 drawButton(410,250,"  ",0);
					 setfillstyle(1,14);
					 drawButton(440,250,"  ",0);
					 //Key Log viewing tool bar
					 setfillstyle(1,7);setcolor(15);
					 rectangle(155,290,295,330);
					 setcolor(15);
					 drawButton(160,280," Edit Log  ",0);
					 //Log buttons
					 setfillstyle(1,1);setcolor(15);
					 drawButton(160,305,"View  ",0);
					 setcolor(15);
					 drawButton(230,305,"Clear ",0);
					 //Mini Window View Tool Bar
					 setfillstyle(1,7);setcolor(15);
					 rectangle(320,290,475,330);
					 setcolor(15);
					 drawButton(325,280,"Mini Window",0);
					 //Log buttons
					 setfillstyle(1,1);
					 setcolor(15);
					 drawButton(325,305,"Show  ",0);
					 setcolor(15);
					 drawButton(405,305,"Hide  ",0);
					 //Lock System and Change Password Tool Bar
					 setfillstyle(1,7);setcolor(15);
					 rectangle(155,345,295,380);
					 setcolor(15);
					 drawButton(160,335,"Permissions",0);
					 //Log buttons
					 setfillstyle(1,1);setcolor(15);
					 drawButton(160,357,"Set Control",0);
					 //Register Copy
					 setfillstyle(1,7);setcolor(15);
					 rectangle(320,345,475,380);
					 setcolor(15);
					 drawButton(325,335,"Register   ",0);
					 //Log buttons
					 setfillstyle(1,1);setcolor(15);
					 drawButton(325,357,"Product Code",0);
					 //Printing directions to use switches
					 setcolor(0);
					 outtextxy(160,385," Arrow keys to select.'Esc'to go back.");
					 //Checking horizontal & vertical button variables and
					 //deciding which button is selected and showing clicked
					 //effect on that
					 /*Button Details********/
					 //BUTTON  -      Skin Change--------------------------------
					 if(btn_v==0)
					  {
						setcolor(8);rectangle(155,235,475,275);
						setfillstyle(1,8);
						setcolor(15);drawButton(160,225,"Skin Color ",1);
					  }
					 //Skin-> Color=3
					 if(btn_h==0&&btn_v==0)
					  {setfillstyle(1,3);drawButton(170,250,"  ",1);}
					 //Skin-> Color=4
					 if(btn_h==1&&btn_v==0)
					  {setfillstyle(1,4);drawButton(200,250,"  ",1);}
					 //Skin-> Color=5
					 if(btn_h==2&&btn_v==0)
					  {setfillstyle(1,5);drawButton(230,250,"  ",1);}
					 //Skin-> Color=6
					 if(btn_h==3&&btn_v==0)
					  {setfillstyle(1,6);drawButton(260,250,"  ",1);}
					 //Skin-> Color=7
					 if(btn_h==4&&btn_v==0)
					  {setfillstyle(1,8);drawButton(290,250,"  ",1);}
					 //Skin-> Color=9
					 if(btn_h==5&&btn_v==0)
					  {setfillstyle(1,9);drawButton(320,250,"  ",1);}
					 //Skin-> Color=10
					 if(btn_h==6&&btn_v==0)
					  {setfillstyle(1,10);drawButton(350,250,"  ",1);}
					 //Skin-> Color=11
					 if(btn_h==7&&btn_v==0)
					  {setfillstyle(1,11);drawButton(380,250,"  ",1);}
					  //Skin-> Color=12
					 if(btn_h==8&&btn_v==0)
					  {setfillstyle(1,12);drawButton(410,250,"  ",1);}
					 //Skin-> Color=14
					 if(btn_h==9&&btn_v==0)
					  {setfillstyle(1,14);drawButton(440,250,"  ",1);}
					 //BUTTON  -      Edit Log------------------------------------
					 if(btn_v==1)
					  {
						setcolor(8);rectangle(155,290,295,330);
						setfillstyle(1,8);
						setcolor(15);drawButton(160,280," Edit Log  ",1);
					  }
					 //View Log File
					 if(btn_v==1&&btn_h==0)
					  {
						setfillstyle(1,1);setcolor(11);
						drawButton(160,305,"View  ",1);
					  }
					 //Clear Log File
					 if(btn_v==1&&btn_h>0)
					  {
						setfillstyle(1,1);setcolor(11);
						drawButton(230,305,"Clear ",1);
					  }


					 //BUTTON  -      Permissions--------------------------------
					 if(btn_v==2)
					  {
						setcolor(8);rectangle(155,345,295,380);
						setfillstyle(1,8);setcolor(15);
						drawButton(160,335,"Permissions",1);
						setfillstyle(1,1);setcolor(11);
						drawButton(160,357,"Set Control",0);
					  }



					 //BUTTON  -      Mini Window--------------------------------
					 if(btn_v==3)
					  {
						setfillstyle(1,8);setcolor(8);rectangle(320,290,475,330);
						setcolor(15);drawButton(325,280,"Mini Window",1);
						setfillstyle(1,1);setcolor(11);
						drawButton(325,305,"Show  ",1);
					  }
					 //Hide Button
					 if(btn_h>0&&btn_v==3)
					  {
						setfillstyle(1,1);setcolor(15);
						drawButton(325,305,"Show  ",0);
						setfillstyle(1,1);setcolor(11);
						drawButton(405,305,"Hide  ",1);
					  }

					  //BUTTON  -      Register Window--------------------------------
					 if(btn_v==4)
					  {
						setfillstyle(1,8);setcolor(8);
						rectangle(320,345,475,380);
						setcolor(15);
						drawButton(325,335,"Register   ",1);
						//Log buttons
						setfillstyle(1,1);setcolor(11);
						drawButton(325,357,"Product Code",1);
					  }
					 //Showing Mouse
					 showMouse();

					 //Reading user key press and setting actions for keys
					 char option=getch();
					 //Testing only
					 switch(option)
						  {
							//Down arrow for changing tool bar buttons VERTICAL
							case 80:
							btn_h=0;
							if(btn_v<4){btn_v++;}else{btn_v=0;}
							break;
							//Up arrow for changing tool bar VERTICAL
							case 72:
							btn_h=0;
							if(btn_v>0){btn_v--;}else{btn_v=0;}
							break;
							//Right arrow for increasing vertical selection variable
							case 77:
							if(btn_h<9){btn_h++;}
							else
							  {btn_h=0;}
							break;
							//Left arrow for decreasing vertical selection variable
							case 75:
							if(btn_h>0){btn_h--;}else{btn_h=9;}
							break;
							//Enter key press reading
							case 13:
							//Setting skin color
							/****************************************************/
							if(btn_v==0)
							 {
							  createLog("Skin Changed:");
							  drawMsgBox(215,240,"Skin Changed");
							 }
							if(btn_v==1)
							 {createLog("Log Menu Accessed:");}
							if(btn_v==2){createLog("Permission Window opened:");}
							if(btn_v==3){createLog("Mini Window Options Opened:");}
							//--------------------------------------------------//
							if(btn_v==0&&btn_h==0)
							{f_skin_control_panel=3;}
							if(btn_v==0&&btn_h==1)
							{f_skin_control_panel=4;}
							if(btn_v==0&&btn_h==2)
							{f_skin_control_panel=5;}
							if(btn_v==0&&btn_h==3)
							{f_skin_control_panel=6;}
							if(btn_v==0&&btn_h==4)
							{f_skin_control_panel=8;}
							if(btn_v==0&&btn_h==5)
							{f_skin_control_panel=9;}
							if(btn_v==0&&btn_h==6)
							{f_skin_control_panel=10;}
							if(btn_v==0&&btn_h==7)
							{f_skin_control_panel=11;}
							if(btn_v==0&&btn_h==8)
							{f_skin_control_panel=12;}
							if(btn_v==0&&btn_h==9)
							{f_skin_control_panel=14;}
							//Changing skin file contents with new value
							f_skin=fopen("skin_1.skn","w");
							putw(f_skin_control_panel,f_skin);
							fclose(f_skin);
							/****************************************************/
							//Checking for Log file Tool Bar
							if(btn_v==1&&btn_h==0)
							 {
							  system("edit log.log");
							  drawMsgBox(215,240,"Back to Piano");
							  cleardevice();
							  mainWindow();
							 }
							if(btn_v==1&&btn_h>0)
							 {
							  log=fopen("log.log","w");
							  fclose(log);
							  drawMsgBox(215,240,"Log file cleared");
							 }
							/****************************************************/
							//Checking for mini window visiblility
							if(btn_v==3&&btn_h==0)
							 {
							  f_mini_show=fopen("skin_3.skn","w");
							  putw(1,f_mini_show);
							  fclose(f_mini_show);
							  drawMsgBox(215,240,"Mini window opened");
							  mini_show=1;

							 }
							if(btn_v==3&&btn_h==1)
							 {
							  f_mini_show=fopen("skin_3.skn","w");
							  putw(0,f_mini_show);
							  fclose(f_mini_show);
							  drawMsgBox(215,240,"Mini window closed");
							  mini_show=0;
							 }
							//Access Control functions
							if(btn_v==2)
							{
							 //code for restrict access
							 pwdWindow();
							}
							//Register Copy
							if(btn_v==4)
							 {
							  regWindow();
							 }
							break;
							case 27:
							cleardevice();
							mainWindow();
							break;
							default:
							break;
						  }
					 optionsWindow();
					}

void MyPiano::pwdWindow()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Main window
					 setfillstyle(1,3);bar(170,230,460,390);
					 //Title bar
					 setfillstyle(1,4);bar(170,230,460,250);
					 setcolor(15);outtextxy(175,236,"Set User Permissions");
					 //3D effect
					 setcolor(15);
					 line(170,230,460,230);line(170,230,170,390);
					 line(170,229,460,229);line(169,229,169,390);
					 setcolor(0);
					 line(170,390,460,390);line(460,230,460,390);
					 line(171,250,460,250);
					 //Password Protection ENABLED\DISABLED
					 setfillstyle(1,7);setcolor(15);
					 rectangle(175,265,455,310);
					 setcolor(15);
					 drawButton(190,255,"   Password Protection   ",0);
					 //Enabled\Disabled
					 setfillstyle(1,1);setcolor(15);
					 drawButton(190,285,"  Enabled   ",0);
					 setcolor(15);
					 drawButton(320,285,"  Disabled  ",0);
					 //Change Password
					 setfillstyle(1,7);setcolor(15);
					 rectangle(175,335,455,380);
					 setcolor(15);
					 drawButton(190,325,"        Password         ",0);
					 setfillstyle(1,1);setcolor(15);
					 drawButton(190,355,"   Change   ",0);
					 setcolor(15);
					 drawButton(320,355,"   About ?  ",0);
					 //Password Protection Button
					 if(pwd_v==0)
					  {
						setfillstyle(1,8);setcolor(8);
						rectangle(175,265,455,310);
						setcolor(15);
						drawButton(190,255,"   Password Protection   ",1);
						setfillstyle(1,1);setcolor(11);
						drawButton(190,285,"  Enabled   ",1);
					  }
					 //Password Protection-> Disabled
					 if(pwd_v==0&&pwd_h>0)
					  {
						setfillstyle(1,1);setcolor(15);
						drawButton(190,285,"  Enabled   ",0);
						setcolor(11);
						drawButton(320,285,"  Disabled  ",1);
					  }
					 //Change password button
					 if(pwd_v>0)
					  {
						setfillstyle(1,8);setcolor(8);
						rectangle(175,335,455,380);
						setcolor(15);
						drawButton(190,325,"        Password         ",1);
						setfillstyle(1,1);setcolor(11);
						drawButton(190,355,"   Change   ",1);
						setcolor(15);
						drawButton(320,355,"   About ?  ",0);
					  }
					 //Password Change-> Change
					 if(pwd_v==1&&pwd_h>0)
					  {
						setfillstyle(1,1);setcolor(15);
						drawButton(190,355,"   Change   ",0);
						setcolor(11);
						drawButton(320,355,"   About ?  ",1);
					  }

					 //Showing Mouse
					 showMouse();

					 char ch=getch();
					 switch(ch)
						  {
							//Down Arrow
							case 80:
							pwd_h=0;
							if(pwd_v<1){pwd_v++;}else{pwd_v=0;}
							break;
							//Up Arrow
							case 72:
							pwd_h=0;
							if(pwd_v>0){pwd_v--;}else{pwd_v=1;}
							break;
							//Right Arrow
							case 77:
							if(pwd_h<1){pwd_h++;}else{pwd_h=0;}
							break;
							//Left Arrow
							case 75:
							if(pwd_h>0){pwd_h--;}else{pwd_h=1;}
							break;
							//Enter Key Press
							case 13:
							//Enabling password
							if(pwd_v==0&&pwd_h==0)
							 {
							  pwd_flag=fopen("pwd_flag.pwd","w");
							  putw(1,pwd_flag);
							  fclose(pwd_flag);
							  drawMsgBox(215,240,"Password Enabled");
							 }
							//Disabling password
							if(pwd_v==0&&pwd_h>0)
							 {
							  pwd_flag=fopen("pwd_flag.pwd","w");
							  putw(0,pwd_flag);
							  fclose(pwd_flag);
							  drawMsgBox(215,240,"Password Disbled");
							 }
							//Change password
							if(pwd_v>0&&pwd_h==0)
							 {
							  cleardevice();
							  char old_password[8];
							  char new_password[8];
							  //Opening password stored file
							  pwd=fopen("pwd.pwd","r");
							  fgets(password,9,pwd);
							  fclose(pwd);
							  //Reading and checking old password
							  initTextMode();
							  textcolor(15);
							  gotoxy(25,12);cprintf("Enter old password:");
							  gets(old_password);
							  int cmp=strcmp(old_password,password);
							  if(cmp!=0)
								{
								 clrscr();
								 gotoxy(25,12);cprintf("Wrong Passwords");
								 sound(1000);delay(300);nosound();
								 //Changing to graphics mode
								 initGraphics();
								 cleardevice();mainWindow();
								}
							  //Changing to graphics mode
							  initTextMode();
							  textcolor(15);
							  gotoxy(25,13);cprintf("Enter new password:");
							  gets(new_password);
							  //Opening password stored file
							  pwd=fopen("pwd.pwd","w");
							  fputs(new_password,pwd);
							  fclose(pwd);
							  //Changed notification
							  initGraphics();
							  drawMsgBox(240,160,"Password Changed");
							  cleardevice();mainWindow();
							 }
							//About Button
							if(pwd_v==1&&pwd_h==1)
							 {
							  aboutWindow();
							 }
							break;
							//Escape Key
							case 27:
							optionsWindow();
							break;
							default:
							break;
						  }
					 pwdWindow();
					}
void MyPiano::regWindow()
					{
					 initTextMode();
					 textcolor(15);
					 gotoxy(25,13);cprintf("Enter Registraion Code:");
					 int code;cin>>code;
					 //Registraton file opening
					 if(code==reg_status)
					  {
						reg=fopen("reg.reg","w");putw(0,reg);
						initGraphics();
						drawMsgBox(240,160,"Registration Done");
					  }
					 else
					  {initGraphics();drawMsgBox(200,160,"Invalid Product Code");}
					 initGraphics();
					 mainWindow();
					}

void MyPiano::aboutWindow()
					{
					 //Hiding Mouse
					 hideMouse();

					 setfillstyle(1,6);bar(195,260,440,380);
					 setfillstyle(1,1);bar(195,260,440,275);
					 setcolor(15);outtextxy(198,264,"What is security?");
					 setcolor(15);
					 // 3D effect
					 line(195,260,440,260);line(195,260,195,380);
					 line(194,259,440,260);line(194,259,194,380);
					 setcolor(0);
					 line(195,380,440,380);line(440,260,440,380);
					 line(196,275,440,275);
					 //drawing box
					 setcolor(7);rectangle(198,277,438,378);
					 //Printing security contents
					 settextstyle(2,0,4);
					 setcolor(14);
					 outtextxy(201,280,"What Password Does:");
					 setcolor(15);
					 outtextxy(201,290,"Preventing unauthorized user from");
					 outtextxy(201,300,"accessing your computer.");
					 setcolor(14);
					 outtextxy(201,315,"Tips:");
					 setcolor(15);
					 outtextxy(201,325,"Change password regularly.");
					 setcolor(14);
					 outtextxy(201,340,"Forgot password:");
					 setcolor(15);
					 outtextxy(201,350,"E-Mail Me");
					 setcolor(11);
					 outtextxy(210,365,"E-mail:renjithmathewjoseph@hotmail.com");
					 settextstyle(0,0,0);
					 //Showing Mouse
					 showMouse();
					 getch();pwdWindow();
					}



void MyPiano::recordWindow()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Drawing main window
					 setfillstyle(1,1);bar(150,200,480,400);
					 setcolor(15);
					 line(150,200,480,200);line(150,200,150,400);
					 setcolor(8);
					 line(150,400,480,400);line(480,200,480,400);
					 //Title bar
					 setfillstyle(1,9);bar(151,201,479,217);
					 setcolor(0);line(151,218,479,218);
					 setcolor(11);settextstyle(1,0,1);
					 outtextxy(155,206,"Record Songs");
					 //Close button
					 setfillstyle(1,1);drawCloseButton(462,203,"X",0);
					 //Box
					 setcolor(0);rectangle(152,220,478,398);
					 //Drawing other components
					 setcolor(8);
					 rectangle(200,240,440,370);
					 //Press ESC
					 setcolor(14);outtextxy(240,380,"Press Esc to go back.");
					 //Checking which button is selected
					 //New file button
					 if(rec_h==0)
					  {
						setfillstyle(1,8);setcolor(11);
						drawButton(220,250,"      New File      ",1);
						//Open File
						setcolor(15);setfillstyle(1,7);
						drawButton(220,280,"      Open File     ",0);
						//About
						setcolor(15);
						drawButton(220,310,"      About ?       ",0);
						//Go Back
						setcolor(15);
						drawButton(220,340,"      Go Back       ",0);
					  }
					 //Open File Button
					 if(rec_h==1)
					  {
						setfillstyle(1,7);setcolor(15);
						drawButton(220,250,"      New File      ",0);
						//Open File
						setcolor(11);setfillstyle(1,8);
						drawButton(220,280,"      Open File     ",1);
						//About
						setcolor(15);setfillstyle(1,7);
						drawButton(220,310,"      About ?       ",0);
						//Go Back
						setcolor(15);
						drawButton(220,340,"      Go Back       ",0);
					  }
					 //About button
					 if(rec_h==2)
					  {
						setfillstyle(1,7);setcolor(15);
						drawButton(220,250,"      New File      ",0);
						//Open File
						setcolor(15);
						drawButton(220,280,"      Open File     ",0);
						//About
						setcolor(11);setfillstyle(1,8);
						drawButton(220,310,"      About ?       ",1);
						//Go Back
						setcolor(15);setfillstyle(1,7);
						drawButton(220,340,"      Go Back       ",0);
					  }
					 //Back to main window button
					 if(rec_h==3)
					  {
						setfillstyle(1,7);setcolor(15);
						drawButton(220,250,"      New File      ",0);
						//Open File
						setcolor(15);
						drawButton(220,280,"      Open File     ",0);
						//About
						setcolor(15);
						drawButton(220,310,"      About ?       ",0);
						//Go Back
						setcolor(11);setfillstyle(1,8);
						drawButton(220,340,"      Go Back       ",1);
						setfillstyle(1,7);
					  }
					 //Showing Mouse
					 showMouse();
					 //Reading user input
					 char ch=getch();
					 switch(ch)
						  {
							//Down Arrow
							case 80:
							if(rec_h<3){rec_h++;}else{rec_h=0;}
							break;
							//Up Arrow
							case 72:
							if(rec_h>0){rec_h--;}else{rec_h=3;}
							break;
							case 27:
							cleardevice();
							mainWindow();
							break;
							//Enter key press
							case 13:
							if(rec_h==0)
							 {
							  cleardevice();
							  initTextMode();
							  gotoxy(20,12);cout<<"Enter file name to be recorded:";
							  gets(filename);
							  strcat(filename,".gpn");
							  //Checks if file exists or not
							  record=fopen(filename,"r");
							  //Not present
							  if(record==NULL)
								{
								 record=fopen(filename,"w");
								 rec_flag=1;initGraphics();mainWindow();
								}
							  //Present
							  else
								{
								 gotoxy(20,12);cout<<"File Exists.Overwrite? (Y/N):";
								 playBeep();
								 char ch=getch();
								 //Overwrite
								 if(ch=='y'||ch=='Y')
								  {
									record=fopen(filename,"w");
									rec_flag=1;initGraphics();mainWindow();
								  }
								 else
								  {
									rec_flag=0;
									initGraphics();mainWindow();
								  }
								}
							 }
							//Opening recorded file for playing
							if(rec_h==1)
							 {
							  initTextMode();
							  gotoxy(20,12);cout<<"Enter file name to be palyed:";
							  gets(filename);
							  strcat(filename,".gpn");
							  //Checks if file exists or not
							  record=fopen(filename,"r");
							  //Not present
							  if(record==NULL)
								{
								 initGraphics();
								 drawErrorBox(200,160,"File not found.");
								 rec_flag=0;initGraphics();mainWindow();
								}
							  else
								{play_flag=1;initGraphics();mainWindow();}
							 }
							//Back Button
							if(rec_h==3)
							 {
							  cleardevice();mainWindow();
							 }
							//About Me
							if(rec_h==2)
							 {
							  drawMsgBox(200,160,"All rights reserved.");
							  cleardevice();mainWindow();
							 }

							break;
							default:
							break;
						  }
					 recordWindow();
					}

void MyPiano::recordBox()
					{
					 //Drawing main body and title bar
					 setfillstyle(1,6);bar(200,304,420,424);
					 setfillstyle(1,4);bar(200,304,420,319);
					 setcolor(0);line(201,319,420,319);
					 setcolor(15);outtextxy(213,308,"Record Status Indicator");
					 //3D effect
					 setcolor(15);
					 line(200,304,420,304);line(200,304,200,424);
					 setcolor(7);
					 line(200,424,420,424);line(420,304,420,424);
					 //Print details such as
					 //chars recorded,current file size,etc
					 //Starting time etc
					 setcolor(11);outtextxy(213,330,"File Name:");
					 setcolor(10);outtextxy(300,330,filename);
					 setcolor(11);outtextxy(213,345,"Chars    :");
					 char *t_rec_count;
					 itoa(rec_count,t_rec_count,10);
					 setcolor(10);outtextxy(300,345,t_rec_count);
					 setcolor(11);outtextxy(213,360,"Buffers  :");
					 //Remaining buffers

					 itoa((200-rec_count),t_rec_count,10);
					 setcolor(10);outtextxy(300,360,t_rec_count);
					 //Progress bar
					 setcolor(11);outtextxy(213,375,"Record Buffer Indicator");
					 //Bar
					 setcolor(8);rectangle(210,385,412,400);
					 setfillstyle(1,7);bar(211,386,411,399);
					 //Bar limit setting
					 setfillstyle(1,1);bar(211,386,211+rec_count,399);
					 //Reading & Printing percentage completed
					 itoa((rec_count/2),t_rec_count,10);
					 strcat(t_rec_count,"%");
					 setcolor(14);outtextxy(306,390,t_rec_count);
					}


void MyPiano::playBox()
					{
					 hideMouse();
					 //Drawing main body and title bar
					 setfillstyle(1,8);bar(200,304,420,424);
					 setfillstyle(1,1);bar(200,304,420,319);
					 setcolor(0);line(201,319,420,319);
					 setcolor(15);outtextxy(213,308,"Play back status Indicator");
					 //3D effect
					 setcolor(15);
					 line(200,304,420,304);line(200,304,200,424);
					 setcolor(7);
					 line(200,424,420,424);line(420,304,420,424);
					 //Print details such as
					 //chars recorded,current file size,etc
					 //Starting time etc
					 setcolor(11);outtextxy(213,330,"File Name:");
					 setcolor(10);outtextxy(300,330,filename);
					 setcolor(11);outtextxy(213,345,"Chars    :");
					 char *t_rec_count;
					 itoa(rec_count,t_rec_count,10);
					 setcolor(10);outtextxy(300,345,t_rec_count);
					 //Progress bar
					 setcolor(11);outtextxy(213,375,"Playback Indicator");
					 //Bar
					 setcolor(0);rectangle(210,385,412,400);
					 setfillstyle(1,15);bar(211,386,411,399);
					 //Bar limit setting
					 showMouse();
					}


void MyPiano::helpWindow()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Drawing main window
					 setfillstyle(1,1);bar(150,200,480,400);
					 setcolor(15);
					 line(150,200,480,200);line(150,200,150,400);
					 setcolor(8);
					 line(150,400,480,400);line(480,200,480,400);
					 //Title bar
					 setfillstyle(1,4);bar(151,201,479,217);
					 setcolor(0);line(151,218,479,218);
					 setcolor(15);settextstyle(1,0,1);
					 outtextxy(155,206,"Piano Help Topics");
					 //Close button
					 setfillstyle(1,1);drawCloseButton(462,203,"X",0);
					 //Box
					 setcolor(0);rectangle(152,220,478,398);
					 //Drawing other components
					 settextstyle(5,0,4);setcolor(11);
					 outtextxy(155,220,"Refer File:How To Use");
					 settextstyle(0,0,0);
					 //Showing Mouse
					 showMouse();
					 getch();
					 cleardevice();
					}


void MyPiano::playSound(int frequency)
					{
					 current_freq=frequency;
					 sound(frequency*sound_flag);
					 //Rec Flag Settings
					 //0-No Rec,1-Open Temp Rec & Start Rec
					 //Open Temp Rec File
					 //Record notes to file
					 if(rec_flag==1)
					  {
						//Setting Limit
						if(rec_count>=200)
						  {
							nosound();
							for(int temp=0;temp<=rec_count;temp++)
							 {
							  putw(record_buffer[temp],record);
							 }
							rec_flag=0;rec_count=0;
							putw(9999,record);
							drawMsgBox(215,240,"Recording Completed.");
							cleardevice();mainWindow();
						  }
						record_buffer[rec_count]=frequency*sound_flag;
						rec_count++;
						recordBox();
					  }
					 //Drawing graph and spectrum
					 drawGraph();
					 drawSpectrum();
					 delay(time_delay);
					 nosound();
					}
void MyPiano::drawSpectrum()
					{
					 int yaxis=130;
					 //Limiting spectrum to max limit
					 if(current_freq>600){current_freq=600;}
					 for(int bars=0;bars<(current_freq/55);bars++)
					  {
						if(bars<3)setfillstyle(1,10);
						if(bars>=3&&bars<6)setfillstyle(1,14);
						if(bars>=6&&bars<8)setfillstyle(1,6);
						if(bars>=8)setfillstyle(1,4);
						bar(228,yaxis,238,yaxis-3);
						bar(243,yaxis,253,yaxis-3);
						bar(258,yaxis,268,yaxis-3);
						bar(273,yaxis,283,yaxis-3);
						bar(288,yaxis,298,yaxis-3);
						bar(303,yaxis,313,yaxis-3);
						yaxis-=5;
					  }
					 delay(100);
					}
void MyPiano::drawMainBody()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Drawing main body of piano
					 setfillstyle(1,7);bar(50,50,590,300);
					 //3D effect for main body
					 setcolor(15);
					 line(50,50,591,50);line(50,50,50,301);
					 line(51,51,591,51);line(51,51,51,300);
					 setcolor(8);
					 line(51,300,590,300);line(590,51,590,300);
					 line(51,301,590,301);line(591,51,591,301);
					 //Drawing controls body
					 setfillstyle(1,f_skin_control_panel);bar(53,75,588,150);
					 //3D effect for controls body
					 //Drawing black bar
					 setfillstyle(1,0);bar(222,78,318,132);
					 setcolor(0);
					 line(52,149,588,149);line(52,150,588,150);
					 line(589,52,589,150);
					 setcolor(15);line(52,151,588,151);
					 //Printing title bar and caption
					 setfillstyle(1,8);bar(53,53,587,73);
					 setcolor(0);
					 line(53,74,587,74);line(53,75,587,75);
					 line(588,53,588,150);
					 //Caption with 3D effect
					 setcolor(14);outtextxy(58,60,"MyPiano 3.0");
					 setcolor(0);line(150,53,150,75);line(151,53,151,75);
					 //Showing Mouse
					 showMouse();
					}

void MyPiano::drawControlPanel()
					{
					 //Hiding Mouse
					 hideMouse();
					 setcolor(7);settextstyle(1,0,1);
					 outtextxy(55,82,"Power");
					 outtextxy(55,100,"Delay");
					 outtextxy(55,118,"Pitch");
					 outtextxy(55,136,"Sound");
					 //Power Light drawing
					 setfillstyle(1,4);bar(100,80,110,90);
					 setcolor(7);rectangle(100,80,110,90);
					 //Delay Progress bar
					 drawProgressBar(102,98,(time_delay/50),11);
					 //Freq. Progress bar
					 drawProgressBar(102,116,(sound_flag*5),14);
					 //Drawing sound status box
					 setcolor(15);rectangle(100,132,135,146);
					 setfillstyle(1,0);bar(101,133,134,145);
					 //Checking for mute option
					 if(sound_flag>0){setcolor(6);outtextxy(105,136,"ON");}
					 else
						{setcolor(6);outtextxy(105,136,"OFF");}
					 //Drawing vertical lines
					 setcolor(7);
					 //Graphical spectrum display
					 line(220,76,220,147);
					 //Drawing key frequency graph
					 line(320,76,320,147);
					 //drawing current values
					 line(480,76,480,147);
					 //Drawing horizontal line
					 line(220,135,586,135);line(220,134,586,134);
					 //Printing each box captions(Spectrum\Graph\Values etc)
					 outtextxy(227,138,"2D Spectrum");
					 //Freq Graph
					 setcolor(7);
					 outtextxy(344,138,"Frequency Graph");
					 outtextxy(500,138,"Settings");
					 //Drawing 3D effect to boxes
					 setcolor(15);
					 //Vertical white line drawing (LEFT)
					 line(220,76,220,135);line(320,76,320,135);line(480,76,480,135);
					 //Horizontal line WHITE- UP SIDE
					 setcolor(15);line(220,76,586,76);
					 //Horizontal line BLACK- DOWN SIDE
					 setcolor(0);line(220,133,586,133);
					 //Vertical lines BLACK Right Side
					 setcolor(0);
					 line(318,76,318,133);line(478,77,478,133);
					 //Printing settings box contents
					 setcolor(15);setfillstyle(1,1);
					 drawButton(489,78," Record  ",0);
					 setcolor(15);
					 drawButton(489,95," Options ",0);
					 setcolor(15);
					 drawButton(489,113,"  Help   ",0);
					 //Drawing closed button and help button
					 setfillstyle(1,8);
					 drawCloseButton(565,58,"X",0);
					 drawCloseButton(550,58,"?",0);
					 drawCloseButton(535,58,"-",0);
					 //Showing Mouse
					 showMouse();
					}


void MyPiano::drawMiniWindow()
					{
					 //Hiding Mouse
					 hideMouse();
					 setfillstyle(1,f_skin_control_panel);bar(50,304,180,454);
					 setcolor(15);outtextxy(55,308,"Mini Window");
					 line(50,304,50,454);line(50,304,180,304);
					 line(51,304,51,454);line(50,305,180,305);
					 setcolor(7);
					 line(50,454,180,454);line(180,304,180,454);
					 line(50,453,180,453);line(181,304,181,454);
					 setcolor(7);line(52,318,179,318);line(52,317,179,317);
					 //Close Button
					 //Short Cut Keys Details Printing
					 setcolor(15);
					 outtextxy(55,380,"Shortcut Keys");
					 setcolor(7);
					 outtextxy(55,390,"Ctrl+R Record");
					 outtextxy(55,400,"Ctrl+O Options");
					 outtextxy(55,410,"Ctrl+H Help");
					 outtextxy(55,420,"Ctrl+X Exit");
					 outtextxy(55,430,"+/- Delay");
					 outtextxy(55,440,"Select-Arrows");
					 //Printing datas
					 setcolor(7);
					 outtextxy(55,325,"Time :");
					 outtextxy(55,345,"Pitch:");
					 outtextxy(55,355,"Freq.:");
					 outtextxy(55,365,"Delay:");
					 //Printing values
					 char temp[8];
					 setcolor(14);
					 //Pitch
					 itoa(sound_flag,temp,10);
					 outtextxy(105,345,temp);
					 //Freq.
					 itoa(current_freq*sound_flag,temp,10);
					 strcat(temp," Hz");
					 outtextxy(105,355,temp);
					 //Delay
					 itoa(time_delay,temp,10);
					 strcat(temp," ms");
					 outtextxy(105,365,temp);
					 //Close Button
					 setfillstyle(1,f_skin_control_panel);
					 drawCloseButton(168,305,"X",0);
					 //Showing Mouse
					 showMouse();
					}

void MyPiano::printTime()
					{
					 //Checking for copy registraton
					 if(reg_status!=0)
					  {
						setcolor(11);outtextxy(50,15,"Unregistered Copy");
						setcolor(15);outtextxy(50,25,"For registration please contact:renjithmathewjoseph@hotmail.com");
						outtextxy(50,35,"Register Immediatly and avoid these captions.....");
						struct  time t;gettime(&t);
						if(t.ti_sec==10){bug++;}
						if(bug==1)
						 {
						  bug=0;
						  drawMsgBox(200,160,"Unregistered Version");
						  cleardevice();mainWindow();
						 }
					  }
					 //If mini window visiblility==1 show time
					 if(mini_show==1)
					 {
					 setfillstyle(1,0);bar(102,322,173,335);
					 setcolor(15);rectangle(101,321,174,336);
					 //Accessing current Time
					 char tme[8],temp[8];
					 struct dostime_t t;
					 _dos_gettime(&t);
					 //t.hour, t.minute,t.second, t.hsecond);
					 itoa(t.hour,tme,10);
					 strcpy(temp,tme);strcat(temp,":");
					 itoa(t.minute,tme,10);
					 strcat(temp,tme);strcat(temp,":");
					 itoa(t.second,tme,10);
					 strcat(temp,tme);
					 outtextxy(105,325,temp);
					 delay(10);
					 }
					}

void MyPiano::drawGraph()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Limiting spectrum to max limit
					 if(current_freq>600){current_freq=600;}
					 //Interchanging previous frequencies with current freq.
					 for(int count=0;count<=20;count++)
						{
						 freq_buffer[count]=freq_buffer[count+1];
						}
					 freq_buffer[20]=current_freq;
					 //Drawing graph
					 int xaxis=327;
					 int yaxis;
					 for(int cnt=0;cnt<=20;cnt++)
						{
						 yaxis=125-freq_buffer[cnt]/12;
						 setcolor(1);
						 line(xaxis-1,yaxis+5,xaxis-1,128);
						 setcolor(11);
						 line(xaxis,yaxis+5,xaxis,128);
						 setcolor(1);
						 line(xaxis+1,yaxis+5,xaxis+1,128);
						 setfillstyle(1,4);bar(xaxis-2,yaxis+4,xaxis+2,yaxis+8);
						 xaxis+=7;
						}
					 //Showing Mouse
					 showMouse();
					}


void MyPiano::drawSwitchPanel()
					{
					 //Hiding Mouse
					 hideMouse();
					 //Drawing key holding bar and printing key notes
					 setfillstyle(1,9);bar(53,152,588,163);
					 setcolor(7);line(53,164,588,164);
					 setcolor(11);
					 outtextxy(67,155,"Q");
					 outtextxy(87,155,"W");
					 outtextxy(107,155,"E");
					 outtextxy(127,155,"R");
					 outtextxy(147,155,"T");
					 outtextxy(167,155,"Y");
					 outtextxy(187,155,"U");
					 outtextxy(207,155,"I");
					 outtextxy(227,155,"O");
					 outtextxy(247,155,"P");
					 outtextxy(267,155,"{");
					 outtextxy(287,155,"}");
					 outtextxy(307,155,"A");
					 outtextxy(327,155,"S");
					 outtextxy(347,155,"D");
					 outtextxy(367,155,"F");
					 outtextxy(387,155,"G");
					 outtextxy(407,155,"H");
					 outtextxy(427,155,"J");
					 outtextxy(447,155,"K");
					 outtextxy(467,155,"L");
					 outtextxy(487,155,":");
					 outtextxy(507,155,"Z");
					 outtextxy(527,155,"X");
					 outtextxy(547,155,"C");
					 outtextxy(567,155,"V");
					 //Adding switches
					 int black=0;
					 for(int nos=61;nos<=570;nos+=20)
					  {
						if(black<3)
						 {drawSwitch(nos,165,15);black++;}
						 else
						 {drawSwitch(nos,165,0);black=0;}
					  }
					 //Showing Mouse
					 showMouse();
					}
void MyPiano::drawSwitch(int x,int y,double color)
					{
					 hideMouse();
					 setfillstyle(1,color);bar(x,y,x+18,y+133);
					 setcolor(4);line(x,y,x,y+133);
					 setcolor(8);line(x+18,y,x+18,y+133);line(x,y+133,x+18,y+133);
					 showMouse();
					}
void MyPiano::drawProgressBar(int x,int y,int val,int color)
					{
					 hideMouse();
					 setcolor(15);rectangle(x-2,y,x+104,y+10);
					 setfillstyle(1,0);bar(x-1,y+1,x+103,y+9);
					 for(int bars=0;bars<val;bars++)
						{
						 setfillstyle(1,color);bar(x+2,y+2,x+5,y+8);
						 x=x+5;
						}
					 showMouse();
					}



void main()
		{
		 //Logging
		 Database dbase;
		 dbase.createLog("Opened:");
		 //Opening main progam
		 MyPiano mypiano;
		 mypiano.checkPassword();
		}


