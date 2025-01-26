#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        set<pair<int, int>> s;
        priority_queue<int, vector<int>, greater<>> npq, ppq;
        int prev;
        auto finalize = [&]() {
            while (npq.size()) {
                int num, pos;
                num = npq.top();
                npq.pop();
                pos = ppq.top();
                ppq.pop();
                nums[pos] = num;
            }
        };

        for (int i = 0; i < nums.size(); i++) {
            s.emplace(nums[i], i);
        }
        prev = 0;
        for (auto [num, pos] : s) {
            if (prev == 0 || num - prev <= limit) {
            } else {
                finalize();
            }
            prev = num;
            npq.emplace(num);
            ppq.emplace(pos);
        }
        finalize();
        return nums;
    }
};