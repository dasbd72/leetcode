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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        // Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse right
        ListNode *left = head, *right = slow->next;
        slow->next = nullptr;
        right = reverse(right);
        // Left->right->...
        ListNode *curr = head, *tmp;
        left = left->next;
        while (true) {
            if (right == nullptr) {
                break;
            }
            tmp = right;
            right = right->next;
            curr = curr->next = tmp;
            if (left == nullptr) {
                break;
            }
            tmp = left;
            left = left->next;
            curr = curr->next = tmp;
        }
        curr->next = nullptr;
    }
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head, *next, *prev = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};