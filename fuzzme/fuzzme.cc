
#include "fuzzme.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

const size_t BUFFER_SIZE = 5;
char BUFFER[BUFFER_SIZE];

const char *FuzzMe(const char *Data, size_t Size) {
  if (Size >= 3 && Data[0] == 'B' && Data[1] == 'U' && Data[2] == 'G') {
    memcpy(BUFFER, Data, Size);
  }
  return BUFFER;
}
