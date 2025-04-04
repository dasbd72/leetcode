#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(m + n - 1, 0);
        dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < m + n - 1; i++) {
            int j0 = max(0, i - (m - 1));
            int j1 = min(i, n - 1);
            for (int j = j1; j >= j0; j--) {
                int r = i - j;
                int c = j;
                int tmp = 0;
                if (obstacleGrid[r][c] == 1) {
                    dp[j] = tmp;
                    continue;
                }
                if (r - 1 >= 0) {
                    tmp += dp[j];
                }
                if (c - 1 >= 0) {
                    tmp += dp[j - 1];
                }
                dp[j] = tmp;
            }
        }
        return dp[n - 1];
    }
};