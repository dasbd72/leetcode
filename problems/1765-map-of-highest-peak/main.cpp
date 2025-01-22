#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(pair<int, int> lhs, pair<int, int> rhs) {
    return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

class Solution {
   public:
    vector<pair<int, int>> ds = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int h, w;
        queue<pair<int, int>> que;
        vector<vector<int>> height;

        h = isWater.size();
        w = isWater[0].size();
        height = vector<vector<int>>(h, vector<int>(w, -1));
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (isWater[r][c] == 1) {
                    height[r][c] = 0;
                    que.emplace(r, c);
                }
            }
        }
        while (que.size()) {
            auto pos = que.front();
            auto [r, c] = pos;
            que.pop();
            for (auto d : ds) {
                auto [nr, nc] = pos + d;
                if (nr < 0 || nr >= h || nc < 0 || nc >= w || height[nr][nc] != -1) {
                    continue;
                }
                height[nr][nc] = height[r][c] + 1;
                que.emplace(nr, nc);
            }
        }
        return height;
    }
};
