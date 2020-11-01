//: C09:Database.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// A prototypical resource class
#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <stdexcept>
#include <string>
using std::cout;
using std::string;
using std::runtime_error;

struct DatabaseError : runtime_error {
  DatabaseError(const string& msg) : runtime_error(msg)
  {}
};

class Database {
public:
  Database(const string& dbStr) : dbid(dbStr) {}
  virtual ~Database(){}
  void open() throw(DatabaseError) {
    cout << "connected to " << dbid << '\n';
  }
  void close() {
    cout << dbid << " closed\n";
  }
  //Other database functions...
private:
  string dbid;
};
#endif ///:~
