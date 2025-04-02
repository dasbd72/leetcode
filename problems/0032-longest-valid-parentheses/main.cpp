#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        // stack<int> stk;
        // vector<int> start(s.length(), -1);
        // int ans = 0;
        // for (int i = 0; i < s.length(); i++) {
        //     if (s[i] == '(') {
        //         stk.push(i);
        //     } else if (stk.size()) {
        //         start[i] = stk.top();
        //         stk.pop();
        //         if (start[i] - 1 >= 0 && start[start[i] - 1] != -1) {
        //             start[i] = start[start[i] - 1];
        //         }
        //         ans = max(ans, i - start[i] + 1);
        //     }
        // }

        // Cuts substring by stack
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i < s.length() && s[i] == ')' && stk.size() > 1 && s[stk.top()] == '(') {
                stk.pop();
                continue;
            }
            ans = max(ans, i - stk.top() - 1);
            stk.push(i);
        }
        return ans;
    }
};