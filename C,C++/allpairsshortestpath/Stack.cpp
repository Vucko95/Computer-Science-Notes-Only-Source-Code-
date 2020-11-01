/* Project: C++ Assignment 3
 * Purpose: Definitions for Stack Class
 * File:    Stack.cpp
 * Author:  COAD021
 * Date:    02APR2001
 */

#include <stdlib.h>
#include <string.h>
#include "Stack.h"

//  Constructors and Destructors
//==========================================================
Stack::Stack(int Size) {

   size=Size;
   Quantity=INCREMENT;
   Next=0;
   Storage=(unsigned char *)calloc(INCREMENT,size);
}

Stack::~Stack() {
	if(Storage)free(Storage);
   
}

//
// Private Class Functions
//=========================================================

bool Stack::Inflate(int Increase) {
	void *v=realloc(Storage,(Quantity+Increase)*size);
   if (!v) return false;

   Storage=(unsigned char *)v;
   
	Quantity += Increase;
	return true;
}

bool Stack::Push(void *Data) {
	if(Next >= Quantity) {
	   if (!Inflate(INCREMENT)) return false;
        }
	memcpy(&(Storage[Next*size]),Data,size);
	Next++;
	return true;
}

void *Stack::Read(int index) {
   return(&(Storage[index*size]));
}

void *Stack::Pop() {
	--Next;
	return(&(Storage[Next*size]));
}	

bool Stack::IsEmpty()
{
	if (!Next)return true;
	return false;
}