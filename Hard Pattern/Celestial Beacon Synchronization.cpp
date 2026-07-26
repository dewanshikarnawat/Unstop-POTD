//Problem: Celestial Beacon Synchronization
//Topic: Mo's Algorithm + Range Query Processing + Square Root Decomposition + Frequency Counting (Hash Map/Array) + Arrays
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Query {
    int l, r, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    vector<Query> queries(Q);

    for (int i = 0; i < Q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    int block = sqrt(N);

    sort(queries.begin(), queries.end(), [&](Query a, Query b) {
        int blockA = a.l / block;
        int blockB = b.l / block;

        if (blockA != blockB)
            return blockA < blockB;

        return a.r < b.r;
    });

    unordered_map<int, long long> freq;
    vector<long long> ans(Q);

    int curL = 1, curR = 0;
    long long curAns = 0;

    auto add = [&](int idx) {
        long long f = freq[arr[idx]];
        curAns -= f * f;
        f++;
        freq[arr[idx]] = f;
        curAns += f * f;
    };

    auto remove = [&](int idx) {
        long long f = freq[arr[idx]];
        curAns -= f * f;
        f--;
        freq[arr[idx]] = f;
        curAns += f * f;
    };

    for (auto q : queries) {

        while (curL > q.l)
            add(--curL);

        while (curR < q.r)
            add(++curR);

        while (curL < q.l)
            remove(curL++);

        while (curR > q.r)
            remove(curR--);

        ans[q.idx] = curAns;
    }

    for (long long x : ans)
        cout << x << "\n";
    return 0;
}
