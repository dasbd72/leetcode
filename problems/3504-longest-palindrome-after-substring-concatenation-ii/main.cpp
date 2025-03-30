#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++, r--;
        }
        return true;
    }
    vector<int> startPalindrome(const string& s) {
        vector<int> p(s.length(), 1);
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + p[i]; j < s.length(); j++) {
                if (checkPalindrome(s, i, j)) {
                    p[i] = j - i + 1;
                }
            }
        }
        return p;
    }
    vector<int> endPalindrome(const string& s) {
        vector<int> p(s.length(), 1);
        for (int i = 0; i < s.length(); i++) {
            for (int j = i - p[i]; j >= 0; j--) {
                if (checkPalindrome(s, j, i)) {
                    p[i] = i - j + 1;
                }
            }
        }
        return p;
    }
    int dfs(const string& s, const string& t, vector<vector<int>>& dp, const vector<int>& p, const vector<int>& q, int i, int j) {
        if (i >= s.length() && j < 0) {
            return 0;
        }
        if (i >= s.length()) {
            return q[j];
        }
        if (j < 0) {
            return p[i];
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        if (s[i] != t[j]) {
            return dp[i][j] = max(p[i], q[j]);
        } else {
            return dp[i][j] = max(max(p[i], q[j]), 2 + dfs(s, t, dp, p, q, i + 1, j - 1));
        }
    }

   public:
    int longestPalindrome(string s, string t) {
        vector<int> p = startPalindrome(s);
        vector<int> q = endPalindrome(t);
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), 0));
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                length = max(length, dfs(s, t, dp, p, q, i, j));
            }
        }
        return length;
    }
};