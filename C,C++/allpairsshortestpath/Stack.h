/* Project: C++ Assignment 3
 * Purpose: Header for Stack Class
 * File:    Stack.h
 * Author:  COAD021
 * Date:    02APR2001
 */

#ifndef STACK_H
#define STACK_H

class Stack {
   protected:
      enum {INCREMENT=16};
      int size;
      int Quantity;
      int Next;
      unsigned char *Storage;
      bool Inflate(int Increase);
   public:
      Stack(int Size);
      ~Stack();
      void *Read(int index);
      int getNumber(){return Next-1;}  
      bool Push(void *Data);
      void *Pop();
      bool IsEmpty();
};

#endif //STACK_H