#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string ret;
        int interval = numRows * 2 - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i + j * interval < s.length(); j++) {
                int jint = j * interval;
                ret.push_back(s[i + jint]);
                if (!(i == 0 || i == numRows - 1) && interval - i + jint < s.length())
                    ret.push_back(s[interval - i + jint]);
            }
        }
        return ret;
    }
};