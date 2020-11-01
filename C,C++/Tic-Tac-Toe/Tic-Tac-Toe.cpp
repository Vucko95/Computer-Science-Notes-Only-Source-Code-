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
//E-Mail: usmanshahzada@hotmail.com 
//Description: It`s Tic-Tac-Toe 

# include<stdio.h> 
# include<iostream.h> 
# include<conio.h> 
# include <process.h> 
char player1[100],player2[100]; 
enum whoplays {human,machine}; 
enum cell {empty,full}; 
enum boolean{false,true}; 
int deep = 0; 
class position 
{ 
private: 
cell mcell[9]; 
cell hcell[9]; 
whoplays player ; 
public: 
position(); 
boolean iswin(); 
boolean islegal(int); 
void makemove(int); 
void setplayer (whoplays); 
static void initdisplay(); 
void display(); 
int evaluate(int&); 
}; 
position::position() 
{for (int j=0;j<9;j++) 
mcell[j]=hcell[j]=empty; 
} 
boolean position::iswin() 
{ 
cell *ptr; 
if (player==human) 
ptr=hcell; 
else 
ptr=mcell; 
if((ptr[0]&&ptr[1]&&ptr[2])||(ptr[3]&&ptr[4]&&ptr[5])||(ptr[6]&&ptr[7]&&ptr[8])||(ptr[0]&&ptr[3]&&ptr[6])||(ptr[1]&&ptr[4]&&ptr[7])||(ptr[2]&&ptr[5]&&ptr[8])||(ptr[0]&&ptr[4]&&ptr[8])||(ptr[2]&&ptr[4]&&ptr[6])) 
return (true); 
else 
return (false); 
} 
boolean position::islegal(int move) 
{ 
if(move>=0 &&move<=8&&mcell[move]==empty&&hcell[move]==empty) 
return (true); 
else 
return (false); 
} 
void position::makemove(int move) 
{ 
if(player==human) 
hcell[move]=full; 
else 
mcell[move]=full; 
} 
void position::setplayer(whoplays p) 
{player =p; 
} 
void position::initdisplay() 
{const unsigned char block= '\xB2'; 
void insert(unsigned char,int,int); 
int row,col; 
clrscr(); 
for(row=0;row<11;row++) 
{insert (block ,5,row); 
insert (block ,11,row); 
} 
for (col=0;col<17;col++) 
{insert (block,col,3); 
insert (block,col,7); 
} 
for (int j=0; j<9;j++) 
insert ((char)(j+'0'),(j%3)*6+4,(j/3)*4) ; 
} 
void position::display() 
{ 
void insert (unsigned char,int,int); 
int row,col; 
for (int j=0;j<9;j++) 
{if (hcell[j]) 
insert('X',(j%3)*6+2,(j/3)*4+1); 
else if( mcell[j]) 
insert('0',(j%3)*6+2,(j/3)*4+1); 
else 
insert(' ',(j%3)*6+2,(j/3)*4+1); 
} 
gotoxy(1,23); 
} 
void insert(unsigned char ch,int col,int row) 
{gotoxy(col+50+1,row+5+1); 
putch(ch); 
} 
void main() 
{clrscr(); 
cout<<"Player1 enter your name:"; 
gets(player1); 
cout<<"Player2 enter your name:"; 
gets(player2); 
int move; 
int sc; 
int movecount=0; 
position current; 
int cursrow=0; 
position::initdisplay(); 
while(1) 
{current.setplayer(human); 
current.display(); 
gotoxy(1,++cursrow); 
cout<<player1<<" make your move"; 
cin>>move; 
if (!current.islegal(move)) 
{ 
gotoxy(1,++cursrow); 
cout<<"illegal move"; 
continue; 
} 
current.makemove(move); 
current.display(); 
if ( current.iswin()) 
{ 
gotoxy(1,++cursrow); 
cout<<player1<<" you win"; 
getch(); 
exit(0); 
} 
if (++movecount==9) 
{ 
gotoxy(1,++cursrow); 
cout<<"its a draw"; 
getch(); 
exit(0); 
} 
current.setplayer(machine); 
current.display(); 
gotoxy(1,++cursrow); 
cout<<player2<<" make your move"; 
cin>>move; 
if (!current.islegal(move)) 
{ 
gotoxy(1,++cursrow); 
cout<<"illegal move"; 
continue; 
} 
current.makemove(move); 
current.display(); 
if ( current.iswin()) 
{ 
gotoxy(1,++cursrow); 
cout<<player2<<" wins win"; 
getch(); 
exit(0); 
} 
if (++movecount==9) 
{ 
gotoxy(1,++cursrow); 
cout<<"its a draw"; 
getch(); 
exit(0); 
} 
}} 