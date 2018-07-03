//
// Created by Code Intelligence
//

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>

#include "fuzzme.h"

int main(int argc, char** argv) {
  uint8_t buf[18000];

  while (__AFL_LOOP(1000)) {
    ssize_t read_bytes = read(0, buf, 18000);
    FuzzMe((const char *) buf, (size_t) read_bytes);
    memset(buf, 0, 18000);
  }

}

