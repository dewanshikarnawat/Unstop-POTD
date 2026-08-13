//Problem: The Festive Smart-Light Grid
//Topic: Binary Search Tree (BST) + Two Pointers
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x != -1)
            a.push_back(x);
    }

    sort(a.begin(), a.end());

    // Find largest element < K
    int left = lower_bound(a.begin(), a.end(), K) - a.begin() - 1;

    // Find smallest element > K
    int right = upper_bound(a.begin(), a.end(), K) - a.begin();
    while (left >= 0 && right < a.size()) {
        int x = a[left];
        int y = a[right];

        int leftDiff = K - x;
        int rightDiff = y - K;

        if (leftDiff == rightDiff) {
            cout << x << " " << y << endl;
            return 0;
        }

        // Move the side having the larger difference
        if (leftDiff > rightDiff)
            left--;
        else
            right++;
    }

    cout << -1 << endl;
    return 0;
}
