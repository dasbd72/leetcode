#include <bits/stdc++.h>
using namespace std;

struct NodeV0 {
    int l;
    int r;
    int val;
    NodeV0() {}
    NodeV0(int i, int val) : l(i), r(i), val(val) {}
    NodeV0(int l, int r, int val) : l(l), r(r), val(val) {}
    NodeV0 add(NodeV0 rval) {
        return NodeV0(min(l, rval.l), max(r, rval.r), val ^ rval.val);
    }
};

class SegmentTreeV0 {
   public:
    size_t depth;           // depth >= 1
    vector<NodeV0> buffer;  // 1-based buffer

    SegmentTreeV0() {}
    void build(vector<int>& arr) {
        depth = ceil(log2(arr.size())) + 1;
        buffer = vector<NodeV0>(1 << depth, NodeV0());
        // Fill leaf
        int offset = 1 << (depth - 1);
        for (int i = 0; i < (int)arr.size(); i++) {
            buffer[offset + i] = NodeV0(i, arr[i]);
        }
        for (int i = (int)arr.size(); i < (1 << (depth - 1)); i++) {
            buffer[offset + i] = NodeV0(i, 0);
        }
        // Bottom up building
        for (int i = offset - 1; i >= 1; i--) {
            buffer[i] = buffer[i * 2].add(buffer[i * 2 + 1]);
        }
    }

    int query(int l, int r) {
        return recursive_query(1, l, r);
    }

    int recursive_query(int i, int l, int r) {
        l = max(l, buffer[i].l);
        r = min(r, buffer[i].r);
        if (l == buffer[i].l && r == buffer[i].r) {
            // Matched
            return buffer[i].val;
        }
        int lval = 0;
        int rval = 0;
        if (l <= buffer[i * 2].r)
            lval = recursive_query(i * 2, l, r);
        if (r >= buffer[i * 2 + 1].l)
            rval = recursive_query(i * 2 + 1, l, r);
        return lval ^ rval;
    }
};

/*
    Builds the segment tree in a naive method
 */
class SolutionV0 {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTreeV0 segment_tree;
        segment_tree.build(arr);
        vector<int> result(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            result[i] = segment_tree.query(queries[i][0], queries[i][1]);
        }
        return result;
    }
};

class SegmentTreeV1 {
   public:
    size_t depth;        // depth >= 1
    vector<int> buffer;  // 1-based buffer

    SegmentTreeV1() {}
    void build(vector<int>& arr) {
        depth = ceil(log2(arr.size())) + 1;
        buffer = vector<int>(1 << depth, 0);
        // Fill leaf
        int offset = 1 << (depth - 1);
        for (int i = 0; i < (int)arr.size(); i++) {
            buffer[offset + i] = arr[i];
        }
        for (int i = (int)arr.size(); i < (1 << (depth - 1)); i++) {
            buffer[offset + i] = 0;
        }
        // Bottom up building
        for (int i = offset - 1; i >= 1; i--) {
            buffer[i] = buffer[i * 2] ^ buffer[i * 2 + 1];
        }
    }

    int query(int l, int r) {
        return recursive_query(1, 1, l, r);
    }

    int recursive_query(int i, int d, int l, int r) {
        int offset = 1 << (d - 1);
        int range = 1 << (depth - d);
        int il = (i - offset) * range;
        int ir = il + range - 1;
        if (r < il || l > ir)
            return 0;
        if (max(l, il) == il && min(r, ir) == ir) {
            // Matched
            return buffer[i];
        }
        return recursive_query(i * 2, d + 1, l, r) ^ recursive_query(i * 2 + 1, d + 1, l, r);
    }
};

/*
    Builds the segment tree in a mathematic method
 */
class SolutionV1 {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTreeV1 segment_tree;
        segment_tree.build(arr);
        vector<int> result(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            result[i] = segment_tree.query(queries[i][0], queries[i][1]);
        }
        return result;
    }
};

/*
    The prefix sum method.
 */
class Solution {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size() + 1);
        prefix[0] = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        vector<int> result(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            result[i] = prefix[queries[i][1] + 1] ^ prefix[queries[i][0]];
        }
        return result;
    }
};

auto _ = []() noexcept {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0; }();
