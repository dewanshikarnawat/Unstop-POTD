//Problem: Emergency Broadcast Range
//Topic: Modified Dijkstra (Priority Queue) / Multi-Source Shortest Path
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> best(n + 1, -1);

    priority_queue<pair<long long, int>> pq;

    for (int i = 0; i < k; i++) {
        int t;
        long long p;
        cin >> t >> p;

        if (p > best[t]) {
            best[t] = p;
            pq.push({p, t});
        }
    }

    while (!pq.empty()) {
        long long power = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (power != best[u])
            continue;

        if (power == 0)
            continue;

        for (int v : adj[u]) {
            long long newPower = power - 1;

            if (newPower > best[v]) {
                best[v] = newPower;
                pq.push({newPower, v});
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (best[i] >= 0)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
