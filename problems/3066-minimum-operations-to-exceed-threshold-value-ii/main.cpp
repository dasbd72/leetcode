#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());
        int a, b, cnt;
        long long c;
        cnt = 0;
        while (pq.size() >= 2 && pq.top() < k) {
            cnt++;
            // Get the smallest two numbers
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            // Required to prevent overflow
            c = min((long long)a * 2 + b, (long long)INT32_MAX);
            pq.push(c);
        }
        return cnt;
    }
};