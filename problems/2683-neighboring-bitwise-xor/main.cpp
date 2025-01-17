#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool doesValidArrayExist(vector<int>& derived) {
        int base = 0;
        for (int i = 0; i < (int)derived.size(); i++) {
            base ^= derived[i];
        }
        return base == 0;
    }
};