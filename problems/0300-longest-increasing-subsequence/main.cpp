#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int sslen = 0;
        for (int i = 0; i < nums.size(); i++) {
            bool flag = false;
            for (int j = 0; j < sslen; j++) {
                if (nums[i] <= nums[j]) {
                    nums[j] = nums[i];
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            nums[sslen++] = nums[i];
        }
        return sslen;
    }
};