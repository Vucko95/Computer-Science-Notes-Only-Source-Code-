#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_EMPLOYEE 10

int main(int argc, char *argv[]){
	int Salary[NUM_EMPLOYEE], lCount=0,gCount=0,i=0;
	printf("Enter employee salary (Max 10)\n ");
	for (i=0; i<NUM_EMPLOYEE; i++){
		printf("\nEnter employee salary: %d - ",i+1);
		scanf("%d",&Salary[i]);
	}
	
	for(i=0; i<NUM_EMPLOYEE; i++){
		if(Salary[i]<3000)
			lCount++;
		else
			gCount++;
	}
	
	printf("\nThere are {%d} employee with salary more than 3000\n",gCount);
	printf("There are {%d} employee with salary less than 3000\n",lCount);
	printf("Press ENTER to continue...\n");
	getchar();
	return 0;
}
