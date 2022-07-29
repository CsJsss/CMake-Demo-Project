#include "include/log.hpp"
#include "include/sub.hpp"
#include <iostream>

int main() {

  LOG_INFO("This is sub target.");
  LOG_INFO("1234 - 5678 = {}", sub(1234, 5678));
  return 0;
}