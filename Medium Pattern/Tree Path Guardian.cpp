//Problem: Tree Path Guardian
//Topic: Tree + DFS + Monotonic Stack
//Pattern: Medium

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n + 1, -1);

    // prev[v] = previous candidate in the monotonic stack
    vector<int> prev(n + 1, 0);

    // top of the current root-to-node stack
    int top = 0;

    struct State {
        int v, parent;
        int oldTop;
        int oldPrev;
        bool exit;
    };

    vector<State> st;
    st.push_back({1, 0, 0, 0, false});

    while (!st.empty()) {
        State cur = st.back();
        st.pop_back();

        int v = cur.v;
        int p = cur.parent;

        if (cur.exit) {
            // Restore stack state before entering this node
            top = cur.oldTop;
            prev[v] = cur.oldPrev;
            continue;
        }

        int oldTop = top;
        int oldPrev = prev[v];

        // Remove ancestors whose strength is <= a[v]
        while (top != 0 && a[top] <= a[v]) {
            top = prev[top];
        }

        // The remaining top is the closest greater ancestor
        if (top != 0)
            ans[v] = top;

        // Add current node to stack
        prev[v] = top;
        top = v;

        // Restore when leaving this subtree
        st.push_back({v, p, oldTop, oldPrev, true});

        // Visit children
        for (int i = (int)adj[v].size() - 1; i >= 0; i--) {
            int u = adj[v][i];

            if (u == p)
                continue;

            st.push_back({u, v, 0, 0, false});
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
