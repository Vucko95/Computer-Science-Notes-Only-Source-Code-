/* Project: C++ Assignment 3
 * Purpose: Header for Generic One Dimentional Array Class
 * File:    Generic1DArray.h
 * Author:  COAD021
 * Date:    02APR2001
 */

#ifndef GENERIC1DARRAY_H
#define GENERIC1DARRAY_H

#include "MyException.h"

class Generic1DArray {

protected:
   int elSize;      // Size of each space
   int quantity;    // Number of storage spaces

   unsigned char* storage;

public:
   Generic1DArray(int nEls, int sz) {
      quantity = nEls;
      elSize = sz;
      int Size = quantity * elSize;
      storage = new unsigned char [Size];
   }

   Generic1DArray::~Generic1DArray() {
      if(storage != 0) delete []storage;
   }

   void add(void* element, int inx) {
      if (inx < 0 || inx >= quantity)
         throw MyException("Generic1DArray add",inx);
      memcpy(&(storage[inx*elSize]), element, elSize);
      if(!storage) {
         throw MyException("memcpy error - add Generic1DArray");
      }
   }

   void* fetch(int index) const {    
      if(index >= quantity || index < 0) return 0;
      // Return address of desired element:
      return &(storage[index * elSize]);
   }
};

#endif // GENERIC1DARRAY_H
