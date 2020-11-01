//: C07:Valarray1.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{-bor}
// Illustrates basic valarray functionality
#include <iostream>
#include <valarray>
using namespace std;

double f(double x) {
    return 2.0*x - 1.0;
}

template<class T>
void print(const char* lbl, const valarray<T>& a) {
    cout << lbl << ": ";
    for (size_t i = 0; i < a.size(); ++i)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
  double n[] = {1.0, 2.0, 3.0, 4.0};
  valarray<double> v(n, sizeof n / sizeof n[0]);
  print("v", v);
  valarray<double> sh(v.shift(1));
  print("shift 1", sh);
  valarray<double> acc(v + sh);
  print("sum", acc);
  valarray<double> trig(sin(v) + cos(acc));
  print("trig", trig);
  valarray<double> p(pow(v, 3.0));
  print("3rd power", p);
  valarray<double> app(v.apply(f));
  print("f(v)", app);
  valarray<bool> eq(v == app);
  print("v == app?", eq);
  double x = v.min();
  double y = v.max();
  double z = v.sum();
  cout << "x = " << x << ", y = " << y
    << ", z = " << z  << endl;
} ///:~
