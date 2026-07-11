//Problem: The Archive Room
//Topic: Stack
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> st;

    while (N--) {
        string op;
        cin >> op;

        if (op == "ADD") {
            long long x;
            cin >> x;
            st.push_back(x);
        } else { // REMOVE
            if (!st.empty())
                st.pop_back();
        }
    }

    if (st.empty())
        cout << -1;
    else
        cout << st.back();

    return 0;
}
