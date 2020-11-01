/* Project: C++ Assignment 3
 * Purpose: Header for String Table Class
 * File:    StringTable.h
 * Author:  COAD021
 * Date:    02APR2001
 */

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include "Generic1DArray.h"

class StringTable : public Generic1DArray {
   protected:
      int next;

   public:
      StringTable(int numElements, int elSize) : Generic1DArray(numElements, elSize) {
         next = 0;
      }

      enum {NOTFOUND = -1};

      const char* getString(int index) {
         if(index < 0 || index >= next)
            throw MyException("Index out of bounds StringTable.getString");
         return (const char*) fetch(index);
      }

      int getIndex(const char* s) {
         int check;
         for (int k=0; k<quantity; k++) {
            check = strcmp(s,(const char*)fetch(k));
            if (check == 0) return (k);
         }
         return NOTFOUND;      
      }

      int addString(const char* s) {
         int index = getIndex(s);
         if(index != NOTFOUND) return (index);  // If index is found
         add((void*)s, next);
         return(next++);
   }
};

#endif  //STRINGTABLE_H