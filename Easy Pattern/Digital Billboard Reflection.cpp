//Problem: Digital Billboard Reflection
//Topic: Arrays, 2D Arrays, Matrix Manipulation
//Pattern: Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> a(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = C - 1; j >= 0; j--) {
            cout << a[i][j];
            if (j > 0) cout << " ";
        }
        cout << "\n";
    }
  
    return 0;
}
