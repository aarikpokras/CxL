#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> read_file(string file) {
    vector<string> ret_vec;
    ifstream f_end(file);
    if (!f_end.is_open()) {
        ret_vec.push_back("");
        return ret_vec;
    }
    string ln;
    while(getline(f_end, ln)) {
        ret_vec.push_back(ln);
    }
    f_end.close();
    return ret_vec;
}
