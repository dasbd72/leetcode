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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while (curr->next != nullptr) {
            if (st.find(curr->next->val) != st.end()) {
                // Found
                curr->next = nextAndDel(curr->next);
            } else {
                curr = curr->next;
            }
        }
        return nextAndDel(dummy);
    }

   private:
    inline ListNode* nextAndDel(ListNode* node) {
        ListNode* to_del = node;
        node = node->next;
        delete to_del;
        return node;
    }
};

auto _ = []() noexcept {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0; }();
