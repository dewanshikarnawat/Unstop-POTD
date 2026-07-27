//Problem: Mirror Word Check
//Topic: Strings, Palindrome, Two Pointers
//Pattern: Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s;

    t = s;
    reverse(t.begin(), t.end());

    if (s == t)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
