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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        auto append_list1 = [&]() {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        };
        auto append_list2 = [&]() {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        };
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                append_list1();
            } else {
                append_list2();
            }
        }
        while (list1 != nullptr) {
            append_list1();
        }
        while (list2 != nullptr) {
            append_list2();
        }
        curr->next = nullptr;
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