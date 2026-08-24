#include <exception>
#include <iostream>

#include "engine_runtime.h"

int main() {
  try {
    return sonar::fishing::engine_ipc::runtime::run_engine_runtime();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 2;
  }
}
