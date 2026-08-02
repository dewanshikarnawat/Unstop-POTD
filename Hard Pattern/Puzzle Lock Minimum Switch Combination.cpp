//Problem: Puzzle Lock Minimum Switch Combination
//Topic: Bit manipulation
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int M;
    cin >> M;

    vector<int> mask(M);
    for (int i = 0; i < M; i++)
        cin >> mask[i];

    int S, T;
    cin >> S >> T;

    int need = S ^ T;
    int ans = M + 1;

    int total = 1 << M;

    for (int subset = 0; subset < total; subset++) {
        int xr = 0;
        int cnt = 0;

        for (int i = 0; i < M; i++) {
            if (subset & (1 << i)) {
                xr ^= mask[i];
                cnt++;
            }
        }

        if (xr == need)
            ans = min(ans, cnt);
    }

    if (ans == M + 1)
        cout << -1;
    else
        cout << ans;

    return 0;
}
