#include <bits/stdc++.h>
using namespace std;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (!check(R)) {
        return {R, R + 1};
    }
    if (check(L)) {
        return {L - 1, L};
    }
    while (L + 1 < R) {
        Ty M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    return {L, R};
}

class Solution {
   public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [&](int cap) {
            // V1 & V2
            // int dp[2][2] = {};
            // int tmp_max = 0;
            // for(int i = 0; i < n; i++) {
            //     // V1
            //     // if(i == 0) {
            //     //     dp[1][0] = tmp_max;
            //     //     dp[1][1] = (cap >= nums[i] ? 1 : 0);
            //     // } else if(i == 1) {
            //     //     dp[1][0] = tmp_max;
            //     //     dp[1][1] = (cap >= nums[i] ? 1 : 0);
            //     // } else {
            //     //     dp[1][0] = tmp_max;
            //     //     dp[1][1] = dp[0][0] + (cap >= nums[i] ? 1 : 0);
            //     // }
            //     // V2
            //     dp[1][0] = tmp_max;
            //     dp[1][1] = dp[0][0] + (cap >= nums[i] ? 1 : 0);
            //     tmp_max = max(dp[1][0], dp[1][1]);
            //     dp[0][0] = dp[1][0];
            //     dp[0][1] = dp[1][1];
            // }
            // return tmp_max >= k;

            // V3
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (cap >= nums[i]) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= k;
        };
        auto [l, r] = binarySearch(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()), check);
        return r;
    }
};