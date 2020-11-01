//: C06:ComposeFinal.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// An adaptable composer
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "NumStringGen.h"
using namespace std;

template<typename F1, typename F2>
class unary_composer
  : public unary_function<typename F2::argument_type,
                          typename F1::result_type> {
public:
   unary_composer(F1 f1, F2 f2) : f1(f1), f2(f2) {}
   typename F1::result_type
     operator()(typename F2::argument_type x) {
      return f1(f2(x));
   }
private:
   F1 f1;
   F2 f2;
};
template<typename F1, typename F2>
unary_composer<F1, F2> compose(F1 f1, F2 f2) {
   return unary_composer<F1, F2>(f1, f2);
}
int main() {
  const int sz = 9;
  vector<string> vs(sz);
  // Fill it with random number strings:
  generate(vs.begin(), vs.end(), NumStringGen());
  copy(vs.begin(), vs.end(), 
    ostream_iterator<string>(cout, "\t"));
  cout << endl;
  vector<double> vd;
  transform(vs.begin(), vs.end(), back_inserter(vd),
    compose(ptr_fun(atof), mem_fun_ref(&string::c_str)));
  copy(vd.begin(), vd.end(), 
    ostream_iterator<double>(cout, "\t"));
  cout << endl;
} ///:~
