#include <bits/stdc++.h>
using namespace std;

class Data {
   public:
    string str;
    int remain_left;   // Remaining left parenthesis we can place
    int remain_right;  // Remaining right parenthesis we can place

    Data(int n) : str(""), remain_left(n), remain_right(0) {
    }
    Data(string s, int l, int r) : str(s), remain_left(l), remain_right(r) {
    }
};

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ress;
        stack<Data> stk;
        stk.push(Data(n));
        while (!stk.empty()) {
            auto data = stk.top();
            stk.pop();
            // If no more remaining parenthesis to be placed, append to the answer vector
            if (data.remain_left == 0 && data.remain_right == 0) {
                ress.push_back(data.str);
                continue;
            }
            // For each step, put a left or a right parenthesis under constraint
            if (data.remain_left > 0) {
                stk.push(Data(data.str + "(", data.remain_left - 1, data.remain_right + 1));
            }
            if (data.remain_right > 0) {
                stk.push(Data(data.str + ")", data.remain_left, data.remain_right - 1));
            }
        }
        return ress;
    }
};