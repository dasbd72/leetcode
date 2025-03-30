#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> minCosts(vector<int>& cost) {
        int minCost = cost[0];
        vector<int> answer(cost.size());
        for (int i = 0; i < cost.size(); i++) {
            minCost = min(minCost, cost[i]);
            answer[i] = minCost;
        }
        return answer;
    }
};