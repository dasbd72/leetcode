#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = nullptr, *l3head;
        int c = 0;
        while (l1 && l2) {
            if (l3 == nullptr) {
                l3head = l3 = new ListNode;
            } else {
                l3 = l3->next = new ListNode;
            }
            l3->val = l1->val + l2->val + c;
            c = l3->val / 10;
            l3->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            l3 = l3->next = new ListNode;
            l3->val = l1->val + c;
            c = l3->val / 10;
            l3->val %= 10;
            l1 = l1->next;
        }
        while (l2) {
            l3 = l3->next = new ListNode;
            l3->val = l2->val + c;
            c = l3->val / 10;
            l3->val %= 10;
            l2 = l2->next;
        }
        if (c != 0) {
            l3 = l3->next = new ListNode;
            l3->val = c;
            c = l3->val / 10;
            l3->val %= 10;
        }
        return l3head;
    }
};