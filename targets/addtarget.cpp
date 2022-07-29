#include "include/add.hpp"
#include "include/log.hpp"

int main() {
  LOG_INFO("This is add target.");
  LOG_INFO("1234 + 5678 = {}", add(1234, 5678));
  return 0;
}