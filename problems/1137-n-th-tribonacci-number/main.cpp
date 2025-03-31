#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> _dp;
    int tribonacci(int n) {
        _dp.assign(max(3, n + 1), 0);
        _dp[0] = 0;
        _dp[1] = 1;
        _dp[2] = 1;
        return dp(n);
    }
    int dp(int n) {
        if (n < 3 || _dp[n]) {
            return _dp[n];
        }
        return _dp[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
    }
};