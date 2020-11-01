/* Iterative A000904 */
//Calculates the sequence A000904 https://oeis.org/A000904
//output should be (depending on n): 0, 3, 13, 83, 592, 4821, 43979, 444613, 4934720, 59661255, 780531033, 10987095719, 165586966816, 2660378564777, 45392022568023, 819716784789193, 15620010933562688, 313219935456042955, 6593238655510464741

//////output n = 1: 0
//////output n = 3: 13
//////output n = 10: 0, 3, 13, 83, 592, 4821, 43979, 444613, 4934720, 59661255
//////note no final commma in output! 
//////note single-line output!

#include<stdio.h>

//structure to hold the three 'previous' values
struct previous{
	int first;
	int second;
	int third;
} p;

int main(){
	//current is current calculation. s is number of terms from user. c is a counter.
	int current, s, c;
	//set initial values from https://oeis.org/A000904: A(1) = 0, A(2) = 3, A(3) = 13
	//Note below. We aren't using pointers so structure members are accessed with . not ->
	p.first = 0; p.second = 3; p.third = 13;
	// if A(current) is the "current" calculation (A(n)), third is immediately previous A(n-1),
	//second is two previous A(n-2), first is three back A(n-3)
    
	printf("Enter the number of terms\n");
	scanf("%d",&s);
 
	printf("First %d terms of A000904 sequence are :\n",s);
 
	for ( c = 1 ; c <= s ; c++ ){
		if ( c == 1 ){current = p.first;}
		else if ( c == 2 ){current = p.second;}
		else if ( c == 3 ){current = p.third;}
		else{
			//from https://oeis.org/A000904: a(n) = (n+1)*a(n-1) + (n+2)*a(n-2) + a(n-3)
			//calculate A(current)
			current = (c+1)*p.third + (c+2)*p.second + p.first;
			//update the 'previous' values
			p.first = p.second;
			p.second = p.third;
			p.third = current;
		}
		if( c < s )
			printf("%d, ",current);
		else
			printf("%d\n",current);
	}
	return 0;
}
