#include <iostream>
#pragma once
void print(std::string s);
void printi(int i);

template <typename T>
struct num {
  T c;
  num(T w) : c(w) {}
  std::string as_str() {
    return std::to_string(c);
  }
};
