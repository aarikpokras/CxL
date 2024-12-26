#include <iostream>
#include <variant>
#include <cstring>
#include <string>
#include <vector>
#define start int main(int argc, char* argv[]) {
#define begin {
#define end }
#define argit for (int i = 0; i < argc; i++)
#define exitwith return
#pragma once
void print(std::string s);

struct num {
  double c;
  num(double w) : c(w) {}
  std::string as_str() {
    return std::to_string(c);
  }
  num operator+(const double& o) {
    return num(c + o);
  }
  num operator-(const double& o) {
    return c - o;
  }
  num operator*(const double& o) {
    return c * o;
  }
  num operator/(const double& o) {
    return c / o;
  }
  void operator+=(const double& o) {
    c += o;
  }
  void operator-=(const double& o) {
    c -= o;
  }
  void operator*=(const double& o) {
    c *= o;
  }
  void operator/=(const double& o) {
    c /= o;
  }
  void operator++(int) {
    c++;
  }
  void operator--(int) {
    c--;
  }
  bool operator==(const double& o) {
    if (c == o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator!=(const double& o) {
    if (c != o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const double& o) {
    if (c > o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<(const double& o) {
    if (c < o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>=(const double& o) {
    if (c >= o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<=(const double& o) {
    if (c <= o) {
      return true;
    } else {
      return false;
    }
  }
  num operator+(const int& o) {
    return num(c + o);
  }
  num operator-(const int& o) {
    return c - o;
  }
  num operator*(const int& o) {
    return c * o;
  }
  num operator/(const int& o) {
    return c / o;
  }
  void operator+=(const int& o) {
    c += o;
  }
  void operator-=(const int& o) {
    c -= o;
  }
  void operator*=(const int& o) {
    c *= o;
  }
  void operator/=(const int& o) {
    c /= o;
  }
  bool operator==(const int& o) {
    if (c == o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator!=(const int& o) {
    if (c != o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const int& o) {
    if (c > o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<(const int& o) {
    if (c < o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>=(const int& o) {
    if (c >= o) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<=(const int& o) {
    if (c <= o) {
      return true;
    } else {
      return false;
    }
  }
  num operator+(const num& o) {
    return num(c + o.c);
  }
  num operator-(const num& o) {
    return c - o.c;
  }
  num operator*(const num& o) {
    return c * o.c;
  }
  num operator/(const num& o) {
    return c / o.c;
  }
  void operator+=(const num& o) {
    c += o.c;
  }
  void operator-=(const num& o) {
    c -= o.c;
  }
  void operator*=(const num& o) {
    c *= o.c;
  }
  void operator/=(const num& o) {
    c /= o.c;
  }
  bool operator==(const num& o) {
    if (c == o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator!=(const num& o) {
    if (c != o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const num& o) {
    if (c > o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<(const num& o) {
    if (c < o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>=(const num& o) {
    if (c >= o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<=(const num& o) {
    if (c <= o.c) {
      return true;
    } else {
      return false;
    }
  }
  operator int() {
    return c;
  }
  operator double() {
    return c;
  }
};

void loop(void (*what)(void), num times);

void printi(num i);

struct str {
  std::vector<std::string> c;
  str(const char* w) {
    c.push_back(w);
  }
  str(std::string w) {  // Not for user -- this is for
    c.push_back(w);     // operator overloading, which
                        // passes elements of the vector as
                        // std::strings.
  }
  int size() {
    return c[0].size();
  }
  friend str operator+(const str& l, const str& r) {
    std::vector<std::string> ret;

    ret.push_back("");
    ret.push_back("");

    ret[0] = l.c[0].c_str();
    ret[1] = r.c[0].c_str();
    // Take advantage of std::string's concat.
    std::string ret_f = ret[0] + ret[1];
    // This uses the std::string constructor
    return str(ret_f);
  }
  void operator+=(const str& o) {
    c[0] += o.c[0];
  }
  bool operator!=(const str& o) {
    if (c[0] != o.c[0]) {
      return true;
    } else {
      return false;
    }
  }
  bool operator==(const str& o) {
    if (c[0] == o.c[0]) {
      return true;
    } else {
      return false;
    }
  }
  operator std::string() {
    return c[0];
  }
};

struct any {
  std::variant<num, str, const char*, int, double> c;
  any(str w) : c(w) {}
  any(num w) : c(w) {}
  any(int w) : c(w) {}
  any(double w) : c(w) {}
  any(const char* w) : c(w) {}
  bool is_num() {
    if (std::holds_alternative<num>(c)
    || std::holds_alternative<int>(c)
    || std::holds_alternative<double>(c)) {
      return true;
    } else {
      return false;
    }
  }
  bool is_str() {
    if (std::holds_alternative<str>(c)
    || std::holds_alternative<const char*>(c)) {
      return true;
    } else {
      return false;
    }
  }
};

void prints(str s);
str chomp(str what);
str read();

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
  void append(str what) {
    str whatf = str(what);
    c.push_back(whatf.c[0]);
  }
  num items() {
    std::string ret__ = std::to_string(c.size());
    int ret_ = std::stoi(ret__);
    return num(ret_);
  }
  str operator[](const num& o) {
    std::string ret_ = c[o.c];
    return str(ret_);
  }
};
