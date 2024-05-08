#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            if(ans > 214748364 || ans < -214748364)
                return 0;
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
};