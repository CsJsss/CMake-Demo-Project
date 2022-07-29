#include "include/utils.hpp"

namespace util {

void multiAdd(vector<int> &nums, int l, int r, LL &sum) {
  for (int i = l; i <= r; i++)
    sum += nums[i];
}

LL multiThread(vector<int> &nums, int threadNum) {
  vector<thread> threads(threadNum);
  vector<LL> sum(threadNum, 0LL);
  int n = nums.size(), step = n / threadNum + 1;

  for (int i = 0; i < threadNum; i++) {
    int l = (i == 0) ? 0 : i * step;
    int r = std::min(n - 1, (i + 1) * step - 1);
    threads[i] = thread(multiAdd, ref(nums), l, r, std::ref(sum[i]));
  }

  for (auto &t : threads)
    t.join();

  LL ans = 0;
  for (auto &c : sum)
    ans += c;
  return ans;
}

} // namespace util