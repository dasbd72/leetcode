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
    /* An space complexity O(k) version */
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while (true) {
            bool is_end = false;
            vector<ListNode*> vec;
            ListNode* curr2 = curr->next;
            for (int i = 0; i < k; i++) {
                if (curr2 == nullptr) {
                    is_end = true;
                    break;
                }
                vec.push_back(curr2);
                curr2 = curr2->next;
            }
            if (is_end)
                break;
            for (auto it = vec.rbegin(); it != vec.rend(); it++) {
                curr = curr->next = *it;
            }
            curr->next = curr2;
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