#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
   public:
    int size;
    vector<int> rank, parent;
    DisjointSet(int size) : size(size), rank(size, 0), parent(size, -1) {
    }
    int findRoot(int u) {
        if (parent[u] == -1) {
            return u;
        }
        return parent[u] = findRoot(parent[u]);
    }
    void join(int u, int v) {
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u == root_v) {
            return;
        }
        if (rank[root_u] > rank[root_v]) {
            swap(root_u, root_v);
        }
        rank[root_u]++;
        parent[root_v] = root_u;
    }
};

class Solution {
   public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> components;
        int answer = 0;
        for (auto& edge : edges) {
            ds.join(edge[0], edge[1]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for (int i = 0; i < n; i++) {
            components[ds.findRoot(i)].emplace_back(i);
        }
        for (auto& [_, nodes] : components) {
            bool valid = true;
            for (auto& node : nodes) {
                if (degree[node] != nodes.size() - 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                answer++;
            }
        }
        return answer;
    }
};