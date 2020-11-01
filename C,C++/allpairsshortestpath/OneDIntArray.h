/* Project: C++ Assignment 3
 * Purpose: Header for One Dimentional Int Array Class
 * File:    OneDIntArray.h
 * Author:  COAD021
 * Data:    02APR2001
 */

#ifndef ONEDINTARRAY_H
#define ONEDINTARRAY_H

#include "Generic1DArray.h"
#include "MyException.h"

class OneDIntArray : protected Generic1DArray {
  
   public:
      OneDIntArray(int numElements) : Generic1DArray(numElements, sizeof(int)) {}
      
      int& operator[](int index) {
         if (index < 0 || index >= quantity)     //Indexes are zero based
	         throw MyException("OneDIntArray operator[]");
         int offset = index * sizeof(int);
         int *p = (int*) &(storage[offset]);
         return (*p);                                         // Dereference p
      }
};

#endif  //ONEDINTARRAY_H