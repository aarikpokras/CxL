#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int execute(const char *command) {
  return system(command);
}

int move_file(const char* origin, const char* destination) {
  char warn[512];
  snprintf(warn, 512, "This program is trying to change file %s. Use ^C now if you wish to stop this.", origin);
  printf("%s\n", warn);
  sleep(1);
  char buf[256];
  snprintf(buf, 256, "mv \"%s\" \"%s\"", origin, destination);
  for (int i = 0; i < sizeof(buf); i++) {
    if (buf[i] == ';' || buf[i] == '&' || buf[i] == '"') {
      // Nice try, bad guy.
      printf("%s\n", "CxL RT35: Could not move file.");
      return 35;
    }
  }
  return system(buf);
}
