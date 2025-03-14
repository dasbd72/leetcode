#include <bits/stdc++.h>
using namespace std;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (check(R)) {
        return {R, R + 1};
    }
    if (!check(L)) {
        return {L - 1, L};
    }
    while (L + 1 < R) {
        Ty M = L + (R - L) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M;
        }
    }
    return {L, R};
}

class Solution {
   public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check = [&](int num) {
            if (num == 0) {
                return true;
            }
            long long cnt = 0;
            for (int i = 0; i < candies.size(); i++) {
                cnt += (candies[i] / num);
                if (cnt >= k)
                    return true;
            }
            return false;
        };
        auto [l, r] = binarySearch(0, *max_element(candies.begin(), candies.end()), check);
        return l;
    }
};