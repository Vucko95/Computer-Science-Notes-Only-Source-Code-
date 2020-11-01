//: C03:Rparse.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} ../TestSuite/Test
#include <string>
#include <vector>
#include "../TestSuite/Test.h"
using namespace std;

class RparseTest : public TestSuite::Test {
  // To store the words:
  vector<string> strings;
public:
  void parseForData() {
    // The ';' characters will be delimiters
    string s("now.;sense;make;to;going;is;This");
    // The last element of the string:
    int last = s.size();
    // The beginning of the current word:
    int current = s.rfind(';');
    // Walk backward through the string:
    while(current != string::npos){
      // Push each word into the vector.
      // Current is incremented before copying to
      // avoid copying the delimiter:
      ++current;
      strings.push_back(
        s.substr(current, last - current));
      // Back over the delimiter we just found,
      // and set last to the end of the next word:
      current -= 2;
      last = current + 1;
      // Find the next delimiter
      current = s.rfind(';', current);
    }
    // Pick up the first word - it's not
    // preceded by a delimiter
    strings.push_back(s.substr(0, last));
  }
  void testData() {
    // Test order them in the new order:
    test_(strings[0] == "This");
    test_(strings[1] == "is");
    test_(strings[2] == "going");
    test_(strings[3] == "to");
    test_(strings[4] == "make");
    test_(strings[5] == "sense");
    test_(strings[6] == "now.");
    string sentence;
    for(int i = 0; i < strings.size() - 1; i++)
      sentence += strings[i] += " ";
    // Manually put last word in to avoid an extra space
    sentence += strings[strings.size() - 1];
    test_(sentence == "This is going to make sense now.");
  }
  void run() {
    parseForData();
    testData();
  }
};

int main() {
  RparseTest t;
  t.run();
  return t.report();
} ///:~
