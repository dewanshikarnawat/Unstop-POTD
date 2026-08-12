//Problem: The Royal Decree Ledger
//Topic: Fenwick Tree (Binary Indexed Tree) + Coordinate Compression
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Fenwick {
    int n;
    vector<int> bit;

public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int total() {
        return query(n);
    }

    // Returns the smallest index whose prefix sum >= k
    int kth(int k) {
        int idx = 0;

        int pw = 1;
        while ((pw << 1) <= n)
            pw <<= 1;

        for (int step = pw; step > 0; step >>= 1) {
            int next = idx + step;

            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }
        }

        return idx + 1;
    }
};

struct Operation {
    string type;
    long long x;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    vector<Operation> ops;
    vector<long long> values;

    // Read all operations first
    for (int i = 0; i < Q; i++) {
        string type;
        long long x;

        cin >> type >> x;

        ops.push_back({type, x});

        // X is relevant for coordinate compression
        if (type != "POSITION")
            values.push_back(x);
    }

    // Coordinate compression
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    int n = values.size();

    Fenwick bit(n);

    // Presence of each compressed value
    vector<bool> present(n, false);

    for (auto &op : ops) {

        // --------------------------------------------------
        // ADD X
        // --------------------------------------------------
        if (op.type == "ADD") {

            int idx = lower_bound(values.begin(), values.end(), op.x)
                      - values.begin();

            if (!present[idx]) {
                present[idx] = true;
                bit.update(idx + 1, 1);
            }
        }

        // --------------------------------------------------
        // REMOVE X
        // --------------------------------------------------
        else if (op.type == "REMOVE") {

            int idx = lower_bound(values.begin(), values.end(), op.x)
                      - values.begin();

            if (present[idx]) {
                present[idx] = false;
                bit.update(idx + 1, -1);
            }
        }

        // --------------------------------------------------
        // EXISTS X
        // --------------------------------------------------
        else if (op.type == "EXISTS") {

            int idx = lower_bound(values.begin(), values.end(), op.x)
                      - values.begin();

            if (idx < n && values[idx] == op.x && present[idx])
                cout << "YES\n";
            else
                cout << "NO\n";
        }

        // --------------------------------------------------
        // BEFORE X
        // Largest value strictly smaller than X
        // --------------------------------------------------
        else if (op.type == "BEFORE") {

            // Number of compressed values < X
            int pos = lower_bound(values.begin(), values.end(), op.x)
                      - values.begin();

            int countBefore = bit.query(pos);

            if (countBefore == 0) {
                cout << "NONE\n";
            } else {
                int idx = bit.kth(countBefore);
                cout << values[idx - 1] << '\n';
            }
        }

        // --------------------------------------------------
        // AFTER X
        // Smallest value strictly greater than X
        // --------------------------------------------------
        else if (op.type == "AFTER") {

            // Number of values <= X
            int pos = upper_bound(values.begin(), values.end(), op.x)
                      - values.begin();

            int countUpToX = bit.query(pos);
            int total = bit.total();

            if (countUpToX == total) {
                cout << "NONE\n";
            } else {
                int idx = bit.kth(countUpToX + 1);
                cout << values[idx - 1] << '\n';
            }
        }

        // --------------------------------------------------
        // POSITION K
        // Kth smallest element
        // --------------------------------------------------
        else if (op.type == "POSITION") {

            int k = (int)op.x;
            int total = bit.total();

            if (k > total) {
                cout << "NONE\n";
            } else {
                int idx = bit.kth(k);
                cout << values[idx - 1] << '\n';
            }
        }
    }
    return 0;
}
