#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.emplace_back(0);
        nums.emplace_back(0);
        vector<int> dp(n + 2, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for (int i = 3; i < n + 2; i++) {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
        }
        return dp[n + 1];
    }
};