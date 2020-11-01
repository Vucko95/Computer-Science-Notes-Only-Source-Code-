/*******************************************************
*     MYCPLUS Sample Code - http://www.mycplus.com     *
*                                                     *
*   This code is made available as a service to our   *
*      visitors and is provided strictly for the      *
*               purpose of illustration.              *
*                                                     *
* Please direct all inquiries to saqib at mycplus.com *
*******************************************************/



/************************************************************************/
/*		BASIC STACK OPERATIONS								*/
/************************************************************************/

#include <stdio.h>
#include<process.h>
#include <dos.h>
#include<conio.h>
#include<stdio.h>

#define SIZE 5

static struct stack{
							int top;
							int items[SIZE];
						 }s1;

void push(struct stack *,int);
int pop(struct stack*);
int stacktop(struct stack*);
int empty(struct stack*);
int search(struct stack *,int);
void insert(struct stack *,int,int);
void replace(struct stack *,int,int);
void del(struct stack *,int);
void printline(void);

void main()
{
	char c;
	int i,temp;
	s1.top=-1;
	mark:
	clrscr();
	gotoxy(28,2);
	printf("BASIC STACK OPERATIONS");
	gotoxy(34,4);	printf("(1)  Push");
	gotoxy(34,6);	printf("(2)  Pop");
	gotoxy(34,8);	printf("(3)  Search");
	gotoxy(34,10);	printf("(4)  Insert");
	gotoxy(34,12);	printf("(5)  Replace");
	gotoxy(34,14); printf("(6)  Delete\n\n");
	gotoxy(0,18);  printline();
	c=getch();
	switch (c)
	{
		case '1':  	printf("\nWhat element do you wish to push?");
						scanf("%d",&temp);
						push(&s1,temp);
						break;
		case '2':   pop(&s1);
						break;
		case '3':   printf("\nEnter the element you wish to search?");
						scanf("%d",&temp);
						printf("\nThe element is at index %d\n",search(&s1,temp));
						break;
		case '4':	printf("\nEnter the POSTION and ELEMENT you wish to insert?");
						scanf("%d %d",&i,&temp);
						insert(&s1,i,temp);
						break;
		case '5':	printf("\nEnter the POSTION and ELEMENT you wish to replace?");
						scanf("%d %d",&i,&temp);
						replace(&s1,i,temp);
						break;
		case '6':	printf("\nEnter the POSTION you wish to delete from stack?");
						scanf("%d",&temp);
						del(&s1,temp);
						break;
		default : 	printf("\nInvalid entry! Try again!");
						break;
	}
  for (i=s1.top;i>=0;i--)
	  printf("\nThe element at position (%d) is %4d",i,s1.items[i]);
  printf("\n\nDo you wish to continue?");
  c=getch();
  if (c=='y')
	  goto mark;
}

void push(struct stack *sx,int x)
{
	if (sx->top==SIZE-1)
	{
		printf("\n\tSTACT OVERFLOW\n");
		getch();
		exit(1);
	}
	sx->items[++sx->top]=x;
}

int pop(struct stack *sx)
{
	if (empty(sx))
	{
		printf("\n\t STACK UNDERFLOW\n");
		getch();
		exit(1);
	}
	return(sx->items[sx->top--]);
}

int stacktop(struct stack *sx)
{
	return(sx->items[sx->top]);
}

int empty(struct stack *sx)
{
	return((sx->top==-1));
}

int search(struct stack *sx,int n)
{
	int arr[20];
	int i=0,j,result=-1;
	for (j=sx->top;!(empty(sx));j--)
	{
		if (n==stacktop(sx))
		{
			result=sx->top;
			break;
		}
		arr[i++]=pop(sx);
	}
	for (j=i-1;j>=0;j--)
		push(sx,arr[j]);
	return(result);
}

void insert(struct stack *sx,int pos,int ele)
{
	int arr[20];
	int i=0,j;
	for (j=sx->top;j>=pos;j--)
		arr[i++]=pop(sx);
	push(sx,ele);
	for (j=i-1;j>=0;j--)
		push(sx,arr[j]);
}

void replace(struct stack *sx,int pos,int ele)
{
	int arr[20];
	int i=0,j;
	for (j=sx->top;j>=pos;j--)
		arr[i++]=pop(sx);
	push(sx,ele);
	for (j=i-2;j>=0;j--)
		push(sx,arr[j]);
}

void del(struct stack *sx,int pos)
{
	int arr[20];
	int i=0,j;
	for (j=sx->top;j>pos;j--)
		arr[i++]=pop(sx);
	pop(sx);
	for (j=i-1;j>=0;j--)
		push(sx,arr[j]);
}

void printline(void)
{
	int i;
	for (i=0;i<40;i++)
		printf("оп");
}

