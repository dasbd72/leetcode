#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<char, char> freqs;
        for (int i = nums.size() - 1; i >= 0; i--) {
            freqs[nums[i]] += 1;
            if (freqs[nums[i]] > 1) {
                return (i + 3) / 3;
            }
        }
        return 0;
    }
};