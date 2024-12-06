#include <iostream>
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
