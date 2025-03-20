#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
   public:
    int size;
    vector<int> rank, parent, sum;
    DisjointSet(int _size) {
        size = _size;
        rank = vector<int>(size, 0);
        parent = vector<int>(size, -1);
        sum = vector<int>(size, 0xffffffff);
    }
    int findRoot(int u) {
        if (parent[u] == -1) {
            return u;
        }
        return parent[u] = findRoot(parent[u]);
    }
    int rootSum(int u) {
        return sum[findRoot(u)];
    }
    void join(int u, int v, int val) {
        int root_u, root_v;
        root_u = findRoot(u);
        root_v = findRoot(v);
        if (root_u == root_v) {
            sum[root_u] &= val;
            return;
        }
        if (rank[root_u] > rank[root_v]) {
            swap(root_u, root_v);
        }
        rank[root_u]++;
        sum[root_u] &= sum[root_v] & val;
        parent[root_v] = root_u;
    }
};

class Solution {
   public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> answer(query.size(), -1);
        // Disjoint set?
        DisjointSet ds(n);
        int root_u, root_v;
        for (auto& e : edges) {
            ds.join(e[0], e[1], e[2]);
        }
        for (int i = 0; i < query.size(); i++) {
            root_u = ds.findRoot(query[i][0]);
            root_v = ds.findRoot(query[i][1]);
            if (root_u == root_v) {
                answer[i] = ds.rootSum(root_u);
            } else {
                answer[i] = -1;
            }
        }
        return answer;
    }
};