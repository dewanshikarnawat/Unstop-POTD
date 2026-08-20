//Problem: Riya's Congestion Watch on NH-7
//Topic: Segment Tree + Lazy Propagation + Binary Search on Segment Tree (Leftmost Position Query)
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<long long> tree, lazy;
    int n;

    void build(int node, int start, int end, vector<long long>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
     void push(int node) {
        if (lazy[node] != 0) {
            long long val = lazy[node];

            tree[2 * node] += val;
            tree[2 * node + 1] += val;

            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;

            lazy[node] = 0;
        }
    }
    void update(int node, int start, int end,
                int l, int r, long long val) {
        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            tree[node] += val;
            lazy[node] += val;
            return;
        }

        push(node);

        int mid = (start + end) / 2;

        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    long long queryMax(int node, int start, int end,
                       int l, int r) {
        if (r < start || end < l) return LLONG_MIN;

        if (l <= start && end <= r)
            return tree[node];

        push(node);

        int mid = (start + end) / 2;

        return max(
            queryMax(2 * node, start, mid, l, r),
            queryMax(2 * node + 1, mid + 1, end, l, r)
        );
    }

int findFirstGreater(int node, int start, int end,
                         int l, int r, long long x) {
        if (r < start || end < l || tree[node] <= x)
            return -1;

        if (start == end)
            return start;

        push(node);

        int mid = (start + end) / 2;

        int leftAns =
            findFirstGreater(2 * node, start, mid, l, r, x);

        if (leftAns != -1)
            return leftAns;

        return findFirstGreater(
            2 * node + 1,
            mid + 1,
            end,
            l,
            r,
            x
        );
    }

public:
    SegmentTree(vector<long long>& arr) {
        n = arr.size() - 1; // 1-indexed
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
        build(1, 1, n, arr);
    }

    void rangeAdd(int l, int r, long long val) {
        update(1, 1, n, l, r, val);
    }

    long long rangeMax(int l, int r) {
        return queryMax(1, 1, n, l, r);
    }

    int firstGreater(int l, int r, long long x) {
        return findFirstGreater(1, 1, n, l, r, x);
    }
    };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> arr(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int Q;
    cin >> Q;

    SegmentTree st(arr);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            long long v;
            cin >> l >> r >> v;
             st.rangeAdd(l, r, v);
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;

            cout << st.rangeMax(l, r) << '\n';
        }
        else {
            int l, r;
            long long x;
            cin >> l >> r >> x;

            cout << st.firstGreater(l, r, x) << '\n';
        }
    }
    return 0;
}
