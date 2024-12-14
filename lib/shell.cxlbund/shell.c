#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int execute(const char *command) {
  return system(command);
}
