//lab week4 question 2 model solution
//student name
//student number

#include <stdio.h>

void func_1(int *px);
void func_2(int a);
int func_3(int b);

int main () {
	printf ("See the source code for an explanation of the output!\n");
	int x = 100;
	printf ("x is %d \n", x);
	func_1(&x);//this is the solution!
	printf ("x is %d \n", x);
	//func_2(x);
	//printf ("x is %d \n", x);
	//x = func_3(x);//this will change the value of x, because func_3 returns an integer, but that is not the point!
	//printf ("x is %d \n", x);
	printf ("see the commented lines in the source code for more!");
}

void func_1(int *px){ //this is the solution!
	*px = 200;
}

//void func_2(int a){ //this will not change the value of x (which in this function we call a) outsisde the function func_2
//	a = 400;
//}

//int func_3(int b){
//	b = 600;
//   return b;	
//}
