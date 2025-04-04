#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
struct SharedData {
    int max_depth;
    int a_depth;
    TreeNode* target;
    SharedData() {
        max_depth = 0;
        target = nullptr;
    }
};
struct InputData {
    TreeNode* node;
    int depth;
    InputData(TreeNode* x, int y) {
        node = x;
        depth = y;
    }
};
struct OutputData {
    int subtree_depth;
    OutputData() { subtree_depth = 0; }
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return root;
        SharedData shared;
        InputData input(root, 0);
        OutputData output;
        dfs1(shared, input, output);
        shared.a_depth = shared.max_depth + 1;
        dfs2(shared, input, output);
        return shared.target;
    }
    void dfs1(SharedData& sh, InputData in, OutputData& out) {
        sh.max_depth = max(sh.max_depth, in.depth);
        if (in.node->left) {
            dfs1(sh, InputData(in.node->left, in.depth + 1), out);
        }
        if (in.node->right) {
            dfs1(sh, InputData(in.node->right, in.depth + 1), out);
        }
    }
    void dfs2(SharedData& sh, InputData in, OutputData& out) {
        OutputData left_out, right_out;

        out.subtree_depth = in.depth;
        if (in.node->left) {
            dfs2(sh, InputData(in.node->left, in.depth + 1), left_out);
            out.subtree_depth =
                max(left_out.subtree_depth, out.subtree_depth);
        }
        if (in.node->right) {
            dfs2(sh, InputData(in.node->right, in.depth + 1), right_out);
            out.subtree_depth =
                max(out.subtree_depth, right_out.subtree_depth);
        }

        if(!in.node->left && !in.node->right) {
            if(sh.max_depth == in.depth) {
                sh.target = in.node;
            }
        } else if ((in.node->left && left_out.subtree_depth == sh.max_depth) &&
            (in.node->right && right_out.subtree_depth == sh.max_depth)) {
            if(sh.a_depth > in.depth) {
                sh.a_depth = in.depth;
                sh.target = in.node;
            }
        }
    }
};
*/

class Solution {
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            int max_depth = dfs_max_depth(root);
            return dfs(root, max_depth, 0);
        }
        int dfs_max_depth(TreeNode* node) {
            if(!node) {
                return -1;
            }
            return max(dfs_max_depth(node->left), dfs_max_depth(node->right)) + 1;
        }
        TreeNode* dfs(TreeNode* node, int& max_depth, int depth) {
            if(!node) {
                return nullptr;
            }
            if(depth == max_depth) {
                return node;
            }
            TreeNode* left = dfs(node->left, max_depth, depth + 1);
            TreeNode* right = dfs(node->right, max_depth, depth + 1);
            if(left && right) {
                return node;
            }
            return left ? left : right;
        }
    };