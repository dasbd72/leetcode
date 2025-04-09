#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (auto num : nums) {
            if (num > k)
                freqs[num] += 1;
            else if (num < k)
                return -1;
        }
        return freqs.size();
    }
};
