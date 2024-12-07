#include <iostream>
#include "io.h"
using namespace std;

void print(string s) {
  printf("%s", s.c_str());
}

void printi(int i) {
  printf("%d", i);
}

void prints(str s) {
  cout << s.c[0];
}

str chomp(str what) {
  what.c[0].erase(what.c[0].size()-1, what.c[0].size());
  return what;
}
