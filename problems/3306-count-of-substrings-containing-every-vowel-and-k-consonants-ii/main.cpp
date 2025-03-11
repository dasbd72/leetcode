#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long countOfSubstrings(string word, int k) {
        long long cnt = 0;
        int freq[6] = {};
        int lptr = 0, id, lextra = 0;
        auto check = [&]() {
            // Checks if at least one vowels each
            return freq[0] == k && freq[1] && freq[2] && freq[3] && freq[4] && freq[5];
        };
        for (int rptr = 0; rptr < word.length(); rptr++) {
            id = ctoid(word[rptr]);
            freq[id]++;
            while (freq[0] > k) {
                id = ctoid(word[lptr]);
                freq[id]--;
                lptr++;
                lextra = 0;
            }
            while (check() && lptr < rptr && ctoid(word[lptr]) && freq[ctoid(word[lptr])] > 1) {
                id = ctoid(word[lptr]);
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
    int ctoid(char c) {
        if (c == 'a')
            return 1;
        if (c == 'e')
            return 2;
        if (c == 'i')
            return 3;
        if (c == 'o')
            return 4;
        if (c == 'u')
            return 5;
        return 0;
    }
};