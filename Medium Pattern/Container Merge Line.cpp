//Problem: Container Merge Line
//Topic: Stack + Simulation
//Pattern: Medium

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

    vector<long long> st;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        st.push_back(x);

        // Merge while the top two containers are equal
        while (st.size() >= 2) {
            int sz = st.size();

            if (st[sz - 1] != st[sz - 2])
                break;
long long merged = st[sz - 1] + st[sz - 2];

            st.pop_back();
            st.pop_back();

            st.push_back(merged);
        }
    }
    cout << st.size() << '\n';

    for (int i = 0; i < (int)st.size(); i++) {
        if (i > 0)
            cout << ' ';
        cout << st[i];
    }

    cout << '\n';
    return 0;
}
