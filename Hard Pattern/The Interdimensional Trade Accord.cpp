//Problem: The Interdimensional Trade Accord
//Topic: Graph + All-Pairs Shortest Path (APSP) + Floyd-Warshall Algorithm
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    const long long INF = 1e18;

    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));

    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= N; j++) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }   
    return 0;
}
