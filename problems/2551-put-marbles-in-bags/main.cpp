#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long putMarbles(vector<int>& weights, int k) {
        // ~~Pick 2*k for min/max sum of cost including head and tail~~
        // ~~with possibility of repeat~~
        // Let cuts be 0,p1,p1+1,...,p(k-1),p(k-1)+1,n
        // only need to find distinct k-1 pivots
        // pick k-1 with min/max sum of cost
        int n = weights.size();
        // Let weight[0,n-1] be p
        for (int i = 0; i < n - 1; i++) {
            weights[i] = weights[i] + weights[i + 1];
        }
        // min_sum = sum(sorted_p[0,k-2])
        // max_sum = sum(sorted_p[n-k,n-2]) or sum(rev_sorted_p[0,k-2])
        // ans = max_sum - min_sum
        long long ans = 0;
        if (k > 1) {
            nth_element(weights.begin(), weights.begin() + k - 1, weights.end() - 1, less<>());
            for (int i = 0; i < k - 1; i++) {
                ans -= weights[i];
            }
            nth_element(weights.begin(), weights.begin() + k - 1, weights.end() - 1, greater<>());
            for (int i = 0; i < k - 1; i++) {
                ans += weights[i];
            }
        }
        return ans;
    }
};