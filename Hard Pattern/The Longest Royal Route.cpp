//Problem: Find the maximum distance (depth) from City 1 to any node in the given tree.
//Topic: Tree, Graph Traversal, BFS/DFS, Tree Depth (Level Order Traversal).
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 0;

    int ans = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans = max(ans, dist[node]);

        for (int nei : adj[node]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }

    cout << ans;
 
    return 0;
}
