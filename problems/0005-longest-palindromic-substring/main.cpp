#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int start = 0;
        int len = 1;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]; j++) {
                if (j * 2 + 1 > len)
                    start = i - j, len = j * 2 + 1;
            }
            for (int j = 0; i - j >= 0 && i + j + 1 < s.length() && s[i - j] == s[i + j + 1]; j++) {
                if ((j + 1) * 2 > len)
                    start = i - j, len = (j + 1) * 2;
            }
        }

        return s.substr(start, len);
    }
};