//Problem: The Bridge Crossing Monitor
//Topic: Queue (FIFO - First In, First Out)
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int main() {
    int N;
    cin >> N;

    queue<long long> q;

    while (N--) {
        string op;
        cin >> op;

        if (op == "ENTER") {
            long long x;
            cin >> x;
            q.push(x);
        } else { // EXIT
            if (!q.empty())
                q.pop();
        }
    }

    if (q.empty())
        cout << "EMPTY";
    else
        cout << q.front();
    return 0;
}
