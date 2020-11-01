//: C03:ExtractCode.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Extracts code from text
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// Legacy non-standard C header for mkdir()
#ifdef __GNUC__
#include <sys/stat.h>
#elif defined(__BORLANDC__) || defined(_MSC_VER)
#include <direct.h>
#else
#error Compiler not supported
#endif

// Check to see if directory exists
// by attempting to open a new file
// for output within it.
bool exists(string fname) {
  size_t len = fname.length();
  if(fname[len-1] != '/' && fname[len-1] != '\\')
    fname.append("/");
  fname.append("000.tmp");
  ofstream outf(fname.c_str());
  bool existFlag = outf;
  if (outf) {
    outf.close();
    remove(fname.c_str());
  }
  return existFlag;
}

int main(int argc, char* argv[]) {
  // See if input file name provided
  if(argc == 1) {
    cerr << "usage: extractCode file [dir]\n";
    exit(EXIT_FAILURE);
  }
  // See if input file exists
  ifstream inf(argv[1]);
  if(!inf) {
    cerr << "error opening file: " << argv[1] << endl;
    exit(EXIT_FAILURE);
  }
  // Check for optional output directory
  string root("./");  // current is default
  if(argc == 3) {
    // See if output directory exists
    root = argv[2];
    if(!exists(root)) {
      cerr << "no such directory: " << root << endl;
      exit(EXIT_FAILURE);
    }
    size_t rootLen = root.length();
    if(root[rootLen-1] != '/' && root[rootLen-1] != '\\')
      root.append("/");
  }
  // Read input file line by line
  // checking for code delimiters
  string line;
  bool inCode = false;
  bool printDelims = true;
  ofstream outf;
  while (getline(inf, line)) {
    size_t findDelim = line.find("//" "/:~");
    if(findDelim != string::npos) {
      // Output last line and close file
      if (!inCode) {
        cerr << "Lines out of order\n";
        exit(EXIT_FAILURE);
      }
      assert(outf);
      if (printDelims)
        outf << line << endl;
      outf.close();
      inCode = false;
      printDelims = true;
    } else {
      findDelim = line.find("//" ":");
      if(findDelim == 0) {
        // Check for '!' directive
        if(line[3] == '!') {
          printDelims = false;
          ++findDelim;  // To skip '!' for next search
        }
        // Extract subdirectory name, if any
        size_t startOfSubdir =
          line.find_first_not_of(" \t", findDelim+3);
        findDelim = line.find(':', startOfSubdir);
        if (findDelim == string::npos) {
          cerr << "missing filename information\n" << endl;
          exit(EXIT_FAILURE);
        }
        string subdir;
        if(findDelim > startOfSubdir)
          subdir = line.substr(startOfSubdir,
                               findDelim - startOfSubdir);
        // Extract file name (better be one!)
        size_t startOfFile = findDelim + 1;
        size_t endOfFile =
          line.find_first_of(" \t", startOfFile);
        if(endOfFile == startOfFile) {
          cerr << "missing filename\n";
          exit(EXIT_FAILURE);
        }
        // We have all the pieces; build fullPath name
        string fullPath(root);
        if(subdir.length() > 0)
          fullPath.append(subdir).append("/");
        assert(fullPath[fullPath.length()-1] == '/');
        if (!exists(fullPath))
#ifdef __GNUC__
          mkdir(fullPath.c_str(), 0);  // Create subdir
#else
          mkdir(fullPath.c_str());  // Create subdir
#endif
        fullPath.append(line.substr(startOfFile,
                        endOfFile - startOfFile));
        outf.open(fullPath.c_str());
        if(!outf) {
          cerr << "error opening " << fullPath
               << " for output\n";
          exit(EXIT_FAILURE);
        }
        inCode = true;
        cout << "Processing " << fullPath << endl;
        if(printDelims)
          outf << line << endl;
      }
      else if(inCode) {
        assert(outf);
        outf << line << endl;  // output middle code line
      }
    }
  }
  exit(EXIT_SUCCESS);
} ///:~
