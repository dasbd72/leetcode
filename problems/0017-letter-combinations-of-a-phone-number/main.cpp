#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>();
        }

        // Use swapping pointer of vectors to avoid copying
        unique_ptr<vector<string>> result_ptr = make_unique<vector<string>>(vector<string>(1, ""));
        for (auto &c : digits) {
            unique_ptr<vector<string>> prev_ptr = move(result_ptr);
            result_ptr = make_unique<vector<string>>();
            for (auto str : *prev_ptr) {
                for (auto en : digits_mapping[c]) {
                    result_ptr->push_back(str + en);
                }
            }
        }
        return *result_ptr;
    }

   private:
    map<char, vector<char>> digits_mapping = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
};
