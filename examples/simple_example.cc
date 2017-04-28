// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#include <iostream>

#include "aria/examples/foo.h"

int main(int argc, char* argv[]) {
  if (argc > 0)
    std::cout << argv[0] << " is started..\n";

  std::cout << "Temp Foo object..\n";
  aria::Foo();

  std::cout << "main is stopped..\n";
  return 0;
}
