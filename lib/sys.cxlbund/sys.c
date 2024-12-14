#include <stdio.h>
#include "sys.h"

const char* get_os() {
  #if defined(__APPLE__)
    return "macOS";
  #elif defined(_WIN32)
    return "Windows";
  #elif defined(__linux__)
    return "Linux";
  #else
    return "Unknown";
  #endif
}
