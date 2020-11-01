//: :require.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Test for error conditions in programs
// Local "using namespace std" for old compilers
#ifndef REQUIRE_H
#define REQUIRE_H
#include <cstdio>
#include <cstdlib>
#include <fstream>

inline void require(bool requirement, 
  const char* msg = "Requirement failed") {
  using namespace std;
  if (!requirement) {
    fputs(msg, stderr);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireArgs(int argc, int args, 
  const char* msg = "Must use %d arguments") {
  using namespace std;
   if (argc != args + 1) {
     fprintf(stderr, msg, args);
     fputs("\n", stderr);
     exit(EXIT_FAILURE);
   }
}

inline void requireMinArgs(int argc, int minArgs,
  const char* msg = 
    "Must use at least %d arguments") {
  using namespace std;
  if(argc < minArgs + 1) {
    fprintf(stderr, msg, minArgs);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}
  
inline void assure(std::ifstream& in, 
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr,
      "Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::ofstream& in, 
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr,
      "Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
}
// Do we need this???
inline void assure(std::fstream& in, 
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr,
      "Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
}
#endif // REQUIRE_H ///:~
