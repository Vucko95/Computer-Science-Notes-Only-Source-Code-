#include <cstdlib>
#include <iostream>

#define NUM_EMPLOYEE 10

using namespace std;

int main(int argc, char *argv[]){
	int Salary[NUM_EMPLOYEE], lCount=0,gCount=0,i=0;
	cout << "Enter employee salary (Max 10) " << endl;
	for (i=0; i<NUM_EMPLOYEE; i++){
		cout << "Enter employee salary: - " << i+1 << endl;
		cin >> Salary[i];
	}
	
	for(i=0; i<NUM_EMPLOYEE; i++){
		if(Salary[i]<3000)
			lCount++;
		else
			gCount++;
	}
	
	cout << "There are " << gCount << " employee with salary more than 3000" << endl
	<< "There are " << lCount << " employee with salary less than 3000" << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
