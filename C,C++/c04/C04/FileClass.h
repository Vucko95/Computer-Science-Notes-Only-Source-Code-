//: C04:FileClass.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// stdio files wrapped
#ifndef FILECLASS_H
#define FILECLASS_H
#include <cstdio>
#include <stdexcept>

class FileClass {
  std::FILE* f;
public:
  struct FileClassError : std::runtime_error {
  public:
    FileClassError(const char* msg)  
      : std::runtime_error(msg) {}
  }; 
  FileClass(const char* fname, const char* mode = "r");
  ~FileClass();
  std::FILE* fp();
};
#endif // FILECLASS_H ///:~
