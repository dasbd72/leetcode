#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> prefixSum(2, vector<long long>(n + 1, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                prefixSum[i][j + 1] = prefixSum[i][j] + grid[i][j];
            }
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long u = prefixSum[0][n] - prefixSum[0][i + 1];
            long long d = prefixSum[1][i] - prefixSum[1][0];
            long long v = max(u, d);
            ans = min(v, ans);
        }
        return ans;
    }
};