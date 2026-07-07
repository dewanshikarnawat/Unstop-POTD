Topic: Dynamic Programming (DP)
Subtopic: 1D Dynamic Programming (House Robber / Maximum Sum of Non-Adjacent Elements)
Language: C++ (GCC 13.2.0)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> chambers(n);

    for (int i = 0; i < n; i++) {
        cin >> chambers[i];
    }

    if (n == 1) {
        cout << chambers[0];
        return 0;
    }

    long long prev2 = chambers[0];
    long long prev1 = max(chambers[0], chambers[1]);

    for (int i = 2; i < n; i++) {
        long long take = prev2 + chambers[i];
        long long notTake = prev1;
        long long curr = max(take, notTake);

        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;

    return 0;
}
   
