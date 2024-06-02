#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    map<int, char> table;
    Solution() {
        table[1] = 'I';
        table[5] = 'V';
        table[10] = 'X';
        table[50] = 'L';
        table[100] = 'C';
        table[500] = 'D';
        table[1000] = 'M';
    }
    int romanToInt(string s) {
        int num = 0;
        int i = 0;
        int len = s.size();
        while (i < len && s[i] == 'M') {
            num += 1000;
            i += 1;
        }
        for (int level = 100; level >= 1; level /= 10) {
            if (i + 1 < len && s[i] == table[level] && s[i + 1] == table[level * 10]) {
                num += level * 9;
                i += 2;
            }
            if (i < len && s[i] == table[level * 5]) {
                num += level * 5;
                i += 1;
            }
            if (i + 1 < len && s[i] == table[level] && s[i + 1] == table[level * 5]) {
                num += level * 4;
                i += 2;
            }
            while (i < len && s[i] == table[level]) {
                num += level;
                i += 1;
            }
        }
        return num;
    }
};