#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);  // >=
        auto u = upper_bound(nums.begin(), nums.end(), target);  // >
        if (l == u) {
            return {-1, -1};
        }
        return {(int)distance(nums.begin(), l), (int)distance(nums.begin(), u) - 1};
    }
};