#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < (1 << nums.size()); i++) {
            int val = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    val ^= nums[j];
                }
            }
            sum += val;
        }
        return sum;
    }
};