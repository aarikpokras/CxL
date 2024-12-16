#include <iostream>
#include <string>
#include <cstdio>
#include "io.h"
using namespace std;

void loop(void (*what)(void), num<int> times) {
  for (num i = 0; i < times; i++) {
    what();
  }
}

str read() {
  string out_;
  getline(cin, out_);
  return str(out_);
}

void print(string s) {
  printf("%s", s.c_str());
}

void prints(str s) {
  cout << s.c[0];
}

str chomp(str what) {
  what.c[0].erase(what.c[0].size()-1, what.c[0].size());
  return what;
}
