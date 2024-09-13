#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        bool st[26] = {};
        for (auto& c : allowed)
            st[c - 'a'] = true;
        for (auto& word : words)
            if (all_of(word.begin(), word.end(), [&st](char c) { return st[c - 'a']; }))
                cnt++;
        return cnt;
    }
};

auto _ = []() noexcept {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0; }();
