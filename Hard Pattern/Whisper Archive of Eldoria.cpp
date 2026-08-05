//Problem: Whisper Archive of Eldoria
//Topic: Trie
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Node {
    int child[26];
    int cnt;

    Node() {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            child[i] = -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Node> trie(1); // root

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int node = 0;
        for (char c : s) {
            int idx = c - 'a';

            if (trie[node].child[idx] == -1) {
                trie[node].child[idx] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[idx];
            trie[node].cnt++;
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string p;
        cin >> p;

        int node = 0;
        bool ok = true;

        for (char c : p) {
            int idx = c - 'a';

            if (trie[node].child[idx] == -1) {
                ok = false;
                break;
            }

            node = trie[node].child[idx];
        }

        if (!ok) {
            cout << 0 << "\n";
        } else {
            long long cnt = trie[node].cnt;
            cout << cnt * (cnt - 1) / 2 << "\n";
        }
    }

    return 0;
}
