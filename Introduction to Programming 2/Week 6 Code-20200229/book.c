#include <stdio.h>

struct Book {
	char name[200];
	char authors[5][100];
	int year;
	char publisher[100];
	int pages;
	char isbn[13];
	char genre[50];
};
	
int main() {
   struct Book myBook;
   long size = sizeof(myBook.name) + sizeof(myBook.authors) + sizeof(myBook.year) + sizeof(myBook.publisher) + sizeof(myBook.pages) + sizeof(myBook.isbn) + sizeof(myBook.genre);
   printf( "I calculate the myBook struct to be %lu bytes\n", size);
   printf( "A Book is actually %lu bytes\n", sizeof(struct Book) );
}


