#include <iostream>
#include <string>
#include <vector>
#pragma once
std::vector<std::string> read_file(std::string file);
int write_file(std::string file, std::string content);
int file_size(const char* file);
