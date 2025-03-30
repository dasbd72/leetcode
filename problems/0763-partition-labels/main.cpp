#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> start(26, s.length());
        vector<int> end(26, -1);
        for (int i = 0; i < s.length(); i++) {
            int j = s[i] - 'a';
            start[j] = min(i, start[j]);
            end[j] = i;
        }
        vector<int> answer;
        // record left of current partition
        // updates right to max pos of all char
        int l = 0, r = -1;
        for (int i = 0; i < s.length(); i++) {
            r = max(r, end[s[i] - 'a']);
            if (i == r) {
                answer.emplace_back(r - l + 1);
                l = i + 1;
            }
        }
        return answer;
    }
};