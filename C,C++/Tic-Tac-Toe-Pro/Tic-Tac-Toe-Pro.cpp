/*******************************************************
*     MYCPLUS Sample Code - http://www.mycplus.com     *
*                                                     *
*   This code is made available as a service to our   *
*      visitors and is provided strictly for the      *
*               purpose of illustration.              *
*                                                     *
* Please direct all inquiries to saqib at mycplus.com *
*******************************************************/

//Name: Usman Shahzada
//Email:  usmanshahzada@hotmail.com <mailto:usmanshahzada@hotmail.com> 
//Language: C\C++
//Category: Games\Graphics
//Description: PLAY TICTACPRO!!!

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <io.h>
main()
{
//_setcursortype(_NOCURSOR);
int x1=0, x2=0, x3=0, x4=0, x5=0, x6=0, x7=0, x8=0, x9=0;
int o1=0, o2=0, o3=0, o4=0, o5=0, o6=0, o7=0, o8=0, o9=0;
int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0;
int o123=0, o456=0, o789=0, o147=0, o258=0, o369=0, o159=0, o357=0;
int x123=0, x456=0, x789=0, x147=0, x258=0, x369=0, x159=0, x357=0;
int lo, di, delayx, delayload, full=0, full2=0, n, nowin=0;
char x, ver, opt, choices, choices2, race, code[100], uninst, colcho,
quit;
int xwin=0, owin=0, gameno=0, race2, fullver, pat=8, xs=10, os=9,
htxt=15, txt=8;


if(access("c:\\DSI.tic", 0)==0)
  delayx=0;
else
  delayx=1;
if(access("c:\\fastlo.pro", 0)==0)
  delayload=50;
else
  delayload=200;


if(access("c:\\theme1.col", 0)==0)
  {
  pat=8;
  xs=9;
  os=10;
  txt=15;
  htxt=8;
  }
else if(access("c:\\theme2.col", 0)==0)
  {
  pat=8;
  xs=2;
  os=1;
  txt=8;
  htxt=7;
  }
else if(access("c:\\theme3.col", 0)==0)
  {
  pat=8;
  xs=7;
  os=15;
  txt=7;
  htxt=15;
  }


intro:
clrscr();
sleep(delayx);
textcolor(7);
gotoxy(34,1);cprintf("TIC");
sleep(delayx);
gotoxy(38,1);cprintf("TAC");
sleep(delayx);
textcolor(3);
gotoxy(42,1);cprintf("PRO");
sleep(delayx);
textcolor(pat);
gotoxy(34,3);cprintf("   €   €");
gotoxy(34,4);cprintf("‹‹‹€‹‹‹€‹‹‹");
gotoxy(34,5);cprintf("   €   €");
gotoxy(34,6);cprintf("‹‹‹€‹‹‹€‹‹‹");
gotoxy(34,7);cprintf("   €   €");
gotoxy(34,8);cprintf("   ﬂ   ﬂ");
sleep(delayx);
textcolor(os);
gotoxy(35,3);cprintf("o");
sleep(delayx);
textcolor(xs);
gotoxy(35,5);cprintf("x");
sleep(delayx);
textcolor(os);
gotoxy(43,3);cprintf("o");
sleep(delayx);
textcolor(xs);
gotoxy(39,3);cprintf("x");
sleep(delayx);
textcolor(os);
gotoxy(43,7);cprintf("o");
sleep(delayx);
textcolor(xs);
gotoxy(43,5);cprintf("x");
sleep(delayx);
textcolor(os);
gotoxy(39,5);cprintf("o");
sleep(delayx);
textcolor(txt);
gotoxy(33,14);cprintf(" ractice game");
gotoxy(33,12);cprintf("Versus  riend");
gotoxy(36,16);cprintf(" ptions");
gotoxy(35,10);cprintf(" ournament");
gotoxy(37,18);cprintf("E it");
gotoxy(36,20);cprintf(" redits");
gotoxy(35,22);cprintf("Uninst ll");
gotoxy(68,25);cprintf("F ll version");
textcolor(8);
gotoxy(1,25);cprintf("Best viewed in maximize window");
textcolor(15);
gotoxy(34,1);cprintf("TIC TAC");
textcolor(11);
gotoxy(42,1);cprintf("PRO");
textcolor(htxt);
gotoxy(33,14);cprintf("P");
gotoxy(40,12);cprintf("f");
gotoxy(36,16);cprintf("O");
gotoxy(35,10);cprintf("T");
gotoxy(38,18);cprintf("x");
gotoxy(36,20);cprintf("C");
gotoxy(41,22);cprintf("a");
gotoxy(69,25);cprintf("u");
if(access("c:\\FULLTTP.enx", 0)==0)
  {
  textcolor(8);
  gotoxy(68,25);cprintf("Full version");
  }
textcolor(0);
verback:
gotoxy(1,1);cscanf("%c", &ver);


if(ver=='f' || ver=='F')
{
if(access("c:\\FULLTTP.enx", 0)==-1)
  {
  clrscr();
  textcolor(4);
  gotoxy(28,13);cprintf("GET THE FULL VERSION FIRST!");
  sleep(2);
  delayx=0;
  goto intro;
  }
clrscr();
for(lo=28; lo<=53; lo++)
{
textcolor(8);
gotoxy(lo,14);cprintf("€€");
}


for(lo=0, di=28; lo<=100; lo+=4, di++)
{
textcolor(15);
gotoxy(28,12);cprintf("initializing game...");
gotoxy(28,13);cprintf("%d%", lo);
gotoxy(di,14);cprintf("€€");
delay(delayload);
}


sleep(2);


clrscr();
textcolor(15);
gotoxy(34,1);cprintf("TIC TAC");
textcolor(11);
gotoxy(42,1);cprintf("PRO");
textcolor(pat);
gotoxy(34,3);cprintf(" 1 € 2 € 3");
gotoxy(34,4);cprintf("‹‹‹€‹‹‹€‹‹‹");
gotoxy(34,5);cprintf(" 4 € 5 € 6");
gotoxy(34,6);cprintf("‹‹‹€‹‹‹€‹‹‹");
gotoxy(34,7);cprintf(" 7 € 8 € 9");
gotoxy(34,8);cprintf("   ﬂ   ﬂ");
backgame:
textcolor(txt);
gotoxy(1,25);cprintf("E it");
textcolor(htxt);
gotoxy(2,25);cprintf("x");
gotoxy(31,10);cprintf("Enter your choice!");


y:
textcolor(os);
gotoxy(39,9);cprintf("o");
textcolor(0);
gotoxy(50,10);cscanf("%c", &x);
textcolor(os);
if(x=='1')
  {
  gotoxy(35,3);cprintf("o");
  a1++;
  o123++;
  o147++;
  o159++;
  full++;
  if(a1==2)
    goto h;
  else if(o123==3 || o147==3 || o159==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='2')
  {
  gotoxy(39,3);cprintf("o");
  a2++;
  o123++;
  o258++;
  full++;
  if(a2==2)
    goto h;
  else if(o123==3 || o258==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='3')
  {
  gotoxy(43,3);cprintf("o");
  a3++;
  o123++;
  o369++;
  o357++;
  full++;
  if(a3==2)
    goto h;
  else if(o123==3 || o369==3 || o357==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='4')
  {
  gotoxy(35,5);cprintf("o");
  a4++;
  o147++;
  o456++;
  full++;
  if(a4==2)
    goto h;
  else if(o147==3 || o456==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='5')
  {
  gotoxy(39,5);cprintf("o");
  a5++;
  o159++;
  o456++;
  o258++;
  o357++;
  full++;
  if(a5==2)
    goto h;
  else if(o159==3 || o456==3 || o258==3 || o357==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='6')
  {
  gotoxy(43,5);cprintf("o");
  a6++;
  o369++;
  o456++;
  full++;
  if(a6==2)
    goto h;
  else if(o369==3 || o456==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='7')
  {
  gotoxy(35,7);cprintf("o");
  a7++;
  o147++;
  o789++;
  o357++;
  full++;
  if(a7==2)
    goto h;
  else if(o147==3 || o789==3 || o357==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='8')
  {
  gotoxy(39,7);cprintf("o");
  a8++;
  o789++;
  o258++;
  full++;
  if(a8==2)
    goto h;
  else if(o789==3 || o258==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='9')
  {
  gotoxy(43,7);cprintf("o");
  a9++;
  o789++;
  o369++;
  o159++;
  full++;
  if(a9==2)
    goto h;
  else if(o789==3 || o369==3 || o159==3)
    goto owins;
  else if(full==9)
    goto g;
  else
    goto z;
  }
else if(x=='x' || x=='X')
  {
  quitback:
  textcolor(txt);
  gotoxy(1,25);cprintf("Are you sure?  es or  o");
  textcolor(htxt);
  gotoxy(15,25);cprintf("y");
  gotoxy(22,25);cprintf("n");
  textcolor(0);
  gotoxy(1,25);cscanf("%c", &quit);
  if(quit=='y' || quit=='Y')
    goto g3;
  else if(quit=='n' || quit=='N')
    {
    gotoxy(1,25);cprintf("                       ");
    goto backgame;
    }
  else
    goto quitback;
  }
else
  goto y;


z:
backgame2:
textcolor(txt);
gotoxy(1,25);cprintf("E it");
textcolor(htxt);
gotoxy(2,25);cprintf("x");
textcolor(xs);
gotoxy(39,9);cprintf("x");
textcolor(0);
gotoxy(50,10);cscanf("%c", &x);
textcolor(xs);
if(x=='1')
  {
  gotoxy(35,3);cprintf("x");
  a1++;
  x123++;
  x147++;
  x159++;
  full++;
  if(a1==2)
    goto h;
  else if(x123==3 || x147==3 || x159==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='2')
  {
  gotoxy(39,3);cprintf("x");
  a2++;
  x123++;
  x258++;
  full++;
  if(a2==2)
    goto h;
  else if(x123==3 || x258==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='3')
  {
  gotoxy(43,3);cprintf("x");
  a3++;
  x123++;
  x369++;
  x357++;
  full++;
  if(a3==2)
    goto h;
  else if(x123==3 || x369==3 || x357==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='4')
  {
  gotoxy(35,5);cprintf("x");
  a4++;
  x147++;
  x456++;
  full++;
  if(a4==2)
    goto h;
  else if(x147==3 || x456==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='5')
  {
  gotoxy(39,5);cprintf("x");
  a5++;
  x258++;
  x456++;
  x159++;
  x357++;
  full++;
  if(a5==2)
    goto h;
  else if(x258==3 || x456==3 || x159==3 || x357==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='6')
  {
  gotoxy(43,5);cprintf("x");
  a6++;
  x456++;
  x369++;
  full++;
  if(a6==2)
    goto h;
  else if(x456==3 || x369==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='7')
  {
  gotoxy(35,7);cprintf("x");
  a7++;
  x147++;
  x789++;
  x357++;
  full++;
  if(a7==2)
    goto h;
  else if(x147==3 || x789==3 || x357==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='8')
  {
  gotoxy(39,7);cprintf("x");
  a8++;
  x789++;
  x258++;
  full++;
  if(a8==2)
    goto h;
  else if(x789==3 || x258==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='9')
  {
  gotoxy(43,7);cprintf("x");
  a9++;
  x369++;
  x789++;
  x159++;
  full++;
  if(a9==2)
    goto h;
  else if(x369==3 || x789==3 || x159==3)
    goto xwins;
  else if(full==9)
    goto g;
  else
    goto y;
  }
else if(x=='x' || x=='X')
  {
  quitback2:
  textcolor(txt);
  gotoxy(1,25);cprintf("Are you sure?  es or  o");
  textcolor(htxt);
  gotoxy(15,25);cprintf("y");
  gotoxy(22,25);cprintf("n");
  textcolor(0);
  gotoxy(1,25);cscanf("%c", &quit);
  if(quit=='y' || quit=='Y')
    goto g3;
  else if(quit=='n' || quit=='N')
    {
    gotoxy(1,25);cprintf("                       ");
    goto backgame2;
    }
  else
    goto quitback2;
  }
else
  goto z;


owins:
sleep(2);
clrscr();


textcolor(os);
gotoxy(36,13);cprintf("o");
textcolor(15);
gotoxy(38,13);cprintf("wins!");
sleep(2);
if(ver=='t' || ver=='T')
  {
  owin++;
  if(owin==race2)
    {
    textcolor(os);
    gotoxy(34,13);cprintf("o");
    textcolor(15);
    gotoxy(36,13);cprintf("champion!");
    sleep(2);
    goto g3;
    }
  else
    goto tour2;
  }
else
  goto g3;



xwins:
sleep(2);
clrscr();
textcolor(xs);
gotoxy(36,13);cprintf("x");
textcolor(15);
gotoxy(38,13);cprintf("wins!");
sleep(2);
if(access("c:\\FULLTTP.enx", 0)==-1 && choices=='m' ||
access("c:\\FULLTTP.enx", 0)==-1 && choices=='M')
  {
  clrscr();
  for(fullver=9; fullver>=1; fullver--)
    {
    textcolor(8);
    gotoxy(1,1);cprintf(" ode:  ro2002");
    gotoxy(1,25);cprintf("%d", fullver);
    gotoxy(79,25);cprintf("%d", fullver);
    gotoxy(79,1);cprintf("%d", fullver);
    textcolor(15);
    gotoxy(1,1);cprintf("C");
    gotoxy(7,1);cprintf("P");
    sleep(1);
    }
  goto g3;
  }
if(ver=='t' || ver=='T')
  {
  xwin++;
  if(xwin==race2)
    {
    textcolor(xs);
    gotoxy(34,13);cprintf("x");
    textcolor(15);
    gotoxy(36,13);cprintf("champion!");
    sleep(2);
    goto g3;
    }
  else
    goto tour2;
  }
else
  goto g3;



h:
clrscr();
textcolor(4);
gotoxy(34,13);cprintf("Already Used!");


g:
sleep(2);
if(ver=='t' || ver=='T')
  {
  goto tour2;
  }
g3:
clrscr();
textcolor(4);
gotoxy(35,13);cprintf("GAME OVER!");
}
else if(ver=='t' || ver=='T')
  {
  if(access("c:\\FULLTTP.enx", 0)==-1)
    {
    clrscr();
    textcolor(4);
    gotoxy(28,13);cprintf("GET THE FULL VERSION FIRST!");
    sleep(2);
    delayx=0;
    goto intro;
    }
  tour:
  raceback:
  clrscr();
  textcolor(txt);
  gotoxy(1,1);cprintf("Race to");
  gotoxy(1,3);cprintf("Race to");
  gotoxy(1,5);cprintf("Race to");
  gotoxy(1,7);cprintf("Race to");
  textcolor(htxt);
  gotoxy(9,1);cprintf("3");
  gotoxy(9,3);cprintf("5");
  gotoxy(9,5);cprintf("7");
  gotoxy(9,7);cprintf("9");
  textcolor(0);
  gotoxy(1,25);cscanf("%c", &race);
  if(race=='3')
    race2=3;
  else if(race=='5')
    race2=5;
  else if(race=='7')
    race2=7;
  else if(race=='9')
    race2=9;
  else
    goto raceback;
  tour2:
  x1=0, x2=0, x3=0, x4=0, x5=0, x6=0, x7=0, x8=0, x9=0;
  o1=0, o2=0, o3=0, o4=0, o5=0, o6=0, o7=0, o8=0, o9=0;
  a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0;
  o123=0, o456=0, o789=0, o147=0, o258=0, o369=0, o159=0, o357=0;
  x123=0, x456=0, x789=0, x147=0, x258=0, x369=0, x159=0, x357=0;
  full=0, full2=0;
  gameno++;
  if(gameno%2==0)
    {
    n=1;
    nowin=1;
    }
  else
    n=0;
  goto ch2back;
  }
else if(ver=='p' || ver=='P')
{
chback:
clrscr();
textcolor(txt);
gotoxy(1,1);cprintf(" ovice");
gotoxy(1,3);cprintf(" aster");
textcolor(htxt);
gotoxy(1,1);cprintf("N");
gotoxy(1,3);cprintf("M");
textcolor(0);
gotoxy(1,25);cscanf("%c", &choices);
if(choices=='n' || choices=='N')
  n=0;
else if(choices=='m' || choices=='M')
  n=1;
else
 goto chback;


ch2back:
clrscr();
textcolor(txt);
gotoxy(73,23);cprintf(" efense");
gotoxy(73,25);cprintf(" ffense");
textcolor(htxt);
gotoxy(73,23);cprintf("D");
gotoxy(73,25);cprintf("O");
textcolor(0);
gotoxy(1,1);cscanf("%c", &choices2);
clrscr();
if(choices2=='D' || choices2=='d')
  {
  full2++;
  o3++;
  a3++;
  o123++;
  o369++;
  o357++;
  if(gameno>1)
    {
    textcolor(15);
    gotoxy(33,13);cprintf("updating game...");
    sleep(2);
    goto leapload;
    }
  }
else if(choices2=='O' || choices2=='o')
  {
  if(gameno>1)
    {
    textcolor(15);
    gotoxy(33,13);cprintf("updating game...");
    sleep(2);
    goto leapload;
    }
  else
    goto loading;
  }
else
  goto ch2back;


loading:
clrscr();
for(lo=28; lo<=53; lo++)
{
textcolor(8);
gotoxy(lo,14);cprintf("€€");
}


for(lo=0, di=28; lo<=100; lo+=4, di++)
{
textcolor(15);
gotoxy(28,12);cprintf("initializing game...");
gotoxy(28,13);cprintf("%d%", lo);
gotoxy(di,14);cprintf("€€");
delay(delayload);
}
sleep(2);


leapload:
clrscr();
if(choices=='n' || choices=='N')
  {
  textcolor(8);
  gotoxy(74,25);cprintf("Novice");
  }
else if(choices=='m' || choices=='M')
  {
  textcolor(8);
  gotoxy(74,25);cprintf("Master");
  }
if(race=='3')
  {
  textcolor(8);
  gotoxy(71,25);cprintf("Race to 3");
  }
else if(race=='5')
  {
  textcolor(8);
  gotoxy(71,25);cprintf("Race to 5");
  }
else if(race=='7')
  {
  textcolor(8);
  gotoxy(71,25);cprintf("Race to 7");
  }
else if(race=='9')
  {
  textcolor(8);
  gotoxy(71,25);cprintf("Race to 9");
  }


if(ver=='t' || ver=='T')
  {
  textcolor(os);
  gotoxy(37,12);cprintf("o");
  textcolor(xs);
  gotoxy(37,13);cprintf("x");
  textcolor(7);
  gotoxy(39,12);cprintf("- %d", owin);
  gotoxy(39,13);cprintf("- %d", xwin);
  }


textcolor(15);
gotoxy(34,1);cprintf("TIC TAC");
textcolor(11);
gotoxy(42,1);cprintf("PRO");
textcolor(pat);
gotoxy(34,3);cprintf(" 1 € 2 € 3");
gotoxy(34,4);cprintf("‹‹‹€‹‹‹€‹‹‹");
gotoxy(34,5);cprintf(" 4 € 5 € 6");
gotoxy(34,6);cprintf("‹‹‹€‹‹‹€‹‹‹");
gotoxy(34,7);cprintf(" 7 € 8 € 9");
gotoxy(34,8);cprintf("   ﬂ   ﬂ");
if(choices2=='D' || choices2=='d')
  {
  textcolor(os);
  gotoxy(43,3);cprintf("o");
  }
else
  goto offense;
offense:
textcolor(txt);
gotoxy(1,25);cprintf("E it");
textcolor(htxt);
gotoxy(2,25);cprintf("x");
gotoxy(31,10);cprintf("Enter your choice!");
xplay:
textcolor(xs);
gotoxy(39,9);cprintf("x");
textcolor(0);
gotoxy(50,10);cscanf("%c", &x);
if(x=='1')
  {
  textcolor(xs);
  gotoxy(35,3);cprintf("x");
  x1++;
  a1++;
  x123++;
  x147++;
  x159++;
  full++;
  if(a1==2)
    goto h;
  else if(x123==3 || x147==3 || x159==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down2;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down3;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down4;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down6;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down7;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down8;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down9;
  else if(a2==0 && x1==n && x3==n)
    goto down2;
  else if(a3==0 && x1==n && x2==n)
    goto down3;
  else if(a4==0 && x1==n && x7==n)
    goto down4;
  else if(a7==0 && x1==n && x4==n)
    goto down7;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o357++;
    o159++;
    if(o456==3 || o258==3 || o357==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0 && x6==1 || a2==0 && x9==1)
    {
    down2:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    down7:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    down3:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down4:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down6:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down8:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0)
    {
    down9:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='2')
  {
  textcolor(xs);
  gotoxy(39,3);cprintf("x");
  x2++;
  a2++;
  x123++;
  x258++;
  full++;
  if(a2==2)
    goto h;
  else if(x123==3 || x258==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down21;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down23;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down24;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down26;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down27;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down28;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down29;
  else if(a1==0 && x2==n && x3==n)
    goto down21;
  else if(a3==0 && x1==n && x2==n)
    goto down23;
  else if(a8==0 && x2==n && x5==n)
    goto down28;
  else if(a5==0)
    {
    down25:
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o357++;
    o159++;
    if(o456==3 || o258==3 || o357==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down21:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    down23:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down24:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down26:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    down27:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down28:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0)
    {
    down29:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='3')
  {
  textcolor(xs);
  gotoxy(43,3);cprintf("x");
  x3++;
  a3++;
  x123++;
  x369++;
  x357++;
  full++;
  if(a3==2)
    goto h;
  else if(x123==3 || x369==3 || x357==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down31;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down32;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down34;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down36;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down37;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down38;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down39;
  else if(a1==0 && x2==n && x3==n)
    goto down31;
  else if(a2==0 && x1==n && x3==n)
    goto down32;
  else if(a6==0 && x3==n && x9==n)
    goto down36;
  else if(a7==0 && x3==n && x5==n)
    goto down37;
  else if(a9==0 && x3==n && x6==n)
    goto down39;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o357++;
    o159++;
    if(o456==3 || o258==3 || o357==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0 && x8==1)
    {
    down39:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    down32:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down31:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down34:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down36:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    down37:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down38:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='4')
  {
  textcolor(xs);
  gotoxy(35,5);cprintf("x");
  x4++;
  a4++;
  x456++;
  x147++;
  full++;
  if(a4==2)
    goto h;
  else if(x456==3 || x147==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down41;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down42;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down43;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down46;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down47;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down48;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down49;
  else if(a1==0 && x4==n && x7==n)
    goto down41;
  else if(a6==0 && x4==n && x5==n)
    goto down46;
  else if(a7==0 && x1==n && x4==n)
    goto down47;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o357++;
    o159++;
    if(o456==3 || o258==3 || o357==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    down47:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down41:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    down42:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    down43:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down46:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down48:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0)
    {
    down49:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='5')
  {
  textcolor(xs);
  gotoxy(39,5);cprintf("x");
  x5++;
  a5++;
  x456++;
  x258++;
  x159++;
  x357++;
  full++;
  if(a5==2)
    goto h;
  else if(x456==3 || x258==3 || x159==3 || x357==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='6')
  {
  textcolor(xs);
  gotoxy(43,5);cprintf("x");
  x6++;
  a6++;
  x456++;
  x369++;
  full++;
  if(a6==2)
    goto h;
  else if(x456==3 || x369==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down61;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down62;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down63;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down64;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down67;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down68;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down69;
  else if(a3==0 && x6==n && x9==n)
    goto down63;
  else if(a4==0 && x5==n && x6==n)
    goto down64;
  else if(a9==0 && x3==n && x6==n)
    goto down69;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o159++;
    o357++;
    if(o456==3 || o258==3 || o159==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0 && x7==1 || a9==0 && x8==nowin)
    {
    down69:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down61:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    down62:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    down63:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down64:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    down67:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down68:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='7')
  {
  textcolor(xs);
  gotoxy(35,7);cprintf("x");
  x7++;
  a7++;
  x789++;
  x147++;
  x357++;
  full++;
  if(a7==2)
    goto h;
  else if(x789==3 || x147==3 || x357==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down71;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down72;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down73;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down74;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down76;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down78;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down79;
  else if(a1==0 && x4==n && x7==n)
    goto down71;
  else if(a3==0 && x5==n && x7==n)
    goto down73;
  else if(a4==0 && x1==n && x7==n)
    goto down74;
  else if(a8==0 && x7==n && x9==n)
    goto down78;
  else if(a9==0 && x7==n && x8==n)
    goto down79;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o159++;
    o357++;
    if(o456==3 || o258==3 || o159==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    down72:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down71:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    down73:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down74:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down76:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down78:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0)
    {
    down79:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='8')
  {
  textcolor(xs);
  gotoxy(39,7);cprintf("x");
  x8++;
  a8++;
  x789++;
  x258++;
  full++;
  if(a8==2)
    goto h;
  else if(x789==3 || x258==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down81;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down82;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down83;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down84;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down86;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down87;
  else if(a9==0 && o7==1 && o8==1 || a9==0 && o3==1 && o6==1 || a9==0
&& o1==1 && o5==1)
    goto down89;
  else if(a2==0 && x5==n && x8==n)
    goto down82;
  else if(a7==0 && x8==n && x9==n)
    goto down87;
  else if(a9==0 && x7==n && x8==n)
    goto down89;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o159++;
    o357++;
    if(o456==3 || o258==3 || o159==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
   else if(a7==0)
    {
    down87:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down81:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    down82:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0)
    {
    down83:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down84:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down86:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a9==0)
    {
    down89:
    sleep(1);
    textcolor(os);
    gotoxy(43,7);cprintf("o");
    full2++;
    o9++;
    a9++;
    o789++;
    o369++;
    o159++;
    if(o789==3 || o369==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='9')
  {
  textcolor(xs);
  gotoxy(43,7);cprintf("x");
  x9++;
  a9++;
  x789++;
  x369++;
  x159++;
  full++;
  if(a9==2)
    goto h;
  else if(x789==3 || x369==3 || x159==3)
    goto xwins;
  else if(full==5)
    goto g;
  else if(a1==0 && o2==1 && o3==1 || a1==0 && o4==1 && o7==1 || a1==0
&& o5==1 && o9==1)
    goto down91;
  else if(a2==0 && o1==1 && o3==1 || a2==0 && o5==1 && o8==1)
    goto down92;
  else if(a3==0 && o1==1 && o2==1 || a3==0 && o6==1 && o9==1 || a3==0
&& o5==1 && o7==1)
    goto down93;
  else if(a4==0 && o5==1 && o6==1 || a4==0 && o1==1 && o7==1)
    goto down94;
  else if(a6==0 && o4==1 && o5==1 || a6==0 && o3==1 && o9==1)
    goto down96;
  else if(a7==0 && o8==1 && o9==1 || a7==0 && o1==1 && o4==1 || a7==0
&& o3==1 && o5==1)
    goto down97;
  else if(a8==0 && o7==1 && o9==1 || a8==0 && o2==1 && o5==1)
    goto down98;
  else if(a3==0 && x6==n && x9==n)
    goto down93;
  else if(a6==0 && x3==n && x9==n)
    goto down96;
  else if(a7==0 && x8==n && x9==n)
    goto down97;
  else if(a8==0 && x7==n && x9==n)
    goto down98;
  else if(a5==0)
    {
    sleep(1);
    textcolor(os);
    gotoxy(39,5);cprintf("o");
    full2++;
    o5++;
    a5++;
    o456++;
    o258++;
    o159++;
    o357++;
    if(o456==3 || o258==3 || o159==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a3==0 && x9==1 && x5==1)
    {
    down93:
    sleep(1);
    textcolor(os);
    gotoxy(43,3);cprintf("o");
    full2++;
    o3++;
    a3++;
    o123++;
    o369++;
    o357++;
    if(o123==3 || o369==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a1==0)
    {
    down91:
    sleep(1);
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    full2++;
    o1++;
    a1++;
    o123++;
    o147++;
    o159++;
    if(o123==3 || o147==3 || o159==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a8==0)
    {
    down98:
    sleep(1);
    textcolor(os);
    gotoxy(39,7);cprintf("o");
    full2++;
    o8++;
    a8++;
    o789++;
    o258++;
    if(o789==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a2==0)
    {
    down92:
    sleep(1);
    textcolor(os);
    gotoxy(39,3);cprintf("o");
    full2++;
    o2++;
    a2++;
    o123++;
    o258++;
    if(o123==3 || o258==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a4==0)
    {
    down94:
    sleep(1);
    textcolor(os);
    gotoxy(35,5);cprintf("o");
    full2++;
    o4++;
    a4++;
    o456++;
    o147++;
    if(o456==3 || o147==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a6==0)
    {
    down96:
    sleep(1);
    textcolor(os);
    gotoxy(43,5);cprintf("o");
    full2++;
    o6++;
    a6++;
    o456++;
    o369++;
    if(o456==3 || o369==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  else if(a7==0)
    {
    down97:
    sleep(1);
    textcolor(os);
    gotoxy(35,7);cprintf("o");
    full2++;
    o7++;
    a7++;
    o789++;
    o147++;
    o357++;
    if(o789==3 || o147==3 || o357==3)
      goto owins;
    else if(full2==5)
      goto g;
    }
  goto xplay;
  }
else if(x=='x' || x=='X')
  {
  quitback3:
  textcolor(txt);
  gotoxy(1,25);cprintf("Are you sure?  es or  o");
  textcolor(htxt);
  gotoxy(15,25);cprintf("y");
  gotoxy(22,25);cprintf("n");
  textcolor(0);
  gotoxy(1,25);cscanf("%c", &quit);
  if(quit=='y' || quit=='Y')
    goto g3;
  else if(quit=='n' || quit=='N')
    {
    gotoxy(1,25);cprintf("                       ");
    goto offense;
    }
  else
    goto quitback3;
  }
else
  goto xplay;
}
else if(ver=='x' || ver=='X')
  goto g3;
else if(ver=='o' || ver=='O')
  {
  if(access("c:\\FULLTTP.enx", 0)==-1)
    {
    clrscr();
    textcolor(4);
    gotoxy(28,13);cprintf("GET THE FULL VERSION FIRST!");
    sleep(2);
    delayx=0;
    goto intro;
    }
  optback:
  clrscr();
  textcolor(txt);
  gotoxy(1,1);cprintf(" how intro on startup");
  gotoxy(1,3);cprintf(" on't show intro on startup");
  gotoxy(1,7);cprintf(" ast game loading");
  gotoxy(1,9);cprintf("S ooth game loading");
  gotoxy(1,13);cprintf(" olors");
  gotoxy(1,25);cprintf("E it");
  textcolor(htxt);
  gotoxy(1,13);cprintf("C");
  gotoxy(2,25);cprintf("x");
  if(access("c:\\DSI.tic", 0)==0)
    {
    textcolor(14);
    gotoxy(1,3);cprintf("D");
    textcolor(htxt);
    gotoxy(1,1);cprintf("S");
    }
  else
    {
    textcolor(14);
    gotoxy(1,1);cprintf("S");
    textcolor(htxt);
    gotoxy(1,3);cprintf("D");
    }
  if(access("c:\\fastlo.pro", 0)==0)
    {
    textcolor(14);
    gotoxy(1,7);cprintf("F");
    textcolor(htxt);
    gotoxy(2,9);cprintf("m");
    }
  else
    {
    textcolor(14);
    gotoxy(2,9);cprintf("m");
    textcolor(htxt);
    gotoxy(1,7);cprintf("F");
    }
  textcolor(0);
  gotoxy(40,25);cscanf("%c", &opt);
  if(opt=='d' || opt=='D')
    {
    //_creat("c:\\DSI.tic", FA_HIDDEN);
    goto optback;
    }
  if(opt=='s' || opt=='S')
    {
    remove("c:\\DSI.tic");
    goto optback;
    }
  if(opt=='f' || opt=='F')
    {
    //_creat("c:\\fastlo.pro", FA_HIDDEN);
    delayload=50;
    goto optback;
    }
  if(opt=='m' || opt=='M')
    {
    remove("c:\\fastlo.pro");
    delayload=200;
    goto optback;
    }
  if(opt=='c' || opt=='C')
    {
    clrscr();
    colchaback:
    textcolor(11);
    gotoxy(36,1);cprintf("PRO");
    textcolor(15);
    gotoxy(39,1);cprintf("VIEW");
    textcolor(pat);
    gotoxy(34,3);cprintf("   €   €");
    gotoxy(34,4);cprintf("‹‹‹€‹‹‹€‹‹‹");
    gotoxy(34,5);cprintf("   €   €");
    gotoxy(34,6);cprintf("‹‹‹€‹‹‹€‹‹‹");
    gotoxy(34,7);cprintf("   €   €");
    gotoxy(34,8);cprintf("   ﬂ   ﬂ");
    textcolor(os);
    gotoxy(35,3);cprintf("o");
    gotoxy(43,3);cprintf("o");
    gotoxy(39,5);cprintf("o");
    gotoxy(43,7);cprintf("o");
    textcolor(xs);
    gotoxy(35,5);cprintf("x");
    gotoxy(39,3);cprintf("x");
    gotoxy(43,5);cprintf("x");
    textcolor(txt);
    gotoxy(1,25);cprintf("E it");
    gotoxy(36,10);cprintf("Theme");
    gotoxy(36,11);cprintf("Theme");
    gotoxy(36,12);cprintf("Theme");
    gotoxy(73,25);cprintf(" efault");
    textcolor(htxt);
    gotoxy(2,25);cprintf("x");
    gotoxy(42,10);cprintf("1");
    gotoxy(42,11);cprintf("2");
    gotoxy(42,12);cprintf("3");
    gotoxy(73,25);cprintf("D");
    if(access("c:\\theme1.col", 0)==-1 && access("c:\\theme2.col",
0)==-1 && access("c:\\theme3.col", 0)==-1)
      {
      textcolor(14);
      gotoxy(73,25);cprintf("D");
      }
    else if(access("c:\\theme1.col", 0)==0)
      {
      textcolor(14);
      gotoxy(42,10);cprintf("1");
      }
    else if(access("c:\\theme2.col", 0)==0)
      {
      textcolor(14);
      gotoxy(42,11);cprintf("2");
      }
    else if(access("c:\\theme3.col", 0)==0)
      {
      textcolor(14);
      gotoxy(42,12);cprintf("3");
      }
    textcolor(0);
    gotoxy(40,25);cscanf("%c", &colcho);
    if(colcho=='1')
      {
      pat=8;
      xs=9;
      os=10;
      txt=15;
      htxt=8;
//      _creat("c:\\theme1.col", FA_HIDDEN);
      remove("c:\\theme2.col");
      remove("c:\\theme3.col");
      goto colchaback;
      }
    else if(colcho=='2')
      {
      pat=8;
      xs=2;
      os=1;
      txt=8;
      htxt=7;
//      _creat("c:\\theme2.col", FA_HIDDEN);
      remove("c:\\theme1.col");
      remove("c:\\theme3.col");
      goto colchaback;
      }
    else if(colcho=='3')
      {
      pat=8;
      xs=7;
      os=15;
      txt=7;
      htxt=15;
//      _creat("c:\\theme3.col", FA_HIDDEN);
      remove("c:\\theme1.col");
      remove("c:\\theme2.col");
      goto colchaback;
      }
    else if(colcho=='d' || colcho=='D')
      {
      pat=8;
      xs=10;
      os=9;
      htxt=15;
      txt=8;
      remove("c:\\theme1.col");
      remove("c:\\theme2.col");
      remove("c:\\theme3.col");
      goto colchaback;
      }
    else if(colcho=='x' || colcho=='X')
      goto optback;
    else
      goto colchaback;
    }
  if(opt=='x' || opt=='X')
    {
    delayx=0;
    goto intro;
    }
  else
    goto optback;
  }
else if(ver=='c' || ver=='C')
  {
  clrscr();
  textcolor(txt);
  gotoxy(1,1);cprintf(" rogrammer:  nrico  orenzo");
  gotoxy(1,3);cprintf(" pecial thanks to:  ade  uliano");
  gotoxy(1,5);cprintf(" nspired by:  ic  ac  oe");
  gotoxy(1,25);cprintf(" ress any key to exit");
  textcolor(htxt);
  gotoxy(1,1);cprintf("P");
  gotoxy(13,1);cprintf("E");
  gotoxy(20,1);cprintf("L");
  gotoxy(1,3);cprintf("S");
  gotoxy(20,3);cprintf("J");
  gotoxy(25,3);cprintf("J");
  gotoxy(1,5);cprintf("I");
  gotoxy(14,5);cprintf("T");
  gotoxy(18,5);cprintf("T");
  gotoxy(22,5);cprintf("T");
  gotoxy(1,25);cprintf("P");
  gotoxy(22,25);cprintf("...");
  getch();
  delayx=0;
  goto intro;
  }
else if(ver=='a' || ver=='A')
  {
  uninstback:
  clrscr();
  textcolor(txt);
  gotoxy(1,1);cprintf("Are you sure?  es or  o");
  textcolor(htxt);
  gotoxy(15,1);cprintf("y");
  gotoxy(22,1);cprintf("n");
  textcolor(0);
  gotoxy(1,25);cscanf("%c", &uninst);
  if(uninst=='Y' || uninst=='y')
  {
  clrscr();
  for(lo=28; lo<=53; lo++)
    {
    textcolor(8);
    gotoxy(lo,14);cprintf("€€");
    }


  for(lo=0, di=28; lo<=100; lo+=4, di++)
    {
    textcolor(15);
    gotoxy(28,12);cprintf("Uninstalling files...");
    gotoxy(28,13);cprintf("%d%", lo);
    gotoxy(di,14);cprintf("€€");
    delay(200);
    }
  clrscr();
  textcolor(8);
  gotoxy(1,1);cprintf("Uninstall complete.");
  remove("c:\\DSI.tic");
  remove("c:\\FULLTTP.enx");
  remove("c:\\FASTLO.pro");
  remove("c:\\theme1.col");
  remove("c:\\theme2.col");
  remove("c:\\theme3.col");
  remove("TICTAC.exe");
  }
  else if(uninst=='N' || uninst=='n')
    {
    delayx=0;
    goto intro;
    }
  else
    goto uninstback;
  }
else if(ver=='u' || ver=='U')
  {
  if(access("c:\\FULLTTP.enx", 0)==0)
    goto verback;
  clrscr();
  textcolor(8);
  gotoxy(1,1);cprintf(" nter secret code: ");
  textcolor(15);
  gotoxy(1,1);cprintf("E");
  gotoxy(20,1);cscanf("%s", code);
  if(strcoll(code, "Pro2002")==0)
    {
//    _creat("c:\\FULLTTP.enx", FA_HIDDEN);
    delayx=0;
    goto intro;
    }
  else
    {
    textcolor(4);
    gotoxy(1,3);cprintf("Sorry, incorrect code!");
    sleep(2);
    textcolor(7);
    gotoxy(1,5);cprintf("Go to practice game and beat master mode to crack the code.");
    textcolor(8);
    gotoxy(1,25);cprintf(" ress any key to exit");
    textcolor(15);
    gotoxy(1,25);cprintf("P");
    gotoxy(22,25);cprintf("...");
    getch();
    getch();
    delayx=0;
    goto intro;
    }
  }
else
  goto verback;
return 0;
}
