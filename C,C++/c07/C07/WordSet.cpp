//: C07:WordSet.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
using namespace std;

void wordSet(char* fileName) {
  ifstream source(fileName);
  assure(source, fileName);
  string word;
  set<string> words;
  while(source >> word)
    words.insert(word);
  copy(words.begin(), words.end(),
    ostream_iterator<string>(cout, "\n"));
  cout << "Number of unique words:" 
    << words.size() << endl;
}  

int main(int argc, char* argv[]) {
  if(argc > 1)
    wordSet(argv[1]);
  else
    wordSet("WordSet.cpp");
} ///:~
