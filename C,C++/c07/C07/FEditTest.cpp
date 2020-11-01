//: C07:FEditTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} FileEditor
// Test the FileEditor tool
#include <sstream>
#include "FileEditor.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
  FileEditor file;
  if(argc > 1) {
    file.open(argv[1]);
  } else {
    file.open("FEditTest.cpp");
  }
  // Do something to the lines...
  int i = 1;
  FileEditor::iterator w = file.begin();
  while(w != file.end()) {
    ostringstream ss;
    ss << i++;
    *w = ss.str() + ": " + *w;
    w++;
  }
  // Now send them to cout:
  file.write();
} ///:~
