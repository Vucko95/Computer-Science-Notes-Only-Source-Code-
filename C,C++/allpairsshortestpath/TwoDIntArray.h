/* Project: C++ Assignment 3
 * Purpose: Header for Two Dimentional Int Array Class
 * File:    TwoDIntArray.h
 * Author:  COAD021
 * Date:    02APR2001
 */

#ifndef TWODINTARRAY_H
#define TWODINTARRAY_H

#include "OneDIntArray.h"
#include "MyException.h"

class TwoDIntArray : protected OneDIntArray {
  
   private:
     int nRows;
     int nCols;
  
   public:
     TwoDIntArray(int numRows, int numCols) 
          : OneDIntArray(numRows * numCols), nRows(numRows), nCols(numCols){}
 
     int& operator() (int row, int col) {
       if (row < 0 || row >= nRows)              //Indexes are zero based
	       throw MyException("TwoDIntArray operator() - Row index out of bounds");
       if (col < 0 || col >= nCols)              //Indexes are zero based
	       throw MyException("TwoDIntArray operator() - Column index out of bounds");
       
       int index = (row * nCols) + col;          // Offsets to one dimentional array
 
       return (this->operator[](index));
     }
};

#endif //TWODINTARRAY_H