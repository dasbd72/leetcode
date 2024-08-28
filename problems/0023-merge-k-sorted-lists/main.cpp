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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;  // Stores the value and which list it comes from
        // Initialize, put head to heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                pq.push(make_tuple(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        // Pull the smallest into the new list and pull one new from its original list
        while (!pq.empty()) {
            auto [val, i] = pq.top();
            pq.pop();
            curr = curr->next = new ListNode(val);
            if (lists[i] != nullptr) {
                pq.push(make_tuple(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        // Delete dummy and return
        return nextAndDel(dummy);
    }

    ListNode* nextAndDel(ListNode* node) {
        ListNode* to_del = node;
        node = node->next;
        delete to_del;
        return node;
    }
};