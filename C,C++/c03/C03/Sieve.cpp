//: C03:Sieve.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} ../TestSuite/Test
#include <cmath>
#include <cstddef>
#include <string>
#include "../TestSuite/Test.h"
using namespace std;

class SieveTest : public TestSuite::Test {
  string sieveChars;
public:
  // Create a 50 char string and set each
  // element to 'P' for Prime
   SieveTest() : sieveChars(50, 'P') {}
  void run() {
    findPrimes();
    testPrimes();
  }
  bool isPrime(int p) {
    if (p == 0 || p == 1) return false;
    int root = int(sqrt(double(p)));
    for (int i = 2; i <= root; ++i)
      if (p % i == 0) return false;
    return true;
  }
  void findPrimes() {
    // By definition neither 0 nor 1 is prime.
    // Change these elements to "N" for Not Prime
    sieveChars.replace(0, 2, "NN");
    // Walk through the array:
    size_t sieveSize = sieveChars.size();
    int root = int(sqrt(double(sieveSize)));
    for (int i = 2; i <= root; ++i)
      // Find all the multiples:
      for (size_t factor = 2; factor * i < sieveSize;
           ++factor)
        sieveChars[factor * i] = 'N';
  }
  void testPrimes() {
    size_t i = sieveChars.find('P');
    while (i != string::npos) {
      test_(isPrime(i++));
      i = sieveChars.find('P', i);
    }
    i = sieveChars.find_first_not_of('P');
    while (i != string::npos) {
      test_(!isPrime(i++));
      i = sieveChars.find_first_not_of('P', i);
    }
  }
};

int main() {
  SieveTest t;
  t.run();
  return t.report();
} ///:~
