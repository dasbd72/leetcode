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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            curr->next = new ListNode(gcd(curr->val, next->val), next);
            curr = next;
        }
        return head;
    }

   private:
    ListNode* nextAndDel(ListNode* node) {
        ListNode* to_del = node;
        node = node->next;
        delete to_del;
        return node;
    }

    int gcd(int x, int y) {
        if (y > x) {
            return gcd(y, x);
        }
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }
};

auto _ = []() noexcept {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0; }();
