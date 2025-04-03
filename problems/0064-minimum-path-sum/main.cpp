#include <bits/stdc++.h>
using namespace std;

// // Top-Down (passed)
// class Solution {
// public:
//     vector<vector<int>> *grid_ptr;
//     vector<vector<int>> _dp;
//     int minPathSum(vector<vector<int>>& grid) {
//         _dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INT_MAX));
//         grid_ptr = &grid;
//         return dp(grid.size() - 1, grid[0].size() - 1);
//     }
//     int dp(int r, int c) {
//         if(r == 0 && c == 0) {
//             return (*grid_ptr)[0][0];
//         }
//         if(_dp[r][c] != INT_MAX) {
//             return _dp[r][c];
//         }
//         if(r - 1 >= 0) {
//             _dp[r][c] = min(_dp[r][c], dp(r - 1, c) + (*grid_ptr)[r][c]);
//         }
//         if(c - 1 >= 0) {
//             _dp[r][c] = min(_dp[r][c], dp(r, c - 1) + (*grid_ptr)[r][c]);
//         }
//         return _dp[r][c];
//     }
// };

// // Bottom-Up (passed)
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
//         dp[0][0] = grid[0][0];
//         for(int i = 1; i < m + n - 1; i++) {
//             int j_start, j_end;
//             j_start = max(i - (m - 1), 0), j_end = min(n - 1, i);
//             for(int j = j_start; j <= j_end; j++) {
//                 int r = i - j;
//                 int c = j;
//                 dp[r][c] = INT_MAX;
//                 if(c - 1 >= 0) {
//                     dp[r][c] = min(dp[r][c], dp[r][c - 1] + grid[r][c]);
//                 }
//                 if(r - 1 >= 0) {
//                     dp[r][c] = min(dp[r][c], dp[r - 1][c] + grid[r][c]);
//                 }
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// Bottom-Up (passed)
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Optimization 2, space reduce to O(m + n)
        vector<int> dp(m + n - 1);
        dp[0] = grid[0][0];
        for (int i = 1; i < m + n - 1; i++) {
            int j_start, j_end;
            // Optimization 1, shrink left and right of j
            j_start = max(i - (m - 1), 0), j_end = min(n - 1, i);
            for (int j = j_end; j >= j_start; j--) {
                int r = i - j;
                int c = j;
                int curr = INT_MAX;
                if (c - 1 >= 0) {
                    curr = min(curr, dp[j - 1] + grid[r][c]);
                }
                if (r - 1 >= 0) {
                    curr = min(curr, dp[j] + grid[r][c]);
                }
                dp[j] = curr;
            }
        }
        return dp[min(n - 1, m + n - 1)];
    }
};