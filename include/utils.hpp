#ifndef __INCLUDE_UTILS_H_
#define __INCLUDE_UTILS_H_

#include <thread>
#include <vector>

/*
 * Link:
 * https://csjsss.github.io/2022/03/24/ConcurrencyAndDistribution/%E5%B9%B6%E8%A1%8C%E6%95%B0%E7%BB%84%E6%B1%82%E5%92%8C/
 */

namespace util {

using std::thread;
using std::vector;
using LL = long long;

void multiAdd(vector<int> &nums, int l, int r, LL &sum);

LL multiThread(vector<int> &nums, int threadNum=4);

} // namespace util

#endif /* __INCLUDE_UTILS_H_ */
