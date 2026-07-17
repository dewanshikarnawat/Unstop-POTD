//Problem: The Dream Weaver's Resonance Loom
//Topic: Dynamic Programming
//Pattern: Medium

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

    vector<long long> p(N + 1);
    for (int i = 0; i <= N; i++)
        cin >> p[i];

    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] +
                                 dp[k + 1][j] +
                                 p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][N];
    return 0;
}
