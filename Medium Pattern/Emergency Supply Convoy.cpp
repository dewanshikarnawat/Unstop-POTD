//Problem: Emergency Supply Convoy
//Topic: Greedy + Sorting + Priority Queue (Min Heap)
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, long long>> jobs(N);

    for (int i = 0; i < N; i++) {
        int D;
        long long C;
        cin >> D >> C;

        jobs[i] = {D, C};
    }

    // Sort by deadline
    sort(jobs.begin(), jobs.end());

    // Min-heap: smallest crate request on top
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long total = 0;

    for (auto &job : jobs) {
        int deadline = job.first;
        long long crates = job.second;

        pq.push(crates);
        total += crates;

        // At most 'deadline' villages can be completed
        // by this deadline.
        if ((int)pq.size() > deadline) {
            total -= pq.top();
            pq.pop();
        }
    }

    cout << total << endl;
    return 0;
}
