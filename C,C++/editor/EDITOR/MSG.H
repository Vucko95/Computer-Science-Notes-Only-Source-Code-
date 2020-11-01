void about(void)
{
int a,b,c,d;
textbackground(BLUE);
textcolor(WHITE);
gotoxy(20,10);
cprintf("%c",213);
for(a=0;a<33;++a)
cprintf("%c",205);
cprintf("%c",184);
gotoxy(20,11);
cprintf("%c",179);
cprintf(" A PROJECT BY: Saqib, Rizwan, Zia",2);
textcolor(GREEN);
cprintf("%c",179);
gotoxy(20,12);
cprintf("%c",179);
cprintf("                                 %c",179);
gotoxy(20,13);
cprintf("%c   press any key to continue     %c",179,179);
gotoxy(20,14);
cprintf("%c",212);
for(c=0;c<33;++c)
cprintf("%c",205);
cprintf("%c",190);
for(b=0;b<4;++b)
{
gotoxy(55,11+b);
textcolor(WHITE);
cprintf("%c",219);
}
textbackground(BLUE);
for(d=0;d<35;++d)
{
gotoxy(21+d,15);
cprintf("%c",223);
}
//getch();
}
