//Problem: Market Rank Tracker
//Topic: Fenwick Tree (BIT) + Coordinate Compression + Order Statistics
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

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    // Returns smallest index whose prefix sum >= k
    int kth(int k) {
        int idx = 0;

        int pw = 1;
        while ((pw << 1) <= n)
            pw <<= 1;

        for (; pw > 0; pw >>= 1) {
            int next = idx + pw;

            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }
        }

        return idx + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> values;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        values.push_back(a[i]);
    }

    int q;
    cin >> q;

    // Store queries first because update values are also needed
    // for coordinate compression.
    struct Query {
        char type;
        long long x;
        long long y;
    };

    vector<Query> queries;

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if (type == 'U') {
            long long idx, val;
            cin >> idx >> val;

            queries.push_back({type, idx, val});
            values.push_back(val);
        }
        else {
            long long x;
            cin >> x;

            queries.push_back({type, x, 0});
        }
    }

    // Coordinate compression
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    Fenwick fw(values.size());

    auto getIndex = [&](long long x) {
        return int(lower_bound(values.begin(), values.end(), x)
                   - values.begin()) + 1;
    };

    // Insert initial prices
    for (int i = 1; i <= n; i++) {
        fw.add(getIndex(a[i]), 1);
    }

    for (auto &query : queries) {

        if (query.type == 'U') {
            int i = query.x;
            long long newValue = query.y;

            // Remove old price
            fw.add(getIndex(a[i]), -1);

            // Add new price
            a[i] = newValue;
            fw.add(getIndex(a[i]), 1);
        }

        else if (query.type == 'C') {
            long long X = query.x;

            // Number of compressed values <= X
            int pos = upper_bound(values.begin(), values.end(), X)
                      - values.begin();

            cout << fw.sum(pos) << '\n';
        }

        else if (query.type == 'K') {
            int k = query.x;

            int pos = fw.kth(k);

            cout << values[pos - 1] << '\n';
        }
    }
    return 0;
}
