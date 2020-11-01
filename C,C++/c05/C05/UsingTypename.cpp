//: C05:UsingTypename.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Using 'typename' in the template argument list

template<typename T> class X { }; 

int main() {
  X<int> x;
} ///:~
