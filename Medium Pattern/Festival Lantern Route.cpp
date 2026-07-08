//Problem: Select the maximum number of checkpoints such that the distance between every pair of consecutive selected checkpoints is at least D.
//Topic: Greedy + Sorting + Arrays
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    long long D;
    cin >> N >> D;

    vector<long long> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int count = 1;
    long long last = a[0];

    for (int i = 1; i < N; i++) {
        if (a[i] - last >= D) {
            count++;
            last = a[i];
        }
    }

    cout << count;

    return 0;  
}
