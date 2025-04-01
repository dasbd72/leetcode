#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int len = min(len1, len2); len > 0; len--) {
            if (!(len1 % len == 0 && len2 % len == 0)) {
                continue;
            }
            bool valid = true;
            string base = str1.substr(0, len);
            for (int i = 0; i < len1 && valid; i += len) {
                if (str1.substr(i, len) == base) {
                    continue;
                }
                valid = false;
            }
            for (int i = 0; i < len2 && valid; i += len) {
                if (str2.substr(i, len) == base) {
                    continue;
                }
                valid = false;
            }
            if (valid) {
                return base;
            }
        }
        return "";
    }
};