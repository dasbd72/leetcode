#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        set<int> nums_set;
        for (auto n : nums) {
            nums_set.insert(n);
        }
        vector<int> nums_tmp;
        for (auto n : nums) {
            if (nums_set.find(n) != nums_set.end()) {
                nums_tmp.push_back(n);
                nums_set.erase(n);
            }
        }
        nums = nums_tmp;
        return nums_tmp.size();
    }
};