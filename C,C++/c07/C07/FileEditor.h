//: C07:FileEditor.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// File editor tool
#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include <iostream>
#include <string>
#include <vector>

class FileEditor : 
  public std::vector<std::string> {
public:
  void open(const char* filename);
  FileEditor(const char* filename) {
    open(filename);
  }
  FileEditor() {};
  void write(std::ostream& out = std::cout);
};
#endif // FILEEDITOR_H ///:~
