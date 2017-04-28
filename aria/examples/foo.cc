// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include "aria/examples/foo.h"

#include <iostream>

namespace aria {

Foo::Foo() {
  std::cout << "Foo ctor.." << std::endl;
}

Foo::~Foo() {
  std::cout << "Foo dtor.." << std::endl;
}

}  // namespace aria
