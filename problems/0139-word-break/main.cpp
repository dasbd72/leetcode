#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                int start = i - wordDict[j].length();
                if (start < 0 || dp[start] == false) {
                    continue;
                }
                if (s.substr(start, wordDict[j].length()) == wordDict[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};