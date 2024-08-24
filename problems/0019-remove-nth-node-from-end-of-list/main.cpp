#include <bits/stdc++.h>
using namespace std;

/* *
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

class SolutionV0 {
    /*
    Count and go. 0ms solution. Simple in memory access pattern, reason of the speed.
     */
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;
        int sz = this->count(head);

        for (int i = 1; i < sz - n + 1; i++) {
            curr = curr->next;
        }
        curr->next = nextAndDel(curr->next);
        return nextAndDel(dummy);
    }

   private:
    int count(ListNode *head) {
        int sz = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            sz++;
        }
        return sz;
    }

    ListNode *nextAndDel(ListNode *node) {
        ListNode *ret = node->next;
        delete node;
        return ret;
    }
};

class Solution {
    /*
    Use difference of pointers instead of counting once first. 4ms solution.
     */
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr1 = dummy;
        ListNode *curr2 = dummy;

        for (int i = 0; i < n; i++) {
            curr1 = curr1->next;
        }

        while (curr1->next != nullptr) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        curr2->next = nextAndDel(curr2->next);
        return nextAndDel(dummy);
    }

   private:
    ListNode *nextAndDel(ListNode *node) {
        ListNode *ret = node->next;
        delete node;
        return ret;
    }
};