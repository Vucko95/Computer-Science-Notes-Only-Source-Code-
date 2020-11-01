//: C02:HiLo.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Plays the game of Hi-lo to illustrate a loop invariant
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Think of a number between 1 and 100\n";
   cout << "I will make a guess; ";
   cout << "tell me if I'm (H)igh or (L)ow\n";
  int low = 1, high = 100;
  bool guessed = false;
  while (!guessed) {
    // Invariant: the number is in the range [low, high]
    if (low > high) {  // Invariant violation
      cout << "You cheated! I quit\n";
      return EXIT_FAILURE;
    }
    int guess = (low + high) / 2;
    cout << "My guess is " << guess << ". ";
    cout << "(H)igh, (L)ow, or (E)qual? ";
    string response;
    cin >> response;
    switch(toupper(response[0])) {
      case 'H':
        high = guess - 1;
        break;
      case 'L':
        low = guess + 1;
        break;
      case 'E':
        guessed = true;
        break;
      default:
        cout << "Invalid response\n";
        continue;
    }
  }
  cout << "I got it!\n";
  return EXIT_SUCCESS;
} ///:~
