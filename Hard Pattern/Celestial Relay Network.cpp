//Problem: Celestial Relay Network
//Topic: Dynamic Programming (DP) + Bitmasking
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<vector<long long>> cost(N + 1, vector<long long>(N + 1));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> cost[i][j];
        }
    }

    int FULL = 1 << N;
    const long long INF = LLONG_MAX / 4;

    vector<vector<long long>> dp(FULL, vector<long long>(N + 1, INF));

    // Initial transitions from node 0
    for (int i = 1; i <= N; i++) {
        dp[1 << (i - 1)][i] = cost[0][i];
    }

    for (int mask = 0; mask < FULL; mask++) {
        for (int last = 1; last <= N; last++) {
            if (dp[mask][last] == INF)
                continue;

            for (int nxt = 1; nxt <= N; nxt++) {
                if (!(mask & (1 << (nxt - 1)))) {
                    int newMask = mask | (1 << (nxt - 1));
                    dp[newMask][nxt] = min(dp[newMask][nxt],
                                           dp[mask][last] + cost[last][nxt]);
                }
            }
        }
    }

    long long ans = INF;
    int allVisited = FULL - 1;

    for (int last = 1; last <= N; last++) {
        ans = min(ans, dp[allVisited][last] + cost[last][0]);
    }

    cout << ans << endl;

    return 0;
}
