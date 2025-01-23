#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int h, w;
        int ans;
        vector<char> rows, cols;

        h = grid.size();
        w = grid[0].size();
        ans = 0;
        rows = vector<char>(h, 0);
        cols = vector<char>(w, 0);

        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (grid[r][c]) {
                    rows[r]++;
                    cols[c]++;
                }
            }
        }
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if ((rows[r] >= 2 || cols[c] >= 2) && grid[r][c]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};