#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        vector<pair<int, int>> mapping(m * n);
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                mapping[mat[r][c] - 1] = make_pair(r, c);
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = mapping[arr[i] - 1];
            row[r]++;
            col[c]++;
            if (row[r] == n || col[c] == m) {
                return i;
            }
        }
        return -1;
    }
};