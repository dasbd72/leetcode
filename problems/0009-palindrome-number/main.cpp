#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long long orig = x;
        long long rev = 0;
        while(x) {
            rev *= 10;
            rev += x % 10;
            x /= 10;
        }
        return rev == orig;
    }
};