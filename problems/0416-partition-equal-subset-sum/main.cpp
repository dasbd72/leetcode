#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0, target_sum;
        for (auto num : nums) {
            total_sum += num;
        }
        if (total_sum % 2 == 1) {
            return false;
        }
        target_sum = total_sum / 2;
        vector<bool> dp(target_sum + 1, false);
        dp[0] = true;
        for (auto num : nums) {
            for (int i = target_sum; i >= 0; i--) {
                if (!dp[i]) {
                    continue;
                }
                if (i + num <= target_sum) {
                    dp[i + num] = true;
                }
            }
        }
        return dp[target_sum];
    }
};