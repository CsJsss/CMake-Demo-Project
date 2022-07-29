#include "include/log.hpp"
#include "include/utils.hpp"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <vector>

constexpr int N = 10'000;
using LL = long long;

int main() {
  LOG_INFO("This is multi thread add.");

  std::vector<int> nums;
  srand((unsigned int)time(NULL));
  for (int i = 1; i < N; i++)
    nums.push_back(rand() % N);

  LL sumNative = std::reduce(begin(nums), end(nums));
  LL sumMultiThread = util::multiThread(nums, 8);

  LOG_INFO("sumNative = {}, sumMultiThread = {}", sumNative, sumMultiThread);
  return 0;
}