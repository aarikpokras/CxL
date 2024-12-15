#include <stdio.h>
#include "fs.h"

int file_size(const char* file) {
  FILE *f = fopen(file, "r");
  if (f == NULL) {
    return 0;
  }
  fseek(f, 0, SEEK_END);
  int ret_ = ftell(f);
  rewind(f);
  fclose(f);
  return ret_;
}
