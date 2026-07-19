//Problem: Given a directed graph, find the minimum number of starting vertices needed so that every vertex becomes reachable through directed paths.
//Topic: Graphs → Strongly Connected Components (SCC) (Kosaraju's Algorithm / Tarjan's Algorithm)
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
vector<vector<int>> graph, revGraph;
vector<int> visited, comp;
stack<int> st;

void dfs1(int node) {
    visited[node] = 1;
    for (int nxt : graph[node]) {
        if (!visited[nxt])
            dfs1(nxt);
    }
    st.push(node);
}

void dfs2(int node, int id) {
    comp[node] = id;
    for (int nxt : revGraph[node]) {
        if (comp[nxt] == -1)
            dfs2(nxt, id);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    revGraph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }

    visited.assign(N + 1, 0);

    // First DFS (order)
    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            dfs1(i);
    }

    // Second DFS (SCCs)
    comp.assign(N + 1, -1);
    int sccCount = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (comp[node] == -1) {
            dfs2(node, sccCount);
            sccCount++;
        }
    }

    vector<int> indegree(sccCount, 0);

    // Build SCC DAG indegrees
    for (int u = 1; u <= N; u++) {
        for (int v : graph[u]) {
            if (comp[u] != comp[v]) {
                indegree[comp[v]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < sccCount; i++) {
        if (indegree[i] == 0)
            ans++;
    }

    cout << ans << "\n";  
    return 0;
}
