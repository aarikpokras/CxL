#include <iostream>
#include <vector>
#include <string>
#include "tools.h"
using namespace std;

string remins(string subject, string what, int times) {
    int len = what.size();
    for (int i = 0; i < times; i++) {
        int index = subject.find(what);
        subject.erase(index, len);
    }
    return subject;
}

vector<string> split(string subject, string delim, int times) {
    vector<string> ret;
    string b_sub = subject;
    for (int i = 0; i <= times; i++) {
        int index = b_sub.find(delim);
        if (index < subject.size()) {
            ret.push_back(b_sub.substr(0, index));
            b_sub.erase(0, index+1);
        } else {
            ret.push_back(b_sub);
            return ret;
        }
    }
    return ret;
}

string reverse(string subject) {
  string ret_(subject.size(), ' ');
  for (int i = subject.size() - 1; i >= 0; i--) {
    ret_[subject.size() - 1 - i] = subject[i];
  }
  return ret_;
}
