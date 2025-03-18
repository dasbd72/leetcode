#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestNiceSubarray(vector<int>& nums) {
        // Only at most one element in the subarray
        // can have bit 1 for each bit position
        int max_len = 0;
        int l = 0;
        int prev = 0, curr = 0, cross;
        for (int r = 0; r < nums.size(); r++) {
            curr ^= nums[r];
            // if exists bit with prev 1 curr 0 -> need to shrink l
            cross = prev & ~curr;
            // while bit with cross 1 curr 0
            while (cross & ~curr) {
                curr ^= nums[l];
                l++;
            }
            max_len = max(max_len, r - l + 1);
            prev = curr;
        }
        return max_len;
    }
};