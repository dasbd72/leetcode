#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        vector<char> _chars;
        char prev = chars[0];
        int cnt = 1;
        auto step = [&]() {
            _chars.push_back(prev);
            if (cnt > 1) {
                stack<char> stk;
                while (cnt) {
                    stk.push(cnt % 10 + '0');
                    cnt /= 10;
                }
                while (stk.size()) {
                    _chars.push_back(stk.top());
                    stk.pop();
                }
            }
            cnt = 0;
        };
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] != prev) {
                step();
                prev = chars[i];
            }
            cnt++;
        }
        step();
        chars = _chars;
        return chars.size();
    }
};