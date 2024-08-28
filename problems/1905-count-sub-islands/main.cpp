#include <bits/stdc++.h>
using namespace std;

typedef set<pair<int, int>> Island;

class SolutionV0 {
    // The two set solution, too slow
   public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // 0 is ocean
        // 1 is island unmarked
        // Find each sub-island in grid1 first
        // Mark each sub-island with a distinct number
        // Make a set of positions of each sub-island
        int m1 = grid1.size(), n1 = grid1[0].size();
        int idx1 = 2;
        vector<Island> islands1(2);  // Initialize with 2 for index 0 and index 1;
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                if (grid1[i][j] != 1)
                    continue;
                // Increase size of islands
                islands1.push_back({});
                flood(grid1, islands1[idx1], i, j, idx1);
                idx1++;
            }
        }

        int count = 0;
        int m2 = grid2.size(), n2 = grid2[0].size();
        int idx2 = 2;
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                if (grid2[i][j] != 1)
                    continue;
                Island island2;
                flood(grid2, island2, i, j, idx2);
                idx2++;

                // Only when all island2 is in island1 the island is an sub-island
                bool passed = true;
                Island& island1 = islands1[grid1[i][j]];
                for (auto block : island2) {
                    if (island1.find(block) == island1.end()) {
                        passed = false;
                        break;
                    }
                }
                if (passed) {
                    count++;
                }
            }
        }

        return count;
    }

   private:
    vector<pair<int, int>> dvs = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool tryMove(vector<vector<int>>& grid, int m, int n, int ni, int nj) {
        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            return false;
        return grid[ni][nj] == 1;
    }

    void flood(vector<vector<int>>& grid, Island& island, int i, int j, int idx) {
        int m = grid.size(), n = grid[0].size();
        stack<pair<int, int>> stk;
        floodOnce(grid, stk, island, i, j, idx);
        while (!stk.empty()) {
            auto [i, j] = stk.top();
            stk.pop();
            // Try on the four directions
            for (auto [di, dj] : dvs) {
                int ni = i + di, nj = j + dj;
                if (!tryMove(grid, m, n, ni, nj))
                    continue;
                floodOnce(grid, stk, island, ni, nj, idx);
            }
        }
    }

    void floodOnce(vector<vector<int>>& grid, stack<pair<int, int>>& stk, Island& island, int i, int j, int idx) {
        stk.push({i, j});
        island.insert({i, j});
        grid[i][j] = idx;
    }
};

class Solution {
    // Floods simultaneously in this version
   public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(), n = grid1[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] != 1)
                    continue;
                if (flood(grid1, grid2, i, j, grid1[i][j] == 1))
                    count++;
            }
        }
        return count;
    }

   private:
    int m, n;
    const int dis[4] = {-1, 0, 1, 0};
    const int djs[4] = {0, 1, 0, -1};

    inline bool tryMove(vector<vector<int>>& grid, int m, int n, int ni, int nj) {
        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            return false;
        return grid[ni][nj] == 1;
    }

    // flood fills an island of grid2 with a new index
    // returns if the island is a sub-island of grid1 by checking if each blocks on grid1 is also on island
    bool flood(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool matched) {
        bool pass = matched;
        stack<tuple<int, int>> stk;
        stk.push({i, j});
        grid2[i][j] = 2;
        while (!stk.empty()) {
            auto [i, j] = stk.top();
            stk.pop();
            // Try on the four directions
#pragma unroll
            for (int d = 0; d < 4; d++) {
                int ni = i + dis[d], nj = j + djs[d];
                if (!tryMove(grid2, m, n, ni, nj))
                    continue;
                // If only grid2 contains, then it is unavailable
                if (pass && grid1[ni][nj] != 1)
                    pass = false;
                stk.push({ni, nj});
                grid2[ni][nj] = 2;
            }
        }
        return pass;
    }
};

auto _ = []() noexcept {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0; }();
