#include <bits/stdc++.h>
using namespace std;

// // Top-Down (passed)
// class Solution {
// public:
//     vector<vector<int>> _dp;
//     int uniquePaths(int m, int n) {
//         // // bottom-up
//         // vector<vector<int>> dp(m, vector<int>(n, 0));
//         // dp[0][0] = 1;
//         // for(int i = 0; i < n; i++)

//         _dp = vector<vector<int>> (m, vector<int>(n, 0));
//         return dp(m - 1, n - 1);
//     }
//     int dp(int r, int c) {
//         if(r == 0 && c == 0) {
//             return 1;
//         }
//         if(_dp[r][c]) {
//             return _dp[r][c];
//         }
//         if(r - 1 >= 0) {
//             _dp[r][c] += dp(r - 1, c);
//         }
//         if(c - 1 >= 0) {
//             _dp[r][c] += dp(r, c - 1);
//         }
//         return _dp[r][c];
//     }
// };

// Bottom-Up (passed)
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int r = 1; r < m; r++) {
            for (int i = 0; r - i >= 0 && i < n; i++) {
                if (r - i - 1 >= 0)
                    dp[r - i][i] += dp[r - i - 1][i];
                if (i - 1 >= 0)
                    dp[r - i][i] += dp[r - i][i - 1];
            }
        }
        for (int c = 1; c < n; c++) {
            for (int i = 0; c + i < n && m - 1 - i >= 0; i++) {
                if (m - 1 - i - 1 >= 0)
                    dp[m - 1 - i][c + i] += dp[m - 1 - i - 1][c + i];
                if (c + i - 1 >= 0)
                    dp[m - 1 - i][c + i] += dp[m - 1 - i][c + i - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
