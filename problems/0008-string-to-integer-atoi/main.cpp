#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        string s_max = "2147483647";
        string s_min = "-2147483648";

        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        };

        if (i == s.length()) {
            return 0;
        }

        bool is_negative = false;
        if (s[i] == '-') {
            is_negative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        if (i == s.length()) {
            return 0;
        }

        while (i < s.length() && s[i] == '0') {
            i++;
        }
        int start = i;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            i++;
        }
        int end = i;

        if (end - start <= 0) {
            return 0;
        }

        int val = 0;
        if (!is_negative) {
            val = s[start] - '0';
            for (int i = start + 1; i < end; i++) {
                if ((val == 214748364 && s[i] - '0' > 7) || val > 214748364) {
                    return 2147483647;
                }
                val *= 10;
                val += s[i] - '0';
            }
        } else {
            val -= s[start] - '0';
            for (int i = start + 1; i < end; i++) {
                if ((val == -214748364 && s[i] - '0' > 8) || val < -214748364) {
                    return -2147483648;
                }
                val *= 10;
                val -= s[i] - '0';
            }
        }

        return val;
    }
};