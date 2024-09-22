#include <bits/stdc++.h>
using namespace std;

class SolutionV0 {
   public:
    string shortestPalindrome(string s) {
        string ans;
        string rev = string(s.rbegin(), s.rend()).substr(0, (s.length() + 1) / 2);
        vector<int> lps;
        generateLPS(s, lps);

        int offset = 0;
        for (int i = 0; i < (int)rev.size(); i++) {
            int j = i + offset;
            int k = offset;
            while (j < (int)rev.size() && k < (int)s.size()) {
                if (rev[j] != s[k]) {
                    offset = lps[k];
                    break;
                }
                j++, k++;
            }
            if (j == (int)rev.size()) {
                ans = rev + s.substr(k, s.length() - k);
                return ans;
            }
        }
        ans = rev.substr(0, rev.length() - 1) + s;
        return ans;
    }

    void generateLPS(string pattern, vector<int> &lps) {
        lps = vector<int>(pattern.length(), 0);
        int prev = 0, curr = 1;
        while (curr < (int)lps.size()) {
            if (pattern[curr] == pattern[prev]) {
                lps[curr] = prev + 1;
                curr++;
                prev++;
            } else if (prev == 0) {
                lps[curr] = 0;
                curr++;
            } else {
                prev = lps[prev - 1];
            }
        }
    }
};

class Solution {
   public:
    string shortestPalindrome(string s) {
        int n = kmp(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend() - n) + s;
    }

    int kmp(const string &text, const string &pattern) {
        string combi = pattern + "#" + text;
        vector<int> kmp(combi.length(), 0);
        int curr = 1, prev = 0;
        while (curr < combi.length()) {
            if (combi[curr] == combi[prev]) {
                prev++;
                kmp[curr] = prev;
                curr++;
            } else if (prev == 0) {
                kmp[curr] = 0;
                curr++;
            } else {
                prev = kmp[prev - 1];
            }
        }
        return kmp.back();
    }
};
