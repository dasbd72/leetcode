#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumCount(vector<int>& nums) {
        auto checkl = [&](int pos) {
            return nums[pos] < 0;
        };
        auto checkr = [&](int pos) {
            return nums[pos] <= 0;
        };
        auto binary_search = [&](function<bool(int)> check) {
            int l = 0, r = nums.size(), m;
            while (l < r) {
                m = l + (r - l) / 2;
                if (check(m)) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            return l;
        };
        int lpos = binary_search(checkl);
        int rpos = binary_search(checkr);
        int ret = max(lpos, (int)nums.size() - rpos);
        return ret;
    }
};