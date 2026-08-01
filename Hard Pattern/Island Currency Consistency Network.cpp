//Problem: Island Currency Consistency Network
//Topic: Weighted Disjoint Set Union (Weighted DSU / Union-Find with Weights)
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007LL;

struct DSU {
    vector<int> parent, sz;
    vector<long long> wt; // value(node) = wt[node] * value(parent)

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        wt.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    long long modpow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    long long inv(long long x) {
        return modpow(x, MOD - 2);
    }

    pair<int,long long> find(int x) {
        if (parent[x] == x)
            return {x, 1};

        auto p = find(parent[x]);

        wt[x] = wt[x] * p.second % MOD;
        parent[x] = p.first;

        return {parent[x], wt[x]};
    }

    bool unite(int u, int v, long long ratio) {
        auto fu = find(u);
        auto fv = find(v);

        int ru = fu.first;
        int rv = fv.first;

        long long wu = fu.second;
        long long wv = fv.second;

        if (ru == rv) {
            long long implied = wu * inv(wv) % MOD;
            return implied == ratio;
        }

        if (sz[ru] < sz[rv]) {
            parent[ru] = rv;
            wt[ru] = ratio * wv % MOD * inv(wu) % MOD;
            sz[rv] += sz[ru];
        } else {
            parent[rv] = ru;
            // value(rootV)/value(rootU)
            wt[rv] = wu * inv(ratio) % MOD * inv(wv) % MOD;
            sz[ru] += sz[rv];
        }

        return true;
    }

    bool connected(int u, int v) {
        return find(u).first == find(v).first;
    }

    long long query(int u, int v) {
        auto fu = find(u);
        auto fv = find(v);

        if (fu.first != fv.first)
            return -1;

        return fu.second * inv(fv.second) % MOD;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    DSU dsu(N);

    while (M--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            long long p, q;
            cin >> u >> v >> p >> q;

            long long ratio = p % MOD;
            ratio = ratio * dsu.inv(q % MOD) % MOD;

            if (dsu.unite(u, v, ratio))
                cout << "OK\n";
            else
                cout << "CONTRADICTION\n";
        }
        else {
            int u, v;
            cin >> u >> v;

            if (u == v) {
                cout << 1 << "\n";
                continue;
            }

            long long ans = dsu.query(u, v);

            if (ans == -1)
                cout << "UNKNOWN\n";
            else
                cout << ans << "\n";
        }
    }
    return 0;
}
