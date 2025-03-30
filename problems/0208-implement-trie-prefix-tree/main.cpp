#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        bool is_word;
        array<Node*, 26> children;
        Node() {
            is_word = false;
            children.fill(nullptr);
        }
    };

   public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (const auto& c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_word = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (const auto& c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->is_word;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (const auto& c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */