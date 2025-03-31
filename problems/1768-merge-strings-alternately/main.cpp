#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        string ret(len1 + len2, '0');
        int l = 0, r = 0, i = 0;
        while (l < len1 && r < len2) {
            if (l < len1) {
                ret[i++] = word1[l++];
            }
            if (r < len2) {
                ret[i++] = word2[r++];
            }
        }
        while (l < len1) {
            ret[i++] = word1[l++];
        }
        while (r < len2) {
            ret[i++] = word2[r++];
        }
        return ret;
    }
};