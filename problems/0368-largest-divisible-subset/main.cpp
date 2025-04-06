#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxv = 0, maxi = 0;
        vector<int> dp(n, 1);
        vector<int> pi(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    pi[j] = i;
                    if (maxv < dp[j]) {
                        maxv = dp[j];
                        maxi = j;
                    }
                }
            }
        }
        vector<int> ans;
        while (maxi != -1) {
            ans.push_back(nums[maxi]);
            maxi = pi[maxi];
        }
        return ans;
    }
};