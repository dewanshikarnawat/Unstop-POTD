//Problem: Secret Message Decoder
//Topic: Strings
//Pattern: Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string S;
    char C;

    cin >> S;
    cin >> C;

    int count = 0;

    for (char ch : S) {
        if (ch == C)
            count++;
    }

    cout << count;  
    return 0;
}
