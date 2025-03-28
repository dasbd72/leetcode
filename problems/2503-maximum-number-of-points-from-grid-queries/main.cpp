#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        int aggregated = 0;
        set<int> queries_set(queries.begin(), queries.end());
        vector<bool> visited(rows * cols, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> bfs_queue;
        unordered_map<int, int> answer_map;
        vector<int> answer(queries.size(), 0);

        bfs_queue.emplace(grid[0][0], 0);
        visited[0] = 1;
        for (const int& query : queries_set) {
            while (bfs_queue.size()) {
                pair<int, int> data;
                int index, r, c, nindex, nr, nc;
                data = bfs_queue.top();
                index = data.second;
                r = index / cols, c = index % cols;
                if (grid[r][c] < query) {
                    // only pop if valid
                    bfs_queue.pop();
                    aggregated++;
                    // walk
                    for (int d = 0; d < 4; d++) {
                        nr = r + directions[d].first, nc = c + directions[d].second, nindex = nr * cols + nc;
                        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || visited[nindex]) {
                            continue;
                        }
                        bfs_queue.emplace(grid[nr][nc], nindex);
                        visited[nindex] = 1;
                    }
                } else {
                    break;
                }
            }
            answer_map[query] = aggregated;
        }
        for (int i = 0; i < queries.size(); i++) {
            answer[i] = answer_map[queries[i]];
        }
        return answer;
    }
};