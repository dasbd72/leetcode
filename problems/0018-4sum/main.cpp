#include <bits/stdc++.h>
using namespace std;

class SolutionV0 {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < len; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // Starting two pointers
                long long sum0 = nums[i] + nums[j];
                int l = j + 1;
                int m = len - 1;
                while (l < m) {
                    if (l > j + 1 && nums[l] == nums[l - 1]) {
                        l++;
                        continue;
                    }
                    if (m < len - 1 && nums[m] == nums[m + 1]) {
                        m--;
                        continue;
                    }
                    long long sum = sum0 + nums[l] + nums[m];
                    if (sum == target) {
                        results.push_back({nums[i], nums[j], nums[l], nums[m]});
                        l++;
                    } else if (sum < target) {
                        l++;
                    } else {
                        m--;
                    }
                }
            }
        }
        return results;
    }
};

class Solution {
    /*
    A faster solution. Avoids redundant duplicated checks.
     */
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < len; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Starting two pointers
                long long remain = (long long)target - nums[i] - nums[j];
                int l = j + 1;
                int m = len - 1;
                while (l < m) {
                    long long sum = (long long)nums[l] + nums[m];
                    if (sum == remain) {
                        results.push_back({nums[i], nums[j], nums[l], nums[m]});
                        int left = nums[l], right = nums[m];
                        l++, m--;
                        // Moved duplicated checks here since only valid combination of
                        // sums should be passed
                        while (l < m && nums[l] == left)
                            l++;
                        while (l < m && nums[m] == right)
                            m--;
                    } else if (sum < remain) {
                        l++;
                    } else {
                        m--;
                    }
                }
            }
        }
        return results;
    }
};