#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int cnt = 0, end = 0;
        for (const auto& meeting : meetings) {
            if (meeting[0] > end + 1) {
                cnt += meeting[0] - (end + 1);
            }
            end = max(meeting[1], end);
        }
        cnt += max(0, days - end);
        return cnt;
    }
};