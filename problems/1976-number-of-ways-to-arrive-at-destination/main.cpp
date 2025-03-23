#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static constexpr int modular = 1e9 + 7;

    vector<vector<pair<int, int>>> adj;
    vector<long long> distance;
    vector<vector<int>> parents;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    vector<long long> ways;
    int countPaths(int n, vector<vector<int>>& roads) {
        adj = vector<vector<pair<int, int>>>(n);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }

        distance = vector<long long>(n, LLONG_MAX);
        ways = vector<long long>(n, 0);
        pq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>();
        distance[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);
        auto relax = [&](int u) {
            for (auto& [v, time] : adj[u]) {
                if (distance[u] + time < distance[v]) {
                    distance[v] = distance[u] + time;
                    ways[v] = ways[u];
                    pq.emplace(distance[v], v);
                } else if (distance[u] + time == distance[v]) {
                    ways[v] = (ways[v] + ways[u]) % modular;
                }
            }
        };
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            // Important
            if (d > distance[u]) {
                cout << d << " " << distance[u] << "\n";
                continue;
            }
            relax(u);
        }
        return ways[n - 1];
    }
};