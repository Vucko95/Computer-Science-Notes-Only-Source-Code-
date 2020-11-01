/* Project: C++ Assignment 3
 * Purpose: Header for MyException Class
 * File:    MyException.h
 * Author:  COAD021
 * Date:    02APR2001
 */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string.h>                              // For strncpy()

class MyException {
private:
   char message[128];
   int errCode;

public:
   MyException(char* errorMsg, int errNum = 0) {
      strncpy(message, errorMsg,128);
      message[127] = 0;
      errCode = errNum;
   }
   const char* getMessage() {return(message);}
   int getErrCode() {return errCode;}
};  

#endif  //MYEXCEPTION_H
