#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool valid = true;
                if (i - 1 >= 0 && flowerbed[i - 1] == 1) {
                    valid = false;
                }
                if (i + 1 < flowerbed.size() && flowerbed[i + 1] == 1) {
                    valid = false;
                }
                if (valid) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};