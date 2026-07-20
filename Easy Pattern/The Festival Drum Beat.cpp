//Problem: Find the earliest time (LCM) after which two drums with different beat intervals will sound together again.
//Topic: Mathematics
//Pattern: Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
     int A, B;
    cin >> A >> B;

    long long lcm = 1LL * A * B / gcd(A, B);

    cout << lcm;
    
    return 0;
}
