#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string smallestNumber(string pattern) {
        int i, j, k;
        string num, sub;
        for (i = 0; i < pattern.size() + 1; i++) {
            num += char(i + '1');
        }
        for (i = 0; i < pattern.size(); i++) {
            j = i;
            while (pattern[j] == 'D') {
                j++;
            }
            if (j - i > 0) {
                sub = num.substr(i, j - i + 1);
                reverse(sub.begin(), sub.end());
                for (k = 0; k < sub.size(); k++) {
                    num[i + k] = sub[k];
                }
            }
            i = j;
        }
        return num;
    }
};