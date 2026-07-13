//Problem: Find the top K highest package priorities and print them in the order they would be dispatched (highest to lowest).
//Topic: Heap (Priority Queue / Max Heap)
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    priority_queue<long long> pq;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < K; i++) {
        cout << pq.top();
        pq.pop();
        if (i != K - 1)
            cout << " ";
    }
    return 0;
}
