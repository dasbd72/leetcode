#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double y;
        y = myPow(x, n / 2);
        y *= y;
        if (n & 1) {
            y = n > 0 ? y * x : y / x;
        }
        return y;
    }
};