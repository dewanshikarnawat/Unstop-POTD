//Problem: Tara's Expedition Logs
//Topic: Dynamic Programming (DP) + Sliding Window / Two Pointers + Prefix Sum
//Pattern: Medium

#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

long long countArrangements(int n, long long k, const vector<long long>& sightings) {
    // dp[i] = number of valid ways to split the first i elements
    vector<long long> dp(n + 1, 0);

    // prefix[i] = dp[0] + dp[1] + ... + dp[i]
    vector<long long> prefix(n + 1, 0);

    // Empty array has exactly one way
    dp[0] = 1;
    prefix[0] = 1;

    long long windowSum = 0;
    int left = 0;

    for (int i = 1; i <= n; i++) {
        // Add current element to the sliding window
        windowSum += sightings[i - 1];

        // Remove elements from the left while sum exceeds K
        while (left < i && windowSum > k) {
            windowSum -= sightings[left];
            left++;
        }

        /*
            The last segment can start at any index:

                left, left+1, ..., i-1

            So:

                dp[i] =
                    dp[left] + dp[left+1] + ... + dp[i-1]

            Using prefix sums:
                dp[i] = prefix[i-1] - prefix[left-1]
        */

        dp[i] = prefix[i - 1];

        if (left > 0) {
            dp[i] -= prefix[left - 1];
        }

        // Keep value in [0, MOD)
        dp[i] %= MOD;

        if (dp[i] < 0) {
            dp[i] += MOD;
        }

        // Update prefix sum
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    long long k;

    cin >> n >> k;

    vector<long long> sightings(n);

    for (int i = 0; i < n; i++) {
        cin >> sightings[i];
    }

    long long result = countArrangements(n, k, sightings);

    cout << result << endl;

    return 0;
}
