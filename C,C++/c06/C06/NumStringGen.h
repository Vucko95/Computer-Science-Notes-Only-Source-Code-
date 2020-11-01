//: C06:NumStringGen.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// A random number generator that produces 
// strings representing floating-point numbers
#ifndef NUMSTRINGGEN_H
#define NUMSTRINGGEN_H
#include <string>
#include <cstdlib>
#include <ctime>

class NumStringGen {
  const int SZ; // Number of digits to make
public:
  NumStringGen(int ssz = 5) : SZ(ssz) { 
    std::srand(std::time(0)); 
  }
  std::string operator()() {
    static char n[] = "0123456789";
    const int NSZ = sizeof n / sizeof *n;
    std::string r(SZ, ' ');
    for(int i = 0; i < SZ; i++)
      if(i == SZ/2)
        r[i] = '.'; // Insert a decimal point
      else
        r[i] = n[std::rand() % NSZ];
    return r;
  }
};
#endif // NUMSTRINGGEN_H ///:~
