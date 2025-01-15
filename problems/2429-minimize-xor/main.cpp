#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = countBit(num1);
        int cnt2 = countBit(num2);
        int idx = 0;
        if (cnt1 < cnt2) {
            while (cnt1 < cnt2) {
                if (((num1 >> idx) & 1) == 0) {
                    cnt1++;
                    num1 |= (1 << idx);
                }
                idx++;
            }
        } else if (cnt1 > cnt2) {
            while (cnt1 > cnt2) {
                if (((num1 >> idx) & 1) == 1) {
                    num1 &= ~(1 << idx);
                    cnt1--;
                }
                idx++;
            }
        }
        return num1;
    }

    int countBit(int num) {
        int cnt = 0;
        while (num) {
            if (num & 1) {
                cnt++;
            }
            num >>= 1;
        }
        return cnt;
    }
};