#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        string t;
        int l = 0;
        bool is_first = true;
        for (int r = 0; r < s.length() + 1; r++) {
            if (r == s.length() || s[r] == ' ') {
                if (r - l > 0) {
                    if (is_first) {
                        t = s.substr(l, r - l);
                        is_first = false;
                    } else {
                        t = s.substr(l, r - l) + " " + t;
                    }
                }
                l = r + 1;
            }
        }
        return t;
    }
};