#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // top-down method
    // vector<int> _dp;
    // vector<char> _vis;
    // int minCostClimbingStairs(vector<int>& cost) {
    //     _dp.assign(cost.size() + 1, 0);
    //     _vis.assign(cost.size() + 1, 0);
    //     return dp(cost.size(), cost);
    // }
    // int dp(int level, vector<int>& cost) {
    //     if(level < 2 || _vis[level]) {
    //         return _dp[level];
    //     }
    //     _vis[level] = 1;
    //     return _dp[level] = min(dp(level-1, cost) + cost[level - 1],
    //     dp(level-2, cost) + cost[level - 2]);
    // }

    // buttom-up method
    // int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int> dp(cost.size() + 1, 0);
    //     for (int i = 2; i < cost.size() + 1; i++) {
    //         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    //     }
    //     return dp[cost.size()];
    // }

    // buttom-up method
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        for (int i = 2; i < cost.size(); i++) {
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }
        return cost[cost.size() - 1];
    }
};