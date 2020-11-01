//: C03:Trim.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#ifndef TRIM_H
#define TRIM_H
#include <string>
// General tool to strip spaces from both ends:
inline std::string trim(const std::string& s) {
  if(s.length() == 0)
    return s;
  int beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
  int end = s.find_last_not_of(" \a\b\f\n\r\t\v");
  if(beg == std::string::npos) // No non-spaces
    return "";
  return std::string(s, beg, end - beg + 1);
}
#endif // TRIM_H ///:~
