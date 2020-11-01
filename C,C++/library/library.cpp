/*******************************************************
*     MYCPLUS Sample Code - http://www.mycplus.com     *
*                                                     *
*   This code is made available as a service to our   *
*      visitors and is provided strictly for the      *
*               purpose of illustration.              *
*                                                     *
* Please direct all inquiries to saqib at mycplus.com *
*******************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<time.h>
#include<dos.h>

struct addstd
{
	char name[30];
	char roll[5];
	char stream[5];
	char sem[5];
	struct addstd *next;
	struct addstd *prior;
};

struct addstd *begin;
struct addstd *last;


struct addbook
{
	char book[30];
	char author[40];
	char tquantity[5];
	char code[10];
	struct addbook *next;
	struct addbook *prior;
};

struct addbook *start;
struct addbook *end;

struct addlib
{
	char acc[10];
	char edate[20];
	char sdate[20];
	struct addlib *next;
	struct addlib *prior;
};

struct addlib *initiate;
struct addlib *terminate;

struct common
{
	char name[50];
	char roll[5];
	char stream[5];
	char sem[5];
	char mem[10];
}common_list;


char mainmenu(void)
{
	char opt;
	int i;
	clrscr();
	textcolor(4);
	gotoxy(6,2);
	cprintf("S");
	textcolor(0);
	gotoxy(7,2);
	cprintf("tudent Info");
	textcolor(4);
	gotoxy(27,2);
	cprintf("B");
	textcolor(0);
	gotoxy(28,2);
	cprintf("ook Info");
	textcolor(4);
	gotoxy(45,2);
	cprintf("L");
	textcolor(0);
	gotoxy(46,2);
	cprintf("ibrary Info");
	textcolor(4);
	gotoxy(66,2);
	cprintf("E");
	textcolor(0);
	gotoxy(67,2);
	cprintf("xit");
	gotoxy(1,4);
	cprintf("%c",201);
	for(i=1;i<37;i++)
	{
		gotoxy(1+i,4);
		cprintf("%c",205);
	}
	textcolor(4);
	gotoxy(39,4);
	cprintf("A");
	textcolor(0);
	gotoxy(40,4);
	cprintf("bout");
	for(i=44;i<79;i++)
	{
		gotoxy(1+i,4);
		cprintf("%c",205);
	}
	gotoxy(80,4);
	cprintf("%c",187);
	gotoxy(1,5);
	for(i=3;i<21;i++)
	{
		gotoxy(1,2+i);
		cprintf("%c",186);
	}
	gotoxy(1,23);
	cprintf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,23);
		cprintf("%c",205);
	}
	gotoxy(80,23);
	cprintf("%c",188);
	gotoxy(80,2);
	for(i=3;i<21;i++)
	{
		gotoxy(80,2+i);
		cprintf("%c",186);
	}
	textcolor(4);
	gotoxy(2,24);
	cprintf("`S'");
	textcolor(0);
	gotoxy(6,24);
	cprintf("Student Info");
	textcolor(4);
	gotoxy(20,24);
	cprintf("`B'");
	textcolor(0);
	gotoxy(24,24);
	cprintf("Book Info");
	textcolor(4);
	gotoxy(35,24);
	cprintf("`L'");
	textcolor(0);
	gotoxy(39,24);
	cprintf("Library Info");
	textcolor(4);
	gotoxy(54,24);
	cprintf("`A'");
	textcolor(0);
	gotoxy(58,24);
	cprintf("About");
	textcolor(4);
	gotoxy(68,24);
	cprintf("`Esc'");
	textcolor(0);
	gotoxy(74,24);
	cprintf("Exit");
	gotoxy(28,10);
	cprintf("#  TECHNO INDIA LIBRARY  #");
	opt=getch();
	return opt;
}

void fine(void)
{
	int i;
	clrscr();
	textcolor(4);
	gotoxy(4,2);
	cprintf("I");
	textcolor(0);
	gotoxy(5,2);
	cprintf("nsert");
	textcolor(4);
	gotoxy(14,2);
	cprintf("D");
	textcolor(0);
	gotoxy(15,2);
	cprintf("elete");
	textcolor(4);
	gotoxy(24,2);
	cprintf("F");
	textcolor(0);
	gotoxy(25,2);
	cprintf("ind");
	textcolor(4);
	gotoxy(32,2);
	cprintf("D");
	textcolor(0);
	gotoxy(33,2);
	cprintf("isplay");
	textcolor(0);
	gotoxy(44,2);
	cprintf("Sa");
	textcolor(4);
	gotoxy(46,2);
	cprintf("v");
	textcolor(0);
	gotoxy(47,2);
	cprintf("e");
	textcolor(4);
	gotoxy(53,2);
	cprintf("A");
	textcolor(0);
	gotoxy(54,2);
	cprintf("ppend");
	textcolor(4);
	gotoxy(64,2);
	cprintf("L");
	textcolor(0);
	gotoxy(65,2);
	cprintf("oad");
	textcolor(4);
	gotoxy(72,2);
	cprintf("R");
	textcolor(0);
	gotoxy(73,2);
	cprintf("emove");
	gotoxy(1,4);
	cprintf("%c",201);
	for(i=1;i<3;i++)
	{
		gotoxy(1+i,4);
		cprintf("%c",205);
	}
	textcolor(4);
	gotoxy(5,4);
	cprintf("B");
	textcolor(0);
	gotoxy(6,4);
	cprintf("ack");
	for(i=1;i<26;i++)
	{
		gotoxy(9+i,4);
		cprintf("%c",205);
	}
	textcolor(0);
	cprintf(" WORKSPACE ");
	for(i=1;i<27;i++)
	{
		gotoxy(45+i,4);
		cprintf("%c",205);
	}
	textcolor(4);
	gotoxy(73,4);
	cprintf("H");
	textcolor(0);
	gotoxy(74,4);
	cprintf("elp");
	for(i=1;i<3;i++)
	{
		gotoxy(77+i,4);
		cprintf("%c",205);
	}
	gotoxy(80,4);
	cprintf("%c",187);
	gotoxy(1,5);
	for(i=3;i<21;i++)
	{
		gotoxy(1,2+i);
		cprintf("%c",186);
	}
	gotoxy(1,23);
	cprintf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,23);
		cprintf("%c",205);
	}
	gotoxy(80,23);
	cprintf("%c",188);
	gotoxy(80,2);
	for(i=3;i<21;i++)
	{
		gotoxy(80,2+i);
		cprintf("%c",186);
	}
	textcolor(4);
	gotoxy(2,24);
	cprintf("`Ins'");
	textcolor(0);
	gotoxy(8,24);
	cprintf("Insert");
	textcolor(4);
	gotoxy(16,24);
	cprintf("`Del'");
	textcolor(0);
	gotoxy(22,24);
	cprintf("Delete");
	textcolor(4);
	gotoxy(31,24);
	cprintf("`V'");
	textcolor(0);
	gotoxy(35,24);
	cprintf("Save");
	textcolor(4);
	gotoxy(42,24);
	cprintf("`H'");
	textcolor(0);
	gotoxy(46,24);
	cprintf("Help");
	textcolor(4);
	gotoxy(53,24);
	cprintf("`BkSp'");
	textcolor(0);
	gotoxy(61,24);
	cprintf("Remove");
	textcolor(4);
	gotoxy(69,24);
	cprintf("`Esc'");
	textcolor(0);
	gotoxy(75,24);
	cprintf("Back");
}

void libfine(void)
{
	int i;
	clrscr();
	textcolor(4);
	gotoxy(4,2);
	cprintf("R");
	textcolor(0);
	gotoxy(5,2);
	cprintf("egistration");
	textcolor(4);
	gotoxy(22,2);
	cprintf("E");
	textcolor(0);
	gotoxy(23,2);
	cprintf("ssue");
	textcolor(4);
	gotoxy(35,2);
	cprintf("S");
	textcolor(0);
	gotoxy(36,2);
	cprintf("ubmit");
	textcolor(4);
	gotoxy(49,2);
	cprintf("S");
	textcolor(0);
	gotoxy(50,2);
	cprintf("earch");
	textcolor(4);
	gotoxy(62,2);
	cprintf("U");
	textcolor(0);
	gotoxy(63,2);
	cprintf("n Registration");
	gotoxy(1,4);
	cprintf("%c",201);
	for(i=1;i<3;i++)
	{
		gotoxy(1+i,4);
		cprintf("%c",205);
	}
	textcolor(4);
	gotoxy(5,4);
	cprintf("B");
	textcolor(0);
	gotoxy(6,4);
	cprintf("ack");
	for(i=1;i<26;i++)
	{
		gotoxy(9+i,4);
		cprintf("%c",205);
	}
	textcolor(0);
	cprintf(" WORKSPACE ");
	for(i=1;i<27;i++)
	{
		gotoxy(45+i,4);
		cprintf("%c",205);
	}
	textcolor(4);
	gotoxy(73,4);
	cprintf("H");
	textcolor(0);
	gotoxy(74,4);
	cprintf("elp");
	for(i=1;i<3;i++)
	{
		gotoxy(77+i,4);
		cprintf("%c",205);
	}
	gotoxy(80,4);
	cprintf("%c",187);
	gotoxy(1,5);
	for(i=3;i<21;i++)
	{
		gotoxy(1,2+i);
		cprintf("%c",186);
	}
	gotoxy(1,23);
	cprintf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,23);
		cprintf("%c",205);
	}
	gotoxy(80,23);
	cprintf("%c",188);
	gotoxy(80,2);
	for(i=3;i<21;i++)
	{
		gotoxy(80,2+i);
		cprintf("%c",186);
	}
	textcolor(4);
	gotoxy(2,24);
	cprintf("`Ins'");
	textcolor(0);
	gotoxy(8,24);
	cprintf("Resistration");
	textcolor(4);
	gotoxy(22,24);
	cprintf("`E'");
	textcolor(0);
	gotoxy(26,24);
	cprintf("Essue");
	textcolor(4);
	gotoxy(33,24);
	cprintf("`Del'");
	textcolor(0);
	gotoxy(39,24);
	cprintf("Submit");
	textcolor(4);
	gotoxy(47,24);
	cprintf("`Tab'");
	textcolor(0);
	gotoxy(53,24);
	cprintf("Search");
	textcolor(4);
	gotoxy(61,24);
	cprintf("`U'");
	textcolor(0);
	gotoxy(65,24);
	cprintf("Unregistration");
}

char bookmenu(void)
{
	char res;
	fine();
	res=getch();
	return res;
}

char stdmenu(void)
{
	char res;
	fine();
	res=getch();
	return res;
}

char libmenu(void)
{
	char res;
	libfine();
	res=getch();
	return res;
}

void inputs(char *prompt,char *s,int count)
{
	char p[2001];

	do
	{
		printf(prompt);
		fgets(p,2000,stdin);
		if(strlen(p)>count)
		{
			clrscr();
			fine();
			gotoxy(30,13);
			printf("Database is too long.");
			getch();
		}
	}while(strlen(p)>count);

	p[strlen(p)-1]=0;
	strcpy(s,p);
}

struct addbook *bfind(char *author)
{
	struct addbook *info;

	info=start;
	while(info)
	{
		if(!strcmp(author,info->author))
			return info;
		info=info->next;
	}
	return NULL;
}

struct addstd *sfind(char *name)
{
	struct addstd *info;

	info=begin;
	while(info)
	{
		if(!strcmp(name,info->name))
			return info;
		info=info->next;
	}
	return NULL;
}

void bdls_store(struct addbook *i,struct addbook **start,struct addbook **end)
{
	struct addbook *old,*p;
	if(*end==NULL)
	{
		i->next=NULL;
		i->prior=NULL;
		*end=i;
		*start=i;
		return;
	}
	p=*start;
	old=NULL;
	while(p)
	{
		if(strcmp(p->author,i->author)<0)
		{
			old=p;
			p=p->next;
		}
		else
		{
			if(p->prior)
			{
				p->prior->next=i;
				i->next=p;
				i->prior=p->prior;
				p->prior=i;
				return;
			}
			i->next=p;
			i->prior=NULL;
			p->prior=i;
			*start=i;
			return;
		}
	}
	old->next=i;
	i->next=NULL;
	i->prior=old;
	*end=i;
}

void sdls_store(struct addstd *i,struct addstd **begin,struct addstd **last)
{
	struct addstd *old,*p;
	if(*last==NULL)
	{
		i->next=NULL;
		i->prior=NULL;
		*last=i;
		*begin=i;
		return;
	}
	p=*begin;
	old=NULL;
	while(p)
	{
		if(strcmp(p->name,i->name)<0)
		{
			old=p;
			p=p->next;
		}
		else
		{
			if(p->prior)
			{
				p->prior->next=i;
				i->next=p;
				i->prior=p->prior;
				p->prior=i;
				return;
			}
			i->next=p;
			i->prior=NULL;
			p->prior=i;
			*begin=i;
			return;
		}
	}
	old->next=i;
	i->next=NULL;
	i->prior=old;
	*last=i;
}

void benter(void)
{
	struct addbook *info;
	for(;;)
	{
		fine();
		info=(struct addbook *)malloc(sizeof(struct addbook));
		if(!info)
		{
			clrscr();
			fine();
			gotoxy(32,13);
			printf("Out of memory.");
			return;
		}
		gotoxy(4,6);
		inputs("Enter Book Name: ",info->book,30);
		if(!info->book[0])
			break;
		gotoxy(4,8);
		inputs("Enter Author Name: ",info->author,40);
		gotoxy(4,10);
		inputs("Enter Total Quantity: ",info->tquantity,5);
		gotoxy(4,12);
		inputs("Enter Code No.: ",info->code,10);

		bdls_store(info,&start,&end);
	}
}

void senter(void)
{
	struct addstd *info;
	for(;;)
	{
		fine();
		info=(struct addstd *)malloc(sizeof(struct addstd));
		if(!info)
		{
			clrscr();
			fine();
			gotoxy(32,13);
			printf("Out of memory.");
			return;
		}
		gotoxy(4,6);
		inputs("Enter name: ",info->name,30);
		if(!info->name[0])
			break;
		gotoxy(4,8);
		inputs("Enter Roll No.: ",info->roll,5);
		gotoxy(4,10);
		inputs("Enter Stream: ",info->stream,5);
		gotoxy(4,12);
		inputs("Enter Semestar: ",info->sem,5);

		sdls_store(info,&begin,&last);
	}
}

void bdel(struct addbook **start,struct addbook **end)
{
	struct addbook *info;
	char s[80];

	clrscr();
	fine();
	gotoxy(4,13);
	inputs("Enter author name to delete: ",s,30);
	info=bfind(s);
	clrscr();
	fine();
	gotoxy(27,13);
	printf("Searching data to delete....");
	delay(2000);
	if(info)
	{
		if(*start==info)
		{
			*start=info->next;
			if(*start)
				(*start)->prior=NULL;
			else
				*end=NULL;
		}
		else
		{
			info->prior->next=info->next;
			if(info!=*end)
				info->next->prior=info->prior;
			else
				*end=info->prior;
		}
		free(info);
		clrscr();
		fine();
		gotoxy(4,20);
		printf("Data Deleted Sucessfully.");
		gotoxy(4,10);
		printf("%15s %17s %12s %15s",info->book,info->author,info->tquantity,info->code);
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(32,13);
		printf("Data not found.");
		getch();
	}
}

void sdel(struct addstd **begin,struct addstd **last)
{
	struct addstd *info;
	char s[80];

	clrscr();
	fine();
	gotoxy(4,13);
	inputs("Enter name to delete: ",s,30);
	info=sfind(s);
	clrscr();
	fine();
	gotoxy(27,13);
	printf("Searching data to delete....");
	delay(2000);
	if(info)
	{
		if(*begin==info)
		{
			*begin=info->next;
			if(*begin)
				(*begin)->prior=NULL;
			else
				*last=NULL;
		}
		else
		{
			info->prior->next=info->next;
			if(info!=*last)
				info->next->prior=info->prior;
			else
				*last=info->prior;
		}
		free(info);
		clrscr();
		fine();
		gotoxy(4,20);
		printf("Data Deleted Sucessfully.");
		gotoxy(4,10);
		printf("%10s %10s %10s %10s",info->name,info->roll,info->stream,info->sem);
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(32,13);
		printf("Data not found.");
		getch();
	}
}

void sdisplay(struct addstd *info)
{
	if(info!=NULL)
		printf("%15s %17s %12s %15s",info->name,info->roll,info->stream,info->sem);
}

void bdisplay(struct addbook *info)
{
	if(info!=NULL)
		printf("%15s %17s %12s %15s",info->book,info->author,info->tquantity,info->code);
}

void blist(void)
{
	struct addbook *info;
	clrscr();
	gotoxy(4,3);
	puts(" ------------------------------------------------------------------------");
	textcolor(4);
	gotoxy(12,4);
	cprintf("Book Name            Author Name    Total Count      Code Numder\n");
	gotoxy(4,5);
	puts(" ------------------------------------------------------------------------");
	gotoxy(2,6);
	printf("     ");
	info=start;
	while(info!=end)
	{
		bdisplay(info);
		info=info->next;
		printf("\n\n\t   ");
	}
	bdisplay(end);
	puts("\n    ------------------------------------------------------------------------");
	getch();
}

void slist(void)
{
	struct addstd *info;
	clrscr();
	gotoxy(3,3);
	puts(" ------------------------------------------------------------------------");
	textcolor(4);
	gotoxy(12,4);
	cprintf("     Name              Roll Number       Stream       Semestar\n");
	gotoxy(3,5);
	puts(" ------------------------------------------------------------------------");
	gotoxy(2,6);
	printf("  ");
	info=begin;
	while(info!=last)
	{
		sdisplay(info);
		info=info->next;
		printf("\n\n\t ");
	}
	sdisplay(last);
	puts("\n    ------------------------------------------------------------------------");
	getch();
}

void find(void)
{
	char name[40];
	struct addbook *info;

	clrscr();
	fine();
	gotoxy(4,13);
	printf("Enter author name to find: ");
	gets(name);
	clrscr();
	fine();
	gotoxy(32,13);
	printf("Processing Data....");
	delay(2000);
	info=bfind(name);
	if(!info)
	{
		clrscr();
		fine();
		gotoxy(32,13);
		printf("Data not found.");
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(4,13);
		bdisplay(info);
		getch();
	}
}

void ssearch(void)
{
	char name[40];
	struct addstd *info;

	clrscr();
	fine();
	gotoxy(4,13);
	printf("Enter name to find: ");
	gets(name);
	clrscr();
	fine();
	gotoxy(32,13);
	printf("Processing Data....");
	delay(2000);
	info=sfind(name);
	if(!info)
	{
		clrscr();
		fine();
		gotoxy(32,13);
		printf("Data not found.");
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(4,13);
		sdisplay(info);
		getch();
	}
}

void bsave(void)
{
	struct addbook *info;
	FILE *fp;
	char filename[80];

	clrscr();
	fine();
	gotoxy(4,17);
	printf("Example: C:\\Library.txt");
	gotoxy(4,9);
	printf("Input file name: ");
	gets(filename);
	fp=fopen(filename,"wb");
	if(fp==NULL)
	{
		clrscr();
		fine();
		gotoxy(31,13);
		printf("Cannot open file.");
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(33,13);
		printf("Saving Records....");
		delay(2000);
		info=start;
		while(info)
		{
			fwrite(info,sizeof(struct addbook),1,fp);
			info=info->next;
		}
		clrscr();
		fine();
		gotoxy(28,13);
		printf("Records Saved Sucessfully");
		fclose(fp);
		getch();
	}
}

void ssave(void)
{
	struct addstd *info;
	FILE *fp;
	char filename[80];

	clrscr();
	fine();
	gotoxy(4,17);
	printf("Example: C:\\Library.txt");
	gotoxy(4,9);
	printf("Input file name: ");
	gets(filename);
	fp=fopen(filename,"wb");
	if(fp==NULL)
	{
		clrscr();
		fine();
		gotoxy(31,13);
		printf("Cannot open file.");
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(33,13);
		printf("Saving Records....");
		delay(2000);
		info=begin;
		while(info)
		{
			fwrite(info,sizeof(struct addstd),1,fp);
			info=info->next;
		}
		clrscr();
		fine();
		gotoxy(28,13);
		printf("Records Saved Sucessfully");
		fclose(fp);
		getch();
	}
}

void bload(void)
{
	struct addbook *info;
	FILE *fp;
	char filename[80];

	clrscr();
	fine();
	gotoxy(4,17);
	printf("Example: C:\\Library.txt");
	gotoxy(4,9);
	printf("Input file name: ");
	gets(filename);
	fp=fopen(filename,"rb");
	if(fp==NULL)
	{
		clrscr();
		fine();
		gotoxy(31,13);
		printf("Cannot open file.");
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(35,13);
		printf("Loading....");
		delay(2000);
		while(begin)
		{
			info=start->next;
			free(info);
			start=info;
		}
		start=end=NULL;

		while(!feof(fp))
		{
			info=(struct addbook *)malloc(sizeof(struct addbook));
			if(!info)
			{
				clrscr();
				fine();
				gotoxy(32,13);
				printf("Out of memory.");
				return;
			}
			if(1!=fread(info,sizeof(struct addbook),1,fp))
				break;
			 bdls_store(info,&start,&end);
		}
		clrscr();
		fine();
		gotoxy(28,13);
		printf("File Loaded Sucessfully");
		fclose(fp);
		getch();
	}
}

void sload(void)
{
	struct addstd *info;
	FILE *fp;
	char filename[80];

	clrscr();
	fine();
	gotoxy(4,17);
	printf("Example: C:\\Library.txt");
	gotoxy(4,9);
	printf("Input file name: ");
	gets(filename);
	fp=fopen(filename,"rb");
	if(fp==NULL)
	{
		clrscr();
		fine();
		gotoxy(31,13);
		printf("Cannot open file.");
		getch();
	}
	else
	{
		clrscr();
		fine();
		gotoxy(35,13);
		printf("Loading....");
		delay(2000);
		while(begin)
		{
			info=begin->next;
			free(info);
			begin=info;
		}
		begin=last=NULL;

		while(!feof(fp))
		{
			info=(struct addstd *)malloc(sizeof(struct addstd));
			if(!info)
			{
				clrscr();
				fine();
				gotoxy(32,13);
				printf("Out of memory.");
				return;
			}
			if(1!=fread(info,sizeof(struct addstd),1,fp))
				break;
			 sdls_store(info,&begin,&last);
		}
		clrscr();
		fine();
		gotoxy(28,13);
		printf("File Loaded Sucessfully");
		fclose(fp);
		getch();
	}
}

void bappend(void)
{
	struct addbook *info;
	FILE *fp;
	char filename[80];

	clrscr();
	fine();
	gotoxy(4,17);
	printf("Example: 0C:\\Library.txt");
	gotoxy(4,9);
	printf("Input file name to append into: ");
	gets(filename);
	fp=fopen(filename,"ab");
	if(fp==NULL)
	{
		clrscr();
		fine();
		gotoxy(31,13);
		printf("Cannot open file.");
		getch();
	}
	else
	{
		benter();
		clrscr();
		fine();
		gotoxy(33,13);
		printf("Saving Records....");
		delay(2000);
		info=start;
		while(info)
		{
			fwrite(info,sizeof(struct addbook),1,fp);
			info=info->next;
		}
		clrscr();
		fine();
		gotoxy(28,13);
		printf("Records Saved Sucessfully");
		fclose(fp);
		getch();
	}
}

void sappend(void)
{
	struct addstd *info;
	FILE *fp;
	char filename[80];

	clrscr();
	fine();
	gotoxy(4,17);
	printf("Example: C:\\Library.txt");
	gotoxy(4,9);
	printf("Input file name to append into: ");
	gets(filename);
	fp=fopen(filename,"ab");
	if(fp==NULL)
	{
		clrscr();
		fine();
		gotoxy(31,13);
		printf("Cannot open file.");
		getch();
	}
	else
	{
		senter();
		clrscr();
		fine();
		gotoxy(33,13);
		printf("Saving Records....");
		delay(2000);
		info=begin;
		while(info)
		{
			fwrite(info,sizeof(struct addstd),1,fp);
			info=info->next;
		}
		clrscr();
		fine();
		gotoxy(28,13);
		printf("Records Saved Sucessfully");
		fclose(fp);
		getch();
	}
}

struct addlib *libfind(char *acc)
{
	struct addlib *mid;

	mid=initiate;
	while(mid)
	{
		if(!strcmp(acc,mid->acc))
			return mid;
		mid=mid->next;
	}
	return NULL;
}

void libstore(struct addlib *i,struct addlib **initiate,struct addlib **terminate)
{
	struct addlib *old,*p;
	if(*terminate==NULL)
	{
		i->next=NULL;
		i->prior=NULL;
		*terminate=i;
		*initiate=i;
		return;
	}
	p=*initiate;
	old=NULL;
	while(p)
	{
		if(strcmp(p->edate,i->edate)<0)
		{
			old=p;
			p=p->next;
		}
		else
		{
			if(p->prior)
			{
				p->prior->next=i;
				i->next=p;
				i->prior=p->prior;
				p->prior=i;
				return;
			}
			i->next=p;
			i->prior=NULL;
			p->prior=i;
			*initiate=i;
			return;
		}
	}
	old->next=i;
	i->next=NULL;
	i->prior=old;
	*terminate=i;
}


void insert(void)
{
	struct addlib *mid;
	for(;;)
	{
		libfine();
		mid=(struct addlib *)malloc(sizeof(struct addlib));
		if(!mid)
		{
			clrscr();
			libfine();
			gotoxy(32,13);
			printf("Out of memory!");
			return;
		}
		gotoxy(4,7);
		inputs("Enter ACC No.: ",mid->acc,10);
		if(!mid->acc[0])
			break;
		gotoxy(4,9);
		inputs("Enter the Date of essue: ",mid->edate,20);
		gotoxy(4,11);
		inputs("Enter the Date of submit: ",mid->sdate,20);

		libstore(mid,&initiate,&terminate);
	}
}

void show(struct addlib *mid)
{
	if(mid!=NULL)
		printf("%15s %20s %20s",mid->acc,mid->edate,mid->sdate);
}

void resistration(void)
{
	struct addlib *mid;
	char choice;
	FILE *fp;

	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter Stream: ");
	gets(common_list.stream);
	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter Semestar: ");
	gets(common_list.sem);
	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter Roll No.: ");
	gets(common_list.roll);
	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter Name: ");
	gets(common_list.name);
	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter the Membership No: ");
	gets(common_list.mem);

	fp=fopen(common_list.mem,"wb");
	if(fp==NULL)
	{
		clrscr();
		libfine();
		gotoxy(31,13);
		printf("Membership No.is invalid!");
		getch();
	}
	else
	{
		clrscr();
		libfine();
		gotoxy(4,9);
		printf("A new member is registered.");
		gotoxy(4,19);
		printf("Membership No.: %s",common_list.mem);
		getch();
		clrscr();
		libfine();
		gotoxy(4,9);
		printf("Do you want to essue book under %s.",common_list.mem);
		gotoxy(4,19);
		printf("Press `Y' to confirm, anykey to cancel.");
		choice=getch();
		if(choice=='Y' || choice=='y')
			insert();
		clrscr();
		libfine();
		gotoxy(33,13);
		printf("Registering Account....");
		delay(2000);
		if(*common_list.name)
		{
			if(fwrite(&common_list,sizeof(struct common),1,fp)!=1)
			{
				clrscr();
				gotoxy(31,13);
				printf("An error occared while Resistering account!");
			}
		}
		mid=initiate;
		while(mid)
		{
			fwrite(mid,sizeof(struct addlib),1,fp);
			mid=mid->next;
		}
		clrscr();
		libfine();
		gotoxy(28,13);
		printf("Account Registered Sucessfully.");
		fclose(fp);
		getch();
	}
}

void save(void)
{
	struct addlib *mid;
	FILE *fp;
	char filename[80];

	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter the Membership No.: ");
	gets(filename);
	fp=fopen(filename,"wb");
	if(fp==NULL)
	{
		clrscr();
		libfine();
		gotoxy(31,13);
		printf("Membership No. does not exists!");
		getch();
	}
	else
	{
		clrscr();
		libfine();
		gotoxy(33,13);
		printf("Submitting Books....");
		delay(2000);
		if(*common_list.name)
		{
			if(fwrite(&common_list,sizeof(struct common),1,fp)!=1)
			{
				clrscr();
				gotoxy(31,13);
				printf("An error occared while Submitting books!");
			}
		}
		mid=initiate;
		while(mid)
		{
			fwrite(mid,sizeof(struct addlib),1,fp);
			mid=mid->next;
		}
		clrscr();
		libfine();
		gotoxy(28,13);
		printf("Book Submitted Sucessfully.");
		fclose(fp);
		getch();
	}
}

void submit(struct addlib **initiate,struct addlib **terminate)
{
	struct addlib *mid;
	char s[80],choice;
	FILE *fp;

	clrscr();
	libfine();
	gotoxy(4,13);
	inputs("Enter the ACC No.: ",s,30);
	mid=libfind(s);
	clrscr();
	libfine();
	gotoxy(27,13);
	printf("Searching the entered ACC No.....");
	delay(2000);
	if(mid)
	{
		if(*initiate==mid)
		{
			*initiate=mid->next;
			if(*initiate)
				(*initiate)->prior=NULL;
			else
				*terminate=NULL;
		}
		else
		{
			mid->prior->next=mid->next;
			if(mid!=*terminate)
				mid->next->prior=mid->prior;
			else
				*terminate=mid->prior;
		}
		free(mid);
		clrscr();
		libfine();
		gotoxy(4,20);
		printf("Press `Y' to Submit the above book, any key to cancel.");
		gotoxy(4,10);
		printf("%15s %20s %20s",mid->acc,mid->edate,mid->sdate);
		choice=getch();
		if(choice=='Y' || choice=='y')
			save();
	}
	else
	{
		clrscr();
		libfine();
		gotoxy(32,13);
		printf("ACC No is invalid!");
		getch();
	}
}


void search(void)
{
	struct addlib *mid;
	FILE *fp;

	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter the Membership No.: ");
	gets(common_list.mem);

	fp=fopen(common_list.mem,"rb");
	if(fp==NULL)
	{
		clrscr();
		libfine();
		gotoxy(31,13);
		printf("Membership No.does not exists!");
		getch();
	}
	else
	{
		clrscr();
		libfine();
		gotoxy(35,13);
		printf("Searching....");
		delay(2000);
		if(fread(&common_list,sizeof(struct common),1,fp)!=1)
		{
			clrscr();
			gotoxy(31,13);
			printf("An error occared while reading the file!");
		}
		clrscr();
		gotoxy(17,4);
		printf("Name: %s",common_list.name);
		gotoxy(17,6);
		printf("Roll No.: %s",common_list.roll);
		gotoxy(17,8);
		printf("Stream: %s",common_list.stream);
		gotoxy(17,10);
		printf("Semestar: %s",common_list.sem);
		gotoxy(17,12);
		printf("Membership No.: %s",common_list.mem);
		while(initiate)
		{
			mid=initiate->next;
			free(mid);
			initiate=mid;
		}
		initiate=terminate=NULL;

		while(!feof(fp))
		{
			mid=(struct addlib *)malloc(sizeof(struct addlib));
			if(!mid)
			{
				clrscr();
				libfine();
				gotoxy(32,13);
				printf("Out of memory!");
				return;
			}
			if(1!=fread(mid,sizeof(struct addlib),1,fp))
				break;
			libstore(mid,&initiate,&terminate);
		}
		gotoxy(12,14);
		puts(" -------------------------------------------------------");
		textcolor(4);
		gotoxy(17,15);
		cprintf("ACC No.       Date of Issue         Date of Submit\n");
		gotoxy(12,16);
		puts(" -------------------------------------------------------");
		gotoxy(2,17);
		printf("     ");
		mid=initiate;
		while(mid!=terminate)
		{
			show(mid);
			mid=mid->next;
			printf("\n\n      ");
		}
		show(terminate);
		puts("\n\t    -------------------------------------------------------");
		printf("\n\t       You can Essue maximum `4' books at a time.");
		fclose(fp);
		getch();
	}
}

void essue(void)
{
	struct addlib *mid;
	FILE *fp;
	char filename[80];

	clrscr();
	libfine();
	gotoxy(4,13);
	printf("Enter the Membership No.: ");
	gets(filename);
	fp=fopen(filename,"wb");
	if(fp==NULL)
	{
		clrscr();
		libfine();
		gotoxy(31,13);
		printf("Membership No. does not exists!");
		getch();
	}
	else
	{
		insert();
		clrscr();
		libfine();
		gotoxy(33,13);
		printf("Essuing Books....");
		delay(2000);
		if(*common_list.name)
		{
			if(fwrite(&common_list,sizeof(struct common),1,fp)!=1)
			{
				clrscr();
				gotoxy(31,13);
				printf("An error occared while Essuing books!");
			}
		}
		mid=initiate;
		while(mid)
		{
			fwrite(mid,sizeof(struct addlib),1,fp);
			mid=mid->next;
		}
		clrscr();
		libfine();
		gotoxy(28,13);
		printf("Books are Essued Sucessfully.");
		fclose(fp);
		getch();
	}
}

void bookhelp(void)
{
	int i;
	clrscr();
	gotoxy(1,1);
	textcolor(15);
	cprintf("%c",201);
	for(i=1;i<37;i++)
	{
		gotoxy(1+i,1);
		cprintf("%c",205);
	}
	textcolor(14);
	gotoxy(39,1);
	cprintf("HELP");
	textcolor(15);
	for(i=43;i<79;i++)
	{
		gotoxy(1+i,1);
		cprintf("%c",205);
	}
	gotoxy(80,1);
	cprintf("%c",187);
	gotoxy(1,5);
	for(i=1;i<23;i++)
	{
		gotoxy(1,1+i);
		cprintf("%c",186);
	}
	gotoxy(80,1);
	for(i=1;i<23;i++)
	{
		gotoxy(80,1+i);
		cprintf("%c",186);
	}
	gotoxy(3,2);
	textcolor(14);
	cprintf("INSERT : ");
	textcolor(15);
	cprintf("This function is used to insert the names of books with author name,");
	gotoxy(3,3);
	cprintf("total quantity & ACC No. in the database. To insert data press the `Insert'");
	gotoxy(3,4);
	cprintf("key through your keyboard. This function sorted all data alphabatically");
	gotoxy(3,5);
	cprintf("before saving.");
	gotoxy(3,7);
	textcolor(14);
	cprintf("DELETE : ");
	textcolor(15);
	cprintf("This function is used to delete the data. To delete data press");
	gotoxy(3,8);
	cprintf("`Delete' key through your keyboard.");
	gotoxy(3,10);
	textcolor(14);
	cprintf("FIND : ");
	textcolor(15);
	cprintf("This function is used to search the data by author name. To find data");
	gotoxy(3,11);
	cprintf("press `F' key through your keyboard.");
	gotoxy(3,13);
	textcolor(14);
	cprintf("DISPLAY : ");
	textcolor(15);
	cprintf("This function is used to display all data after loading a file. To");
	gotoxy(3,14);
	cprintf("show or display all data press `D' key through your keyboard.");
	gotoxy(3,16);
	textcolor(14);
	cprintf("SAVE : ");
	textcolor(15);
	cprintf("This function is used to save all the data in a specified file in a");
	gotoxy(3,17);
	cprintf("specified drive. To save all data press `V' key through your keyboard.");
	gotoxy(3,19);
	textcolor(14);
	cprintf("APPEND : ");
	textcolor(15);
	cprintf("This function is used to append new data in a existing file. Press");
	gotoxy(3,20);
	cprintf("`A' key through your keyboard to append new data.");
	gotoxy(3,22);
	textcolor(14);
	cprintf("REMOVE : ");
	textcolor(15);
	cprintf("This function is used to remove a file from a specified drive. Press");
	gotoxy(3,23);
	cprintf("Back Space to remove a file through your keyboard.");
	gotoxy(1,24);
	cprintf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,24);
		cprintf("%c",205);
	}
	gotoxy(80,27);
	cprintf("%c",188);
	getch();
}

void book(void)
{
	char response=' ';
	char filename[80];
	clrscr();
	_setcursortype(0);
	start=end=NULL;
	do
	{
		textbackground(15);
		response=stdmenu();
		if(response=='R' || response=='r')
			benter();
		if(response=='S' || response=='s')
			bdel(&start,&end);
		if(response=='L' || response=='l')
			bload();
		if(response=='D' || response=='d')
			blist();
		if(response=='V' || response=='v')
			bsave();
		if(response=='F' || response=='f')
			find();
		if(response=='A' || response=='a')
			bappend();
		if(response=='\b')
		{
			clrscr();
			fine();
			gotoxy(4,13);
			printf("Input file name to remove: ");
			gets(filename);
			clrscr();
			fine();
			gotoxy(31,13);
			printf("Please wait...");
			delay(2000);
			if (remove(filename) == 0)
			{
				clrscr();
				fine();
				gotoxy(25,13);
				printf("%s removed sucessfully.",filename);
				getch();
			}
			else
			{
				perror("remove");
				clrscr();
				fine();
				gotoxy(29,13);
				printf("There is no such file.");
				getch();
			}
		}
		if(response=='H' || response=='h')
		{
			textbackground(3);
			bookhelp();
		}
		if(response==27)
			break;
	}while(response>'A' || response<'Z');
}

void stdhelp(void)
{
	int i;
	clrscr();
	gotoxy(1,1);
	textcolor(15);
	cprintf("%c",201);
	for(i=1;i<37;i++)
	{
		gotoxy(1+i,1);
		cprintf("%c",205);
	}
	textcolor(14);
	gotoxy(39,1);
	cprintf("HELP");
	textcolor(15);
	for(i=43;i<79;i++)
	{
		gotoxy(1+i,1);
		cprintf("%c",205);
	}
	gotoxy(80,1);
	cprintf("%c",187);
	gotoxy(1,5);
	for(i=1;i<23;i++)
	{
		gotoxy(1,1+i);
		cprintf("%c",186);
	}
	gotoxy(80,1);
	for(i=1;i<23;i++)
	{
		gotoxy(80,1+i);
		cprintf("%c",186);
	}
	gotoxy(3,2);
	textcolor(14);
	cprintf("INSERT : ");
	textcolor(15);
	cprintf("This function is used to insert the names of students with roll");
	gotoxy(3,3);
	cprintf("numbers stream & semestar in the database. To insert data press the `Insert'");
	gotoxy(3,4);
	cprintf("key through your keyboard. This function sorted all data alphabatically");
	gotoxy(3,5);
	cprintf("before saving.");
	gotoxy(3,7);
	textcolor(14);
	cprintf("DELETE : ");
	textcolor(15);
	cprintf("This function is used to delete the data. To delete data press");
	gotoxy(3,8);
	cprintf("`Delete' key through your keyboard.");
	gotoxy(3,10);
	textcolor(14);
	cprintf("FIND : ");
	textcolor(15);
	cprintf("This function is used to search the data by name. To find data press");
	gotoxy(3,11);
	cprintf("`F' key through your keyboard.");
	gotoxy(3,13);
	textcolor(14);
	cprintf("DISPLAY : ");
	textcolor(15);
	cprintf("This function is used to display all data after loading a file. To");
	gotoxy(3,14);
	cprintf("show or display all data press `D' key through your keyboard.");
	gotoxy(3,16);
	textcolor(14);
	cprintf("SAVE : ");
	textcolor(15);
	cprintf("This function is used to save all the data in a specified file in a");
	gotoxy(3,17);
	cprintf("specified drive. To save all data press `V' key through your keyboard.");
	gotoxy(3,19);
	textcolor(14);
	cprintf("APPEND : ");
	textcolor(15);
	cprintf("This function is used to append new data in a existing file. Press");
	gotoxy(3,20);
	cprintf("`A' key through your keyboard to append new data.");
	gotoxy(3,22);
	textcolor(14);
	cprintf("REMOVE : ");
	textcolor(15);
	cprintf("This function is used to remove a file from a specified drive. Press");
	gotoxy(3,23);
	cprintf("Back Space to remove a file through your keyboard.");
	gotoxy(1,24);
	cprintf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,24);
		cprintf("%c",205);
	}
	gotoxy(80,27);
	cprintf("%c",188);
	getch();
}

void student(void)
{
	char response;
	char filename[80];
	clrscr();
	_setcursortype(0);
	begin=last=NULL;
	do
	{
		textbackground(15);
		response=stdmenu();
		if(response=='R' || response=='r')
			senter();
		if(response=='S' || response=='s')
			sdel(&begin,&last);
		if(response=='L' || response=='l')
			sload();
		if(response=='D' || response=='d')
			slist();
		if(response=='V' || response=='v')
			ssave();
		if(response=='F' || response=='f')
			ssearch();
		if(response=='A' || response=='a')
			sappend();
		if(response=='\b')
		{
			clrscr();
			fine();
			gotoxy(4,13);
			printf("Input file name to remove: ");
			gets(filename);
			clrscr();
			fine();
			gotoxy(31,13);
			printf("Please wait...");
			delay(2000);
			if (remove(filename) == 0)
			{
				clrscr();
				fine();
				gotoxy(25,13);
				printf("%s removed sucessfully.",filename);
				getch();
			}
			else
			{
				perror("remove");
				clrscr();
				fine();
				gotoxy(29,13);
				printf("There is no such file.");
				getch();
			}
		}
		if(response=='H' || response=='h')
		{
			textbackground(3);
			stdhelp();
		}
		if(response==27)
			break;
	}while(response>'A' || response<'Z');
}

void libhelp(void)
{
	int i;
	clrscr();
	gotoxy(1,1);
	textcolor(15);
	cprintf("%c",201);
	for(i=1;i<37;i++)
	{
		gotoxy(1+i,1);
		cprintf("%c",205);
	}
	textcolor(14);
	gotoxy(39,1);
	cprintf("HELP");
	textcolor(15);
	for(i=43;i<79;i++)
	{
		gotoxy(1+i,1);
		cprintf("%c",205);
	}
	gotoxy(80,1);
	cprintf("%c",187);
	gotoxy(1,5);
	for(i=1;i<23;i++)
	{
		gotoxy(1,1+i);
		cprintf("%c",186);
	}
	gotoxy(80,1);
	for(i=1;i<23;i++)
	{
		gotoxy(80,1+i);
		cprintf("%c",186);
	}
	gotoxy(3,3);
	textcolor(14);
	cprintf("REGISTRATION : ");
	textcolor(15);
	cprintf("This function is used to register a new account in the library");
	gotoxy(3,4);
	cprintf("following the student's name, class roll no., stream, semestar & the library");
	gotoxy(3,5);
	cprintf("registration number. To register a new account press the `Insert' key through");
	gotoxy(3,6);
	cprintf("your keyboard.");
	gotoxy(3,8);
	textcolor(14);
	cprintf("ESSUE : ");
	textcolor(15);
	cprintf("This function is used to essue books under a registered account in");
	gotoxy(3,9);
	cprintf("the library. To essue books press `E' key through your keyboard. One student");
	gotoxy(3,10);
	cprintf("can essue maximum `4' books at a time.");
	gotoxy(3,12);
	textcolor(14);
	cprintf("SUBMIT : ");
	textcolor(15);
	cprintf("This function is used to submit books from students. To submit books");
	gotoxy(3,13);
	cprintf("press `Delete' key through your keyboard.");
	gotoxy(3,15);
	textcolor(14);
	cprintf("SEARCH : ");
	textcolor(15);
	cprintf("This function is used to search an account details following the");
	gotoxy(3,16);
	cprintf("the Membership number. To search an account press `Tab' key through your");
	gotoxy(3,17);
	cprintf("keyboard.");
	gotoxy(3,19);
	textcolor(14);
	cprintf("Un Registration : ");
	textcolor(15);
	cprintf("This function is used to close or unregister an account ");
	gotoxy(3,20);
	cprintf("following the Membership number. To unregister an account press `U' key");
	gotoxy(3,21);
	cprintf("through your keyboard.");
	gotoxy(1,24);
	cprintf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,24);
		cprintf("%c",205);
	}
	gotoxy(80,27);
	cprintf("%c",188);
	getch();
}

void library(void)
{
	char response=' ';
	char filename[80];
	clrscr();
	_setcursortype(0);

	do
	{
		textbackground(15);
		response=libmenu();
		if(response=='R' || response=='r')
			resistration();
		if(response=='E' || response=='e')
			essue();
		if(response=='S' || response=='s')
			submit(&initiate,&terminate);
		if(response=='\t' || response=='\t')
			search();
		if(response=='U' || response=='u')
		{
			clrscr();
			libfine();
			gotoxy(4,13);
			printf("Input the Membership No.: ");
			gets(filename);
			clrscr();
			libfine();
			gotoxy(31,13);
			printf("Please wait...");
			delay(2000);
			if (remove(filename) == 0)
			{
				clrscr();
				libfine();
				gotoxy(25,13);
				printf("%s Unresistered sucessfully.",filename);
				getch();
			}
			else
			{
				perror("remove");
				clrscr();
				libfine();
				gotoxy(29,13);
				printf("Membership No. does not exists!");
				getch();
			}
		}
		if(response=='H' || response=='h')
		{
			textbackground(3);
			libhelp();
		}
		if(response==27)
			break;
	}while(response>'A' || response<'Z');
}

void chcolor(void)
{
	char c;
	int i;
	gotoxy(4,6);
	printf("Press the number key to change color.");
	gotoxy(4,8);
	printf();

}

int main(void)
{
	char choice=' ';
	clrscr();
	_setcursortype(0);

	do
	{
		textbackground(15);
		choice=mainmenu();
		if(choice=='S' || choice=='s')
			student();
		if(choice=='B' || choice=='b')
			book();
		if(choice=='L' || choice=='l')
			library();
		if(choice=='A' || choice=='a')
		{
			clrscr();
			textcolor(1);
			gotoxy(28,8);
			cprintf("GREAT LIBRERIAN  v 1.01");
			gotoxy(20,14);
			cprintf("This Program is coded by `ABHRAJIT KUNDU'.");
			gotoxy(24,16);
			cprintf("  Department of IT, Techno India");
			gotoxy(24,18);
			cprintf("Email: abhrajit06it@rediffmail.com");
			gotoxy(27,20);
			cprintf("Contact(Mob.): 9434568272");
			getch();
		}
		if(choice==27)
		{
			clrscr();
			gotoxy(36,13);
			textcolor(4);
			cprintf("Exiting....");
			delay(2000);
			exit(0);
			break;
		}
	} while(choice>'A' || choice<'Z');
	return 0;
}


