#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 1) {
            return find(nums1, nums2, n / 2);
        } else {
            return (
                       find(nums1, nums2, n / 2 - 1) +
                       find(nums1, nums2, n / 2)) /
                   2;
        }
    }

    double find(vector<int>& nums1, vector<int>& nums2, int k) {
        auto check = [&](int m1) {
            if (nums1.size() == 0)
                return 0;
            if (nums2.size() == 0)
                return 1;
            int m2 = k - m1 - 1;
            int left1, right1, left2, right2;
            if (m1 < 0) {
                left1 = -0x7fffffff;
            } else {
                left1 = nums1[m1];
            }
            if (m1 + 1 >= nums1.size()) {
                right1 = 0x7fffffff;
            } else {
                right1 = nums1[m1 + 1];
            }
            if (m2 < 0) {
                left2 = -0x7fffffff;
            } else {
                left2 = nums2[m2];
            }
            if (m2 + 1 >= nums2.size()) {
                right2 = 0x7fffffff;
            } else {
                right2 = nums2[m2 + 1];
            }
            if (left1 > right2) {
                return 0;
            }
            return 1;
        };

        int l = max(-1, int(k + 1 - nums2.size() - 1));
        int r = min(int(nums1.size()), k + 1);
        while (l + 1 < r) {
            int m1 = (l + r) / 2;
            if (check(m1)) {
                l = m1;
            } else {
                r = m1;
            }
        }

        int left1, left2;
        if (l < 0) {
            left1 = -0x7fffffff;
        } else {
            left1 = nums1[l];
        }
        if (k - l - 1 < 0) {
            left2 = -0x7fffffff;
        } else {
            left2 = nums2[k - l - 1];
        }
        return max(left1, left2);
    }
};