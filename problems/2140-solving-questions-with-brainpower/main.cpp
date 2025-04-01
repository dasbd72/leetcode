#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> forward(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int j = min(n, i + questions[i][1] + 1);
            forward[i + 1] = max(forward[i + 1], forward[i]);
            forward[j] = max(forward[j], forward[i] + questions[i][0]);
        }
        return forward[n];
    }
};