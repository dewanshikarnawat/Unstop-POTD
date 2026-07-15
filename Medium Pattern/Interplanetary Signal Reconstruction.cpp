//Problem: Find the length of the Longest Increasing Subsequence (LIS) in the given array, where the selected elements are in increasing order but not necessarily contiguous.
//Topic: Dynamic Programming (Longest Increasing Subsequence), Binary Search.
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> tail;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        auto it = lower_bound(tail.begin(), tail.end(), x);

        if (it == tail.end())
            tail.push_back(x);
        else
            *it = x;
    }

    cout << tail.size();  
    return 0;
}
