#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int freq[4] = {};
        int lptr = 0, id, lextra = 0;
        auto check = [&]() {
            return (freq[1] > 0 && freq[2] > 0 && freq[3] > 0);
        };
        auto ctoid = [](char c) {
            switch (c) {
                case 'a':
                    return 1;
                case 'b':
                    return 2;
                case 'c':
                    return 3;
                default:
                    return 0;
            }
        };
        for (int rptr = 0; rptr < s.length(); rptr++) {
            id = ctoid(s[rptr]);
            freq[id]++;
            while (check() && lptr < rptr && freq[ctoid(s[lptr])] > 1) {
                id = ctoid(s[lptr]);
                freq[id]--;
                lptr++;
                lextra++;
            }
            if (check()) {
                cnt += (1 + lextra);
            }
        }
        return cnt;
    }
};