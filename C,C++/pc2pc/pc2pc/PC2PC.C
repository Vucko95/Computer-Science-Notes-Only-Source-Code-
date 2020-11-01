/*
 PC to PC Communication via RS232 port.
 Chat with only 3-wire connection.

 Programmed by:
    Shreeharsha Perla	     &		Veena Pai

		III Sem. MSc. in Electronics,
		    Mangalore university
			 Karnataka

     email:
     harshaperla@rediffmail.com     e_veena@rediffmail.com

     website:          http:www.geocities.com/harshaperla
		       http://www.veenapai.tk

     Copyrights (c) 2004 Mangalore Universuty

*/

#include<conio.h>    //for getch, putch,textcolor...
#include<bios.h>     //for bioscom
#include<stdio.h>    //for file functions
#include<dos.h>
//#include<ctype.h>


#define COM1       0
//select com1(0x3f8)port
#define DATA_READY 0x100
#define SETTINGS ( 0x80 | 0x02 | 0x00 | 0x00)
//baud 1200, 7 data bits, no parity, 1 stop bit

void chatwindow();
int chatting();
void dsply(char *, int);
void welcome();

/****************************************************************************/
void main()
{
   textbackground(0);
   welcome();
   chatwindow();
   chatting();

}

void chatwindow()
{
  int i,j;
  textbackground(0);

  clrscr();
  cprintf("      Esc:  Exit      Enter: Send          :Recieved msg       :Sent msg");
  gotoxy(63,1);  textcolor(14);  putch(219);
  gotoxy(43,1);  textcolor(10);  putch(219);
  window(10,3,70,20);
  textbackground(1);
  clrscr();
  textcolor(3);
  window(1,1,80,25);

  for(i=0;i<=60;i++)
  {
     gotoxy(10+i,3);     putch(205);  //Í
     gotoxy(10+i,20);    putch(205);  //Í
  }
  for(j=0;j<=16;j++)
  {
     gotoxy(10,3+j);     putch(186);  //º
     gotoxy(70,3+j);     putch(186);  //º
  }

  gotoxy(10,3); putch(201);           //É
  gotoxy(70,3);putch(187);            //»
  gotoxy(10,20); putch(200);           //È
  gotoxy(70,20);putch(188);           //¼
  textbackground(3);
  textcolor(1);                       //BLUE
  window(1,22,80,24);
  clrscr();                           //make background blue
  window(1,1,80,25);

  for(i=1;i<=80;i++)
  {
      gotoxy(i,22);      putch('-');  //196
      gotoxy(i,24);      putch('-');  //Ä
  }
  gotoxy(2,23);  putch(16);           //

}
/****************************************************************************/
int chatting()
{
    char msg[80],msg_in[80];
    int status,out,in,count=0,count_in=0,i,extra;

    bioscom(0, SETTINGS, COM1); //init. port
    //alternative to outportb(),perticularly for rs 232 communication.

    window(3,23,80,23);         //message entry window
    while (1)
    {
      status = bioscom(3, 0, COM1);

      if (status & DATA_READY)
      {
	 if ((out = bioscom(2, 0, COM1) & 0x7F) != 0)// input message byte.
	    msg_in[count_in++]=out;
	 if(out==13)
	 {
	    dsply(msg_in,10);
	    count_in=0;
	    gotoxy(count+1,1);
	 }
      }

      if (kbhit())   //character entered
      {
	gotoxy(count+1,1);
	if ((in = getche()) == 27)
	   break;
	if(in==0)
	{
	   in= getch();  //special function key pressed, ignore
	   continue;
	}
	if(in==8 && count>0) { count-=2;cprintf(" \b");}     //BackSpace
	else msg[count]=in;
	if(count==70) {in=13; msg[70]=13;}

	count++;

	if(in==13 ) //Enter: Send
	{
	  i=0;
	  dsply(msg,14);
	  for(i=0;i<count;i++)
	  {
	     bioscom(1, msg[i], COM1);
	  }

	  clrscr();
	  count=0;
	}
     }
   }

    return 1;
}

void dsply(char str[80],int col)
{

   int i=0;
   static int line=1;
   window(11,4,69,19);       //Chat display window
   textbackground(1);        //BLUE
   textcolor(col);
   gotoxy(1,line);
    putch('\n');


    putch(175);
    while(str[i]!=13)
    {
	putch(str[i]);
	i++;
    }
    line=wherey();       //store present line
    window(3,23,80,23);  //message enter window
    textbackground(3);
    textcolor(1);
}
/****************************************************************************/

void welcome()
{
   int i,j;

   clrscr();
   textcolor(4);
   gotoxy(25,5);   cprintf("Welcome to PC to PC chat");
   gotoxy(22,6);   cprintf("Program for RS232 communication");
   textcolor(2);
   gotoxy(21,7);    cprintf("By  Shreeharsha Perla & Veena Pai");
   sleep(1);
   window(10,9,70,23);
  textbackground(1);
  clrscr();
  textcolor(3);
  window(1,1,80,25);

  for(i=0;i<=60;i++)
  {
     gotoxy(10+i,3);     putch(205);  //Í
     gotoxy(10+i,23);    putch(205);  //Í
  }
  for(j=0;j<=20;j++)
  {
     gotoxy(10,3+j);     putch(186);  //º
     gotoxy(70,3+j);     putch(186);  //º
  }
  gotoxy(10,3); putch(201);           //É
  gotoxy(70,3);putch(187);            //»
  gotoxy(10,23); putch(200);           //È
  gotoxy(70,23);putch(188);           //¼
  sleep(1);

  gotoxy(15,10);
//  cprintf("Enter: Send");
//  cprintf("\nEsc  : Exit");
//  cprintf("\nF1   : Help");
   window(12,11,68,22);
  cprintf("To start chating, connect serial port COM1"
	  " of both the     computers by a 3-wire link. "
	  "For more details about     connections and serial"
	  " port, Visit our website:                   "
	  "\n      http://eharsha.tk          ");
  gotoxy(3,12);
  cprintf("Press any key to start....");

  window(1,1,80,25);
  getch();


}































































