#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_vol = 0;
        while (l != r) {
            max_vol = max(max_vol, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_vol;
    }
};