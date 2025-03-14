#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
   public:
    struct _node {
        int val;
        int tag;
    };
    vector<_node> buf;
    int depth, size, right;
    SegmentTree(int n) {
        depth = ceil(log2(n));
        size = pow(2, depth + 1) - 1;
        buf = vector<_node>(size);
        right = pow(2, depth) - 1;
    }
    int left_child(int id) {
        return (id + 1) * 2 - 1;
    }
    int right_child(int id) {
        return (id + 1) * 2;
    }
    int get_val(int id) {
        return buf[id].val + buf[id].tag;
    }
    void pull(int id) {
        int lid = left_child(id), rid = right_child(id);
        buf[id].val = max(get_val(lid), get_val(rid));
    }
    void push(int id) {
        int lid = left_child(id), rid = right_child(id);
        buf[id].val += buf[id].tag;
        buf[lid].tag += buf[id].tag;
        buf[rid].tag += buf[id].tag;
        buf[id].tag = 0;
    }
    void modify(int ql, int qr, int val) {
        recursive_modify(0, 0, right, ql, qr, val);
    }
    void recursive_modify(int id, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) {
            return;
        }
        if (ql <= l && qr >= r) {
            buf[id].tag += val;
            return;
        }
        int m = l + (r - l) / 2;
        int lid = left_child(id), rid = right_child(id);
        push(id);
        recursive_modify(lid, l, m, ql, qr, val);
        recursive_modify(rid, m + 1, r, ql, qr, val);
        pull(id);
    }
};

class Solution {
   public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree st(n);
        // Build tree
        for (int i = 0; i < n; i++) {
            st.modify(i, i, nums[i]);
        }
        // Check step 0
        if (st.get_val(0) <= 0) {
            return 0;
        }
        for (int i = 0; i < queries.size(); i++) {
            st.modify(queries[i][0], queries[i][1], -queries[i][2]);
            if (st.get_val(0) <= 0) {
                return i + 1;
            }
        }
        return -1;
    }
};