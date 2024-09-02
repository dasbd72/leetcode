#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < (int)nums.size(); j++) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        int k = i;
        for (; i < (int)nums.size(); i++) {
            nums[i] = 0;
        }
        return k;
    }
};