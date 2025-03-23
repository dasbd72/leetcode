#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        auto check = [&](int pos) {
            return nums[pos] >= target;
        };
        int l = 0, r = nums.size() - 1;
        if (!check(r)) {
            return r + 1;
        }
        if (check(l)) {
            return l;
        }
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};