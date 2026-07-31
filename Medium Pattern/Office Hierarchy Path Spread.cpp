//Problem: Office Hierarchy Path Spread
//Topic: Tree DP + DFS (Postorder Traversal)
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<pair<int,ll>>> adj(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(N + 1), mn(N + 1), mx(N + 1), ans(N + 1);

    function<void(int,int)> dfs = [&](int u, int p) {
        mn[u] = mx[u] = dist[u];

        for (auto [v, w] : adj[u]) {
            if (v == p) continue;

            dist[v] = dist[u] + w;
            dfs(v, u);

            mn[u] = min(mn[u], mn[v]);
            mx[u] = max(mx[u], mx[v]);
        }

        ans[u] = mx[u] - mn[u];
    };

    dfs(1, 0);

    int Q;
    cin >> Q;

    while (Q--) {
        int v;
        cin >> v;
        cout << ans[v] << "\n";
    }
    return 0;
}
