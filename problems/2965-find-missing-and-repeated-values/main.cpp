#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n;
        vector<int> ret(2);
        vector<char> nums;

        n = grid.size();
        nums = vector<char>(n * n + 1);
        ret = vector<int>(2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nums[grid[i][j]]++;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (nums[i] == 0) {
                ret[1] = i;
            } else if (nums[i] > 1) {
                ret[0] = i;
            }
        }
        return ret;
    }
};