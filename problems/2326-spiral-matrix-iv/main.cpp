#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        ListNode *curr = head;
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int r = 0, c = 0, d = 0;
        while (true) {
            mat[r][c] = curr->val;
            curr = curr->next;
            if (curr == nullptr)
                break;
            r += dr[d], c += dc[d];
            if (!(r >= 0 && r < m && c >= 0 && c < n) || mat[r][c] != -1) {
                // Rollback
                r -= dr[d], c -= dc[d];
                // Try next direction
                d = (d + 1) % 4;
                r += dr[d], c += dc[d];
            }
        }
        return mat;
    }

   private:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
};

auto _ = []() noexcept {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0; }();
