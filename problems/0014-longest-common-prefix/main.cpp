#include <bits/stdc++.h>
using namespace std;

// 4 ms
class SolutionV0 {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        vector<size_t> lengths(strs.size());
        transform(strs.begin(), strs.end(), lengths.begin(), [](const string& s) {
            return s.length();
        });
        size_t min_len = *min_element(lengths.begin(), lengths.end());
        for (int ic = 0; ic < min_len; ic++) {
            char c;
            c = strs[0][ic];
            for (auto& str : strs) {
                if (c != str[ic]) {
                    c = '\0';
                    break;
                }
            }
            if (c == '\0')
                break;
            else
                prefix.push_back(c);
        }
        return prefix;
    }
};

// 0 ms
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string prefix;
        string& first_str = strs[0];
        string& last_str = strs[strs.size() - 1];
        int min_len = min(first_str.length(), last_str.length());
        for (int i = 0; i < min_len; i++) {
            if (first_str[i] == last_str[i])
                prefix.push_back(first_str[i]);
            else
                break;
        }
        return prefix;
    }
};