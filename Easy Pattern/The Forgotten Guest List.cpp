//Problem: Find the only registration ID that appears exactly once in the array, where every other registration ID appears exactly twice.
//Topic: Bit Manipulation (XOR)
//Pattern: Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        ans ^= x;
    }

    cout << ans;

    return 0;   
}
