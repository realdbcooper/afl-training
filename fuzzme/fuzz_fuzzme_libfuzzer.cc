//
// Created by Code Intelligence
//
#include "fuzzme.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  FuzzMe(std::string((const char *)Data, Size).c_str(), Size);
  return 0;
}

