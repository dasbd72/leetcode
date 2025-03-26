#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size() * grid[0].size();
        int remainder = grid[0][0] % x;
        int postfix_sum = 0, prefix_sum = 0;
        int tmp, answer = 0x7fffffff;
        vector<int> buffer;
        for (const auto& row : grid) {
            for (const auto& val : row) {
                if (val % x != remainder) {
                    return -1;
                }
                buffer.emplace_back(val);
                postfix_sum += val;
            }
        }
        sort(buffer.begin(), buffer.end());
        for (int i = 0; i < n; i++) {
            // [0...i-1|i...n]
            // Compute total difference
            tmp = (i)*buffer[i] - prefix_sum + postfix_sum - (n - i) * buffer[i];
            // Divide difference by x
            tmp = tmp / x;
            // Update answer
            answer = min(answer, tmp);
            postfix_sum -= buffer[i];
            prefix_sum += buffer[i];
        }
        return answer;
    }
};