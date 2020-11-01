//: C04:Cppcheck.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Configures .h & .cpp files to conform to style
// standard. Tests existing files for conformance.
#include <fstream>
#include <sstream>
#include <string>
#include "../require.h"
using namespace std;

bool startsWith(const string& base, const string& key) {
  return base.compare(0, key.size(), key) == 0;
}

void cppCheck(string fileName) {
  enum bufs { BASE, HEADER, IMPLEMENT,
    HLINE1, GUARD1, GUARD2, GUARD3,
    CPPLINE1, INCLUDE, BUFNUM };
  string part[BUFNUM];
  part[BASE] = fileName;
  // Find any '.' in the string:
  size_t loc = part[BASE].find('.');
  if(loc != string::npos) 
    part[BASE].erase(loc); // Strip extension
  // Force to upper case:
  for(size_t i = 0; i < part[BASE].size(); i++)
    part[BASE][i] = toupper(part[BASE][i]);
  // Create file names and internal lines:
  part[HEADER] = part[BASE] + ".h";
  part[IMPLEMENT] = part[BASE] + ".cpp";
  part[HLINE1] = "//" ": " + part[HEADER];
  part[GUARD1] = "#ifndef " + part[BASE] + "_H";
  part[GUARD2] = "#define " + part[BASE] + "_H";
  part[GUARD3] = "#endif // " + part[BASE] +"_H";
  part[CPPLINE1] = string("//") + ": " 
    + part[IMPLEMENT];
  part[INCLUDE] = "#include \"" + part[HEADER] + "\"";
  // First, try to open existing files:
  ifstream existh(part[HEADER].c_str()),
           existcpp(part[IMPLEMENT].c_str());
  if(!existh) { // Doesn't exist; create it
    ofstream newheader(part[HEADER].c_str());
    assure(newheader, part[HEADER].c_str());
    newheader << part[HLINE1] << endl
      << part[GUARD1] << endl
      << part[GUARD2] << endl << endl
      << part[GUARD3] << endl;
  } else { // Already exists; verify it
    stringstream hfile; // Write & read
    ostringstream newheader; // Write
    hfile << existh.rdbuf();
    // Check that first three lines conform:
    bool changed = false;
    string s;
    hfile.seekg(0);
    getline(hfile, s);
    bool lineUsed = false;
    // The call to good() is for Microsoft (later too)
    for (int line = HLINE1; hfile.good() && line <= GUARD2; 
         ++line) {
      if(startsWith(s, part[line])) {
        newheader << s << endl;
        lineUsed = true;
        if (getline(hfile, s))
          lineUsed = false;
      } else {
        newheader << part[line] << endl;
        changed = true;
        lineUsed = false;
      }
    }
    // Copy rest of file
    if (!lineUsed)
      newheader << s << endl;
    newheader << hfile.rdbuf();
    // Check for GUARD3
    string head = hfile.str();
    if(head.find(part[GUARD3]) == string::npos) {
      newheader << part[GUARD3] << endl;
      changed = true;
    }
    // If there were changes, overwrite file:
    if(changed) {
      existh.close();
      ofstream newH(part[HEADER].c_str());
      assure(newH, part[HEADER].c_str());
      newH << "//@//\n"  // Change marker
        << newheader.str();
    }
  }
  if(!existcpp) { // Create cpp file
    ofstream newcpp(part[IMPLEMENT].c_str());
    assure(newcpp, part[IMPLEMENT].c_str());
    newcpp << part[CPPLINE1] << endl
      << part[INCLUDE] << endl;
  } else { // Already exists; verify it
    stringstream cppfile;
    ostringstream newcpp;
    cppfile << existcpp.rdbuf();
    // Check that first two lines conform:
    bool changed = false;
    string s;
    cppfile.seekg(0);
    getline(cppfile, s);
    bool lineUsed = false;
    for (int line = CPPLINE1;
         cppfile.good() && line <= INCLUDE;
         ++line) {
      if(startsWith(s, part[line])) {
        newcpp << s << endl;
        lineUsed = true;
        if (getline(cppfile, s))
          lineUsed = false;
      } else {
        newcpp << part[line] << endl;
        changed = true;
        lineUsed = false;
      }
    }
    // Copy rest of file
    if (!lineUsed)
      newcpp << s << endl;
    newcpp << cppfile.rdbuf();
    // If there were changes, overwrite file:
    if(changed){
      existcpp.close();
      ofstream newCPP(part[IMPLEMENT].c_str());
      assure(newCPP, part[IMPLEMENT].c_str());
      newCPP << "//@//\n"  // Change marker
        << newcpp.str();
    }
  }
}

int main(int argc, char* argv[]) {
  if(argc > 1)
    cppCheck(argv[1]);
  else
    cppCheck("cppCheckTest.h");
} ///:~
