#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int curr = n, prev = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = INT_MAX;
                if (j - 1 >= 0) {
                    tmp = min(tmp, matrix[i - 1][j - 1]);
                }
                tmp = min(tmp, matrix[i - 1][j]);
                if (j + 1 < n) {
                    tmp = min(tmp, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += tmp;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};