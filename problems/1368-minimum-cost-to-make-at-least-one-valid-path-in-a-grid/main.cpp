#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCost(vector<vector<int>>& grid) {
        int h, w;
        vector<vector<pair<int, int>>> adj;
        auto get_id = [&](int r, int c) {
            return r * w + c;
        };
        auto move = [&](int r, int c, int d) {
            if (d == 1) {
                c++;
                if (c >= w) {
                    c = -1;
                }
            } else if (d == 2) {
                c--;
            } else if (d == 3) {
                r++;
                if (r >= h) {
                    r = -1;
                }
            } else {
                r--;
            }
            return make_pair(r, c);
        };

        h = grid.size();
        w = grid[0].size();
        adj = vector<vector<pair<int, int>>>(h * w);

        // Build the adj graph
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                for (int d = 1; d < 5; d++) {
                    auto [nr, nc] = move(r, c, d);
                    if (nr == -1 || nc == -1) {
                        continue;
                    }
                    int w = (d == grid[r][c]) ? 0 : 1;
                    adj[get_id(r, c)].push_back(make_pair(get_id(nr, nc), w));
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes;
        vector<int> dist(h * w, h * w);  // Initialize distance with maximum
        vector<bool> vis(h * w, 0);      // Vertices visited
        dist[0] = 0;                     // Initialize distance of root
        nodes.push(make_tuple(0, 0));    // Push a dummy edge to start from 0
        while (nodes.size()) {
            auto [d, u] = nodes.top();
            nodes.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            for (auto [v, w] : adj[u]) {
                if (!vis[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    nodes.push(make_tuple(dist[v], v));
                }
            }
        }
        return dist[h * w - 1];
    }
};