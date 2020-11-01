#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_EMPLOYEE 10

int main(int argc, char *argv[])
{
 	//initialise Salary of each employee
    int Salary[NUM_EMPLOYEE][2]={
		{2300,0},
		{3400,0},
		{3200,0},
		{1200,0},
		{3450,0},
		{3800,0},
		{3900,0},
		{2680,0},
		{3340,0},
		{3000,0}
    };
	int lCount=0,gCount=0,i=0;
    for(i=0; i<NUM_EMPLOYEE; i++){
		Salary[i][1] = ((Salary[i][0]*20)/100);	    		 
	}
    printf("Initial Salary + Increment = Total Salary\n");
    for (i=0; i<NUM_EMPLOYEE; i++){
        printf("%d\t\t%d\t\t%d\n",Salary[i][0],Salary[i][1],Salary[i][0]+Salary[i][1]);
    }
 
    printf("Press ENTER to continue...\n");
    getchar();
    return 0;
}
