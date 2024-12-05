#include <iostream>
#include <vector>
#pragma once
void print(std::string s);
void printi(int i);

struct fun {
  int c;
  dfun(int w) : c(w) {}
}

template <typename T>
struct num {
  T c;
  num(T w) : c(w) {}
  std::string as_str() {
    return std::to_string(c);
  }
};

struct strarr {
  std::vector<std::string> c;
  strarr(std::vector<std::string> w) : c(w) {}
  std::string join(std::string delim) {
    std::string rets;
    for (int i = 0; i < c.size(); i++) {
      rets += c[i];
      rets += delim;
    }
    return rets.erase(rets.size()-1, rets.size());
  }
};
