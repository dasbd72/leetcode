#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int diff = start ^ goal;
        int lb;
        while (lb = lowbit(diff)) {
            diff &= ~lb;
            cnt++;
        }
        return cnt;
    }

   private:
    int lowbit(int x) {
        return x & -x;
    }
};