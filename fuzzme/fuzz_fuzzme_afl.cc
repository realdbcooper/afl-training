//
// Created by Code Intelligence
//

#include "fuzzme.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char **argv) {
  std::ifstream ifs(argv[1]);
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()));

  std::cout << FuzzMe(content.c_str(), content.size()) << std::endl;
  return 0;
}
