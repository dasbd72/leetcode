#include <bits/stdc++.h>
using namespace std;

class Solution {
    /*
    Question:
        Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
        Return the sum of the three integers.
        You may assume that each input would have exactly one solution.
    Solution:
        The two pointer method.
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    Notations:
        n = nums.size()
        j is the left pointer and k is the right pointer.
    */
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort to make use of the increasing property
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int min_diff = 1e9, ans = 0;
        for (int i = 0; i < len; i++) {
            // Skip for repeated first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    ans = sum;
                }
                if (sum - target < 0) {
                    // Smaller than target, pointer goes right
                    j++;
                } else {
                    // Larger than target, pointer goes left
                    k--;
                }
            }
        }
        return ans;
    }
};