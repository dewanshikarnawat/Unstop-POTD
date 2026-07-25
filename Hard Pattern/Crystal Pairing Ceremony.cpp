//Problem: Crystal Pairing Ceremony
//Topic: Dynamic Programming
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m;
vector<vector<int>> a;
vector<long long> dp;

long long solve(int mask) {
    if (mask == (1 << m) - 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    // First unpaired guardian
    int i = 0;
    while (mask & (1 << i))
        i++;

    long long ans = 0;

    for (int j = i + 1; j < m; j++) {
        if (!(mask & (1 << j))) {
            ans = max(ans,
                      (long long)a[i][j] +
                      solve(mask | (1 << i) | (1 << j)));
        }
    }

    return dp[mask] = ans;
}

int main() {
    int N;
    cin >> N;

    m = 2 * N;

    a.assign(m, vector<int>(m));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    dp.assign(1 << m, -1);

    cout << solve(0);
    return 0;
}
