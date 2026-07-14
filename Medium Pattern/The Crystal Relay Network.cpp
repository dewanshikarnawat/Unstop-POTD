//Problem: Find the minimum total energy required to travel from the first tower to the last by making jumps, where each jump from i to j costs |Energy[i] - Energy[j]| × (j - i).
//Topic: Dynamic Programming (1D DP)
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> dp(n, LLONG_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long cost = dp[j] + abs(a[i] - a[j]) * 1LL * (i - j);
            dp[i] = min(dp[i], cost);
        }
    }

    cout << dp[n - 1];
    return 0;
}
