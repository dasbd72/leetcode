#include <bits/stdc++.h>
using namespace std;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (check(L)) {
        return {L - 1, L};
    }
    if (!check(R)) {
        return {R, R + 1};
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
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        // Find pivot first
        // if pivot = 0 [0, n-1]
        // else [pivot, n-1][0, pivot-1]
        auto pivotCheck = [&](int pivot) {
            int r = len - 1 - pivot, l = (len - 1 - pivot - 1 + len) % len;
            return nums[0] <= nums[r] && nums[l] < nums[r];
        };
        auto [_, pivot] = binarySearch(0, len - 1, pivotCheck);
        // Find target in unrotated array
        auto check = [&](int pos) {
            int rotated_pos = (pos - pivot + len) % len;
            return target <= nums[rotated_pos];
        };
        auto [_, pos] = binarySearch(0, len - 1, check);
        int rotated_pos = (pos - pivot + len) % len;
        if (pos == len || nums[rotated_pos] != target) {
            return -1;
        }
        return rotated_pos;
    }
};