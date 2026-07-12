//Problem: Find the Visitor ID with the highest frequency in the array, and if multiple IDs have the same frequency, return the smallest ID among them.
//Topic: Hash Map (unordered_map) + Frequency Counting + Arrays
//Pattern: Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int N;
    cin >> N;

    unordered_map<long long, int> freq;

    for (int i = 0; i < N; i++) {
        long long id;
        cin >> id;
        freq[id]++;
    }

    long long ansId = 0;
    int maxFreq = 0;

    for (auto &p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            ansId = p.first;
        } 
        else if (p.second == maxFreq && p.first < ansId) {
            ansId = p.first;
        }
    }

    cout << ansId << " " << maxFreq; 
    return 0;
}
