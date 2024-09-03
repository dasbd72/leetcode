#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getLucky(string s, int k) {
        string s1 = "0";
        for (auto c : s) {
            s1 += to_string(int(c - 'a' + 1));
        }
        while (k--) {
            int sum = 0;
            string tmp = "0";
            for (auto d : s1) {
                sum += d - '0';
            }
            s1 = to_string(sum);
        }
        return stoi(s1);
    }
};