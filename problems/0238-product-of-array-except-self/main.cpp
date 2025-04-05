#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums as nums and prefix
        // postfix as postfix and answer
        int n = nums.size();
        vector<int> postfix(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                postfix[i] = nums[i];
                continue;
            }
            postfix[i] = nums[i] * postfix[i + 1];
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                nums[i] = nums[i];
                continue;
            }
            nums[i] = nums[i] * nums[i - 1];
        }
        for (int i = 0; i < n; i++) {
            postfix[i] = 1;
            if (i > 0) {
                postfix[i] *= nums[i - 1];
            }
            if (i <= n - 2) {
                postfix[i] *= postfix[i + 1];
            }
        }
        return postfix;
    }
};