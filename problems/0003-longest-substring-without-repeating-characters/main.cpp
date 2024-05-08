#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        queue<int> que;
        array<int, 256> pos;
        pos.fill(-1);

        for (int i = 0; i < s.length(); i++) {
            if (pos[s[i]] > -1) {
                while (i - pos[s[i]] <= que.size()) {
                    que.pop();
                }
            }
            que.push(s[i]);
            pos[s[i]] = i;
            ans = max(ans, (int)que.size());
        }
        return ans;
    }
};