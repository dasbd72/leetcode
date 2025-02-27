#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

struct NodeEntry {
    Node* node;
    bool used;
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        set<int> vis;
        stack<Node*> stk;
        NodeEntry buf[101];
        for (int i = 1; i < 101; i++) {
            buf[i].node = new Node(i);
            buf[i].used = false;
        }

        vis.insert(node->val);
        stk.push(node);
        while (stk.size()) {
            Node* curr = stk.top();
            stk.pop();
            buf[curr->val].used = true;
            for (auto next : curr->neighbors) {
                if (vis.find(next->val) == vis.end()) {
                    vis.insert(next->val);
                    stk.push(next);
                }
                buf[curr->val].node->neighbors.push_back(buf[next->val].node);
            }
        }

        for (int i = 1; i < 101; i++) {
            if (buf[i].used == false) {
                delete buf[i].node;
            }
        }
        return buf[node->val].node;
    }
};