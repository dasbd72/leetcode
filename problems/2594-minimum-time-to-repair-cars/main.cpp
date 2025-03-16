#include <bits/stdc++.h>
using namespace std;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (!check(R)) {
        return {R, R + 1};
    }
    if (check(L)) {
        return {L - 1, L};
    }
    while (L + 1 < R) {
        Ty M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    return {L, R};
}

class Solution {
   public:
    long long repairCars(vector<int>& ranks, int cars) {
        // Build frequency of ranks
        unordered_map<int, int> freq;
        for (int i = 0; i < ranks.size(); i++) {
            freq[ranks[i]] += 1;
        }
        // Check if time limit is valid
        auto check = [&](long long mins) {
            long long cnt = 0;  // Count of cars can be repaired
            for (auto [rank, repeat] : freq) {
                // r * n * n <= min
                // n = sqrt(min / r)
                cnt += (long long)sqrtl(mins / rank) * repeat;
            }
            return cnt >= cars;
        };
        // Get minimum maximum value of mins available in O(n)
        long long max_mins;
        // in O(1)
        max_mins = (long long)cars * cars * *min_element(ranks.begin(), ranks.end());
        // Further reduces in O(n)
        for (auto [rank, repeat] : freq) {
            long long part_cars = ceil((float)cars / repeat);
            long long mins = rank * part_cars * part_cars;
            max_mins = min(max_mins, mins);
        }
        // Get the binary search result
        auto [l, r] = binarySearch((long long)1, max_mins, check);
        return r;
    }
};