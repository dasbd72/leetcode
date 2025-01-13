#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumLength(string s) {
        int mpos[26] = {};
        int minlen = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            mpos[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            int freq = mpos[i];
            // // Version 1 with modular
            // if (freq == 0) {
            //     continue;
            // }
            // minlen += (mpos[i] % 2 == 0 ? 2 : 1);
            // Version 2 with subtraction
            while (freq > 2) {
                freq -= 2;
            }
            minlen += freq;
        }
        return minlen;
    }
};