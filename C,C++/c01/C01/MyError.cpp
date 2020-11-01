//: C01:MyError.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
class MyError {
	const char* const data;
public:
	MyError(const char* const msg = 0) : data (msg) {}
};

void f() {
   // Here we "throw" an exception object:
   throw MyError("something bad happened");
}

int main() {
   // As you'll see shortly, 
   // we'll want a "try block" here:
	f();
} ///:~
