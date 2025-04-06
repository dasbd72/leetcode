#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumPairRemoval(vector<int>& nums) {
        list<int> lst(nums.begin(), nums.end());
        int cnt = 0;
        auto check = [&] {
            int val = INT_MIN;
            auto curr = lst.begin();
            for (; curr != lst.end(); curr++) {
                if (*curr < val) {
                    return false;
                }
                val = *curr;
            }
            return true;
        };
        while (!check()) {
            int val = INT_MAX;
            auto save = lst.begin();
            auto prev = lst.begin();
            auto curr = next(lst.begin());
            for (; curr != lst.end(); curr++, prev++) {
                if (*curr + *prev < val) {
                    save = prev;
                    val = *curr + *prev;
                }
            }
            lst.insert(save, val);
            lst.erase(next(save));
            lst.erase(save);
            cnt++;
        }
        return cnt;
    }
};