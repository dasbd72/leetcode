#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto &c : s) {
            char par_map = getParMap(c);
            if (par_map == 0) {
                stk.push(c);
                continue;
            }
            if (!stk.empty() && stk.top() == par_map) {
                stk.pop();
                continue;
            }
            return false;
        }
        if (!stk.empty())
            return false;
        return true;
    }

   private:
    char getParMap(char c) {
        switch (c) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return '\0';
        }
    }
};
