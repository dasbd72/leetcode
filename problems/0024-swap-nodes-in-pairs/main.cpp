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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while (curr->next != nullptr && curr->next->next != nullptr) {
            // a->b->c->d
            // a->c->d, b
            ListNode* n = curr->next;
            curr->next = n->next;
            // a->c->d, b->d
            n->next = curr->next->next;
            // a->c->b->d
            curr->next->next = n;
            curr = n;
        }
        return nextAndDel(dummy);
    }

   private:
    ListNode* nextAndDel(ListNode* node) {
        ListNode* to_del = node;
        node = node->next;
        delete to_del;
        return node;
    }
};