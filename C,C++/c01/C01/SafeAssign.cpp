//: C01:SafeAssign.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//  Shows an Exception-safe operator=
#include <iostream>
#include <new>       // For std::bad_alloc
#include <cstring>
using namespace std;

// A class that has two pointer members using the heap
class HasPointers {
  // A Handle class to hold the data
  struct MyData {
    const char* theString;
    const int* theInts;
    size_t numInts;
    MyData(const char* pString, const int* pInts,
           size_t nInts)
    : theString(pString), theInts(pInts),  
    numInts(nInts) {}
  } *theData;  // The handle

  // clone and cleanup functions
  static MyData* clone(const char* otherString,
                       const int* otherInts, size_t nInts){
    char* newChars = new char[strlen(otherString)+1];
    int* newInts;
    try {
      newInts = new int[nInts];
    } catch (bad_alloc&) {
      delete [] newChars;
      throw;
    }
    try {
      // This example uses built-in types, so it won't
      // throw, but for class types it could throw, so we
      // use a try block for illustration. (This is the
      // point of the example!)
      strcpy(newChars, otherString);
      for (size_t i = 0; i < nInts; ++i)
        newInts[i] = otherInts[i];
    } catch (...) {
      delete [] newInts;
      delete [] newChars;
      throw;
    }
    return new MyData(newChars, newInts, nInts);
  }
  static MyData* clone(const MyData* otherData) {
    return clone(otherData->theString,
                 otherData->theInts,
                 otherData->numInts);
  }
  static void cleanup(const MyData* theData) {
    delete [] theData->theString;
    delete [] theData->theInts;
    delete theData;
  }
public:
  HasPointers(const char* someString, const int* someInts,
              size_t numInts) {
    theData = clone(someString, someInts, numInts);
  }
  HasPointers(const HasPointers& source) {
    theData = clone(source.theData);
  }
  HasPointers& operator=(const HasPointers& rhs) {
    if (this != &rhs) {
      MyData* newData =
      clone(rhs.theData->theString,
            rhs.theData->theInts,
            rhs.theData->numInts);
      cleanup(theData);
      theData = newData;
    }
    return *this;
  }
  ~HasPointers() {
    cleanup(theData);
  }
  friend ostream& operator<<(ostream& os,
                             const HasPointers& obj) {
    os << obj.theData->theString << ": ";
    for (size_t i = 0; i < obj.theData->numInts; ++i)
      os << obj.theData->theInts[i] << ' ';
    return os;
  }
};

int main() {
  int someNums[] = {1, 2, 3, 4};
  size_t someCount = sizeof someNums / sizeof someNums[0];
  int someMoreNums[] = {5, 6, 7};
  size_t someMoreCount =
  sizeof someMoreNums / sizeof someMoreNums[0];
  HasPointers h1("Hello", someNums, someCount);
  HasPointers h2("Goodbye", someMoreNums, someMoreCount);
  cout << h1 << endl;  // Hello: 1 2 3 4
  h1 = h2;
  cout << h1 << endl;  // Goodbye: 5 6 7
} ///:~
