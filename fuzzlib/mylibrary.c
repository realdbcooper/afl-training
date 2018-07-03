#include "mylibrary.h"

#include <stdio.h>
#include <string.h>
#include <stdio.h>

static char payload[10];
static int command_type = 0;

void parse_command(char *data, size_t len) {
  if (len <= 3) {
    return;
  }

//  if (len >= 4 && strncmp(data, "PUT", 3) == 0) {
  if (len >= 4 && data[0] == 'P' && data[1] == 'U' && data[2] == 'T') {
    command_type = 0;
    memcpy(payload, data+3, len-3);
    puts("received command: PUT");
  } else if (strncmp(data, "GET", 3) == 0){
    command_type = 1;
    puts("received command: GET");
  } else if (len >= 4 && strncmp(data, "INFO", 4) == 0) {
    command_type = 2;
    puts("received command: INFO");
  } else if (strncmp(data, "SYS", 3) == 0) {
    command_type = 3;
    puts("received command: SYS");
  } else if (strncmp(data, "DIR", 3) == 0) {
    command_type = 4;
    puts("received command: DIR");
  } else {
    command_type = -1; // Unknown command
    puts("unknown command");
  }
}

int multiply_even(int x, int y){
  int result = y;
  do {
    result <<= 1;
    x >>= 1;
  } while (x % 2 == 0 && x != 0);
  return x == 0 ? result : result * x;
}

int optimized_multiply(int x, int y) {
  if (x % 2 == 0) {
    return multiply_even(x, y);
  } else if (y % 2 == 0) {
    return multiply_even(y, x);
  } else if (x == 0) {
    return 0;
  } else if (y == 0) {
    return 0;
  } else {
    return x * y;
  }
}