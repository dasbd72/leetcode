#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += odd(s, i);
            cnt += even(s, i);
        }
        return cnt;
    }
    int odd(string& s, int pos) {
        int i = 0, l, r;
        while (true) {
            l = pos - i, r = pos + i;
            if (l < 0 || r >= s.size()) {
                break;
            }
            if (s[l] != s[r]) {
                break;
            }
            i++;
        }
        return i;
    }
    int even(string& s, int pos) {
        int i = 0, l, r;
        while (true) {
            l = pos - i, r = pos + i + 1;
            if (l < 0 || r >= s.size()) {
                break;
            }
            if (s[l] != s[r]) {
                break;
            }
            i++;
        }
        return i;
    }
};