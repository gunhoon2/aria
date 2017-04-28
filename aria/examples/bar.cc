// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/examples/bar.h"

#include <iostream>

namespace aria {

Bar::Bar() {
  std::cout << "Bar ctor.." << std::endl;
}

Bar::~Bar() {
  std::cout << "Bar dtor.." << std::endl;
}

}  // namespace aria
