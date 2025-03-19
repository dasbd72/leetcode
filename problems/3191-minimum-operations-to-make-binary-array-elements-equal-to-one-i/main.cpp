#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                // flip
                cnt++;
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = !nums[i + j];
                }
            }
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            return -1;
        }
        return cnt;
    }
};