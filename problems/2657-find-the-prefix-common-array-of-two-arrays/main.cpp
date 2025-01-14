#include <bits/stdc++.h>
using namespace std;

class SolutionV1 {
   public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> cntA, cntB;
        vector<int> C;
        int cnt = 0;
        for (int i = 0; i < (int)A.size(); i++) {
            int a = A[i], b = B[i];
            if (a == b) {
                cnt++;
            } else {
                if (cntB[b] < cntA[b]) {
                    cnt++;
                }
                if (cntA[a] < cntB[a]) {
                    cnt++;
                }
            }
            C.push_back(cnt);
            cntA[a]++, cntB[b]++;
        }
        return C;
    }
};

/**
 * @brief Computation and memory optimized.
 *
 */
class Solution {
   public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // vector<int> C;
        int cnt = 0;
        long long bsA = 0, bsB = 0;
        for (int i = 0; i < A.size(); i++) {
            int a = A[i] - 1, b = B[i] - 1;
            if (a == b) {
                cnt++;
            } else {
                if ((bsB >> a) & 1) {
                    cnt++;
                }
                if ((bsA >> b) & 1) {
                    cnt++;
                }
            }
            bsA |= (long long)1 << a;
            bsB |= (long long)1 << b;
            // C.emplace_back(cnt);
            A[i] = cnt;
        }
        // return C;
        return A;
    }
};