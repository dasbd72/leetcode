#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> s(nums.begin(), nums.end());
        int prev = -10000000;
        int len = 1;
        int ans = 1;
        for (auto n : s) {
            if (n == prev + 1) {
                len++;
                ans = max(ans, len);
            } else {
                len = 1;
            }
            prev = n;
        }
        return ans;
    }
};