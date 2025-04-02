#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> num_val;
        for (int i = 0; i < nums.size();) {
            int num = nums[i];
            int cnt = 0;
            while (i < nums.size() && nums[i] == num) {
                cnt++;
                i++;
            }
            num_val.emplace_back(num, num * cnt);
        }
        int n = num_val.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int skip = 0;
            if (i >= 1)
                skip = num_val[i].first - 1 == num_val[i - 1].first;
            int a = 0, b = 0;
            if (i - skip - 1 >= 0)
                a = dp[i - skip - 1];
            if (i - skip - 2 >= 0)
                b = dp[i - skip - 2];
            dp[i] = max(a, b) + num_val[i].second;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};