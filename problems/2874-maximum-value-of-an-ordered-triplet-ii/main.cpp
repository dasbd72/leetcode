#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int prefix_i = nums[0];
        int prefix_ij = -2e6;
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(
                ans, (long long)nums[i] *
                         prefix_ij);  // ans = max(ans, nums[i] * prefix_ij[i-1])
            prefix_ij =
                max(prefix_ij,
                    prefix_i - nums[i]);  // prefix_ij[i] = max(prefix_ij[i],
                                          // prefix_i[i-1] - nums[i])
            prefix_i =
                max(prefix_i,
                    nums[i]);  // prefix_i[i] = max(prefix_i[i - 1], nums[i]);
        }
        return ans;
    }
};