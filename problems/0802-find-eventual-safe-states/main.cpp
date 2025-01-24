#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n;
        uint16_t t;
        vector<uint8_t> state;
        vector<uint16_t> visTime;
        vector<int> safeNodes;

        t = 1;
        n = graph.size();
        state = vector<uint8_t>(n, 0);
        visTime = vector<uint16_t>(n, 0);
        for (int u = 0; u < n; u++) {
            if (state[u] == 0) {
                dfs(graph, state, visTime, u, t);
            }
        }

        for (int u = 0; u < n; u++) {
            if (state[u] == 2) {
                safeNodes.emplace_back(u);
            }
        }
        return safeNodes;
    }
    bool dfs(vector<vector<int>>& graph, vector<uint8_t>& state, vector<uint16_t>& visTime, int u, uint16_t& t) {
        bool unsafe = false;
        state[u] = 1;
        visTime[u] = t++;
        for (auto v : graph[u]) {
            if (state[v] == 0) {
                // Tree edge
                unsafe = unsafe || dfs(graph, state, visTime, v, t);
            } else if (state[v] == 1) {
                // Back edge
                unsafe = true;
            } else {
                if (visTime[v] > visTime[u]) {
                    // Forward edge
                } else {
                    // Cross edge
                    unsafe = unsafe || state[v] == 3;
                }
            }
        }
        if (unsafe) {
            state[u] = 3;
        } else {
            state[u] = 2;
        }
        return unsafe;
    }
};