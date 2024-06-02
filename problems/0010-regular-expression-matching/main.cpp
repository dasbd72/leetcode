#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        return recursiveMatch(s, p, 0, 0);
    }

    bool recursiveMatch(string& s, string& p, int i, int j) {
        if (j == p.size() && i == s.size())
            return true;
        if (j == p.size())
            return false;
        if (j + 1 != p.size() && p[j + 1] == '*') {
            if (recursiveMatch(s, p, i, j + 2)) {
                // zero match
                return true;
            }
            for (int cnt = 0; i + cnt < s.size(); cnt++) {
                // cnt + 1 matches
                if (p[j] != '.' && p[j] != s[i + cnt])
                    return false;
                if (recursiveMatch(s, p, i + cnt + 1, j + 2))
                    return true;
            }
            return false;
        }
        if (i == s.size())
            return false;
        if (p[j] != '.' && p[j] != s[i])
            return false;
        return recursiveMatch(s, p, i + 1, j + 1);
    }
};