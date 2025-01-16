#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums2.size() % 2) {
            for (auto num : nums1) {
                ans ^= num;
            }
        }
        if (nums1.size() % 2) {
            for (auto num : nums2) {
                ans ^= num;
            }
        }
        return ans;
    }
};