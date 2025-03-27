#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumIndex(vector<int>& nums) {
        // O(n) find dominant number
        int current_cnt = 0, target_num = 0;
        int target_freq = 0;
        for (const auto& num : nums) {
            if (current_cnt == 0 || num == target_num) {
                target_num = num;
                current_cnt++;
            } else {
                current_cnt--;
            }
        }
        // Count target number frequency
        for (const auto& num : nums) {
            if (num == target_num) {
                target_freq++;
            }
        }
        // Check if exist valid split
        if (target_freq <= ((nums.size() + 1) >> 1)) {
            return -1;
        }
        // Find minimum index
        current_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target_num) {
                current_cnt++;
            }
            if (current_cnt > ((i + 1) >> 1)) {
                return i;
            }
        }
        return -1;
    }
};