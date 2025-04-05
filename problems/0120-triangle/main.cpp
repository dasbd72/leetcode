#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int tmp = INT_MAX;
                if (j <= i - 1) {
                    tmp = min(tmp, triangle[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    tmp = min(tmp, triangle[i - 1][j - 1]);
                }
                triangle[i][j] += tmp;
            }
        }
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};