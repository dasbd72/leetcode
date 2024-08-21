#include <bits/stdc++.h>
using namespace std;

// TLE
class SolutionV0 {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> results;
        set<pair<int, int>> checked_set;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (checked_set.find({nums[i], nums[j]}) != checked_set.end())
                    continue;
                checked_set.insert({nums[i], nums[j]});
                for (int k = j + 1; k < len; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        results.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return results;
    }
};

// 80ms
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = len - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                } else if (k < len - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    results.push_back({nums[i], nums[j], nums[k]});
                    j++;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return results;
    }
};
