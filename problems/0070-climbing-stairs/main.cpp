#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> _dp;
    int climbStairs(int n) {
        _dp.assign(n + 1, 0);
        return dp(n);
    }
    int dp(int n) {
        if (_dp[n]) {
            return _dp[n];
        }
        if (n == 1 || n == 2) {
            return _dp[n] = n;
        }
        return _dp[n] = dp(n - 2) + dp(n - 1);
    }
};