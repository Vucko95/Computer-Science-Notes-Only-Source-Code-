/*
This source code is provided by Muhammad Saqib MYCPLUS Online Community WEbsite.
You are free to modify and change this code as per your requirements.

Website: http://4-tech-support.com/
Email:   msaqib@4-tech-support.com



*/

/*------------------------------------------------------------------------*/
/*			       C++ Editor                                 */
/*------------------------------------------------------------------------*/
/*                    SOURCE CODE WRITTEN BY: Muhammad Saqib              */
/*		      COMSATS Institute of Information Technology.        */
/*				     Abbottabad                           */
/*------------------------------------------------------------------------*/

/* HEADER FILES */

#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main(void)
{
int d=DETECT,m;
int i;
initgraph(&d,&m,"F:\\tc\\bgi");
		  setcolor(7);

		  for(i=0;i<=470;i++){
		  setcolor(1);
		  line(0,30+i,637,30+i); }

		  for(i=0;i<=637;i++){
		  setcolor(WHITE);
		  line(0+i,0,0+i,30);
		  }
		  setcolor(WHITE);

	line(3,40,3,436);         //vert left  //rt
	line(0,40,0,436);	  //vert left  //lt
	setcolor(WHITE);
	line(0,40,20,40);
	line(0,43,20,43);
		   setcolor(WHITE);
		   line(23,35,23,50);	// program exit box
		   line(23,35,27,35);
		   line(23,50,27,50);

		   setcolor(3);
		   outtextxy(31,38,"Û");	//exit point

		   setcolor(WHITE);
		   line(47,35,47,50);        // program exit point
		   line(44,35,47,35);
		   line(44,50,47,50);


	   setcolor(WHITE);
	   line(583,35,583,50);        // window size point
	   line(583,35,587,35);
	   line(583,50,587,50);
		 setcolor(WHITE);
	   line(612,35,612,50);        // window size point
	   line(612,35,608,35);
	   line(612,50,608,50);

	   setcolor(18);
	   outtextxy(593,35,"");
	   outtextxy(593,45,"");                 //arrow
	   line(597,35,597,50);                   //arrow
	   setcolor(WHITE);
	   line(50,40,270,40);     /////horiz  top
	   line(50,43,270,43);     /////horiz  top     left//2


	   outtextxy(280,39,"CIRCLE.CPP");

	   line(370,43,540,43);
	   line(370,40,540,40);  /////horiz  top    2   right
	   outtextxy(545,40,"1");
	   line(553,43,580,43);
	   line(553,40,580,40);  /////horiz  top    2   right


	   line(615,43,633,43);
	   line(615,40,635,40);/////horiz  top
	   for(i=0;i<=360;i++){
	   setcolor(19);
	   line(627,60+i,637,60+i);
	   }
	rectangle(627,60,638,420);
	setcolor(1);
	outtextxy(628,70,"");
	outtextxy(628,170,"Û");
	outtextxy(628,410,"");

	setcolor(WHITE);
	line(633,40,633,60);
	line(636,40,636,60);	  //vert  right
	line(633,430,633,420);
	line(620,430,633,430);

	line(0,434,30,434);
	line(0,430,30,430);      //horz    bottom
	outtextxy(33,430,"*");

	line(43,434,80,434);
	line(43,430,80,430);      //horz    bottom
	outtextxy(83,430,"10:5");
	line(123,434,160,434);
	line(123,430,160,430);      //horz    bottom

		for(i=0;i<=459;i++){
		setcolor(19);
		line(160+i,425,160+i,440);
		}
		setcolor(1);
		outtextxy(170,430,"<");
		outtextxy(607,430,">");
		outtextxy(367,430,"Û");


		for(i=0;i<=637;i++){
		setcolor(WHITE);
		line(0+i,443,0+i,470);

		}
		setcolor(4);
		outtextxy(16,453,"F1");
		setcolor(16);
		outtextxy(35,453,"Help");
		setcolor(4);
		outtextxy(85,453,"Alt-F8");
		setcolor(16);
		outtextxy(146,453,"Next Msg");
		setcolor(4);
		outtextxy(226,453,"Alt-F7");
		setcolor(16);
		outtextxy(286,453,"Prev-Msg");
		setcolor(4);
		outtextxy(358,453,"Alt-F9");
		setcolor(16);
		outtextxy(416,453,"Compile");
		setcolor(4);
		outtextxy(486,453,"F9");
		setcolor(16);
		outtextxy(516,453,"Make");
		setcolor(4);
		outtextxy(556,453,"F10");
		setcolor(16);
		outtextxy(586,453,"Menu");

			setcolor(4);
			outtextxy(8,15,"ð");
			setcolor(4);
			outtextxy(25,15,"F");
			setcolor(16);
			outtextxy(30,15,"ile");
			setcolor(4);
			outtextxy(72,15,"E");
			setcolor(16);
			outtextxy(80,15,"dit");
			setcolor(4);
			outtextxy(122,15,"S");
			setcolor(16);
			outtextxy(130,15,"earch");
			setcolor(4);
			outtextxy(182,15,"R");
			setcolor(16);
			outtextxy(190,15,"un");
			setcolor(4);
			outtextxy(222,15,"C");
			setcolor(16);
			outtextxy(230,15,"ompile");
			setcolor(4);
			outtextxy(292,15,"D");
			setcolor(16);
			outtextxy(300,15,"ebug");
			setcolor(4);
			outtextxy(352,15,"P");
			setcolor(16);
			outtextxy(360,15,"roject");
			setcolor(4);
			outtextxy(422,15,"O");
			setcolor(16);
			outtextxy(430,15,"ption");
			setcolor(4);
			outtextxy(492,15,"W");
			setcolor(16);
			outtextxy(500,15,"indow");
			setcolor(4);
			outtextxy(562,15,"H");
			setcolor(16);
			outtextxy(570,15,"elp");

			for(i=0;i<=160;i++){         //header files
			setcolor(19);
			line(15+i,50,15+i,70);         //
			line(15+i,70,15+i,90);         //
			line(15+i,90,15+i,100);          //
							   //
			 }                           //


			setcolor(1);
			outtextxy(15,60,"#include<graphics.h>");
			outtextxy(15,75,"#include<conio.h>");
			outtextxy(15,90,"#include<dos.h>");
			setcolor(10);
			outtextxy(15,105,"void main");     //
			setcolor(14);
			outtextxy(87,105,"(");     //
			setcolor(15);
			outtextxy(93,105,"void");     //

			setcolor(14);
			outtextxy(127,105,")");
			setcolor(15);
			outtextxy(20,120,"{");     //
			   //
			setcolor(15);
			outtextxy(20,130,"int");     //
			setcolor(10);
			outtextxy(60,130,"gdriver  DETECT  gmode");     //
			setcolor(15);
			outtextxy(119,130,"=");     //
			setcolor(15);
			outtextxy(184,130,",");     //
			setcolor(15);
			outtextxy(249,130,";");     //

			setcolor(10);
			outtextxy(20,145,"intitgraph");     //
			setcolor(15);
			outtextxy(100,145,"(                             \);  ");     //
			setcolor(10);
			outtextxy(117,145,"gdriver  gmode");
			setcolor(14);
			outtextxy(110,145,"&       ,&     ,");
			setcolor(4);
			outtextxy(110,145,"                ''c:\\tc\\bgi''");
			setcolor(10);
			outtextxy(20,165,"setcolor");
			setcolor(15);
			outtextxy(30,165,"       ( );");
			setcolor(7);
			outtextxy(30,165,"        5");

			setcolor(10);
			outtextxy(20,185,"circle");
			setcolor(15);
			outtextxy(70,185,"(   ,   ,  );");

			setcolor(7);
			outtextxy(79,185,"290 190 90");

			setcolor(10);
			outtextxy(20,205,"getch");
			setcolor(15);
			outtextxy(20,205,"     ();");
			setcolor(10);
			outtextxy(20,225,"cleardevice");
			setcolor(15);
			outtextxy(20,225,"           ():");
			setcolor(10);
			outtextxy(20,245,"closegraph");
			setcolor(15);
			outtextxy(20,245,"          ():");
			setcolor(10);
			outtextxy(20,265,"getch");
			setcolor(15);
			outtextxy(20,265,"     ():");
			outtextxy(20,285,"} ");
			setcolor(11);
			outtextxy(200,355,"//press any key to run this program:");
			getch();
			/*
			cleardevice();
			setcolor(5);
			circle(290,190,90);
			getch();
			*/

			}






























