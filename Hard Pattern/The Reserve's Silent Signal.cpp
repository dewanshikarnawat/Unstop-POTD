//Problem: The Reserve's Silent Signal
//Topic: Divide and Conquer → Closest Pair of Points
//Pattern: Hard

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    long long x, y;
};

long long dist(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;

    return dx * dx + dy * dy;
}

long long closestPair(vector<Point>& points, int left, int right) {
    // Only 1 point
    if (right - left <= 0)
        return LLONG_MAX;

    // Two points
    if (right - left == 1)
        return dist(points[left], points[right]);
int mid = (left + right) / 2;
    long long midX = points[mid].x;

    long long leftDist = closestPair(points, left, mid);
    long long rightDist = closestPair(points, mid + 1, right);

    long long d = min(leftDist, rightDist);

    // Build strip containing points close to dividing line
    vector<Point> strip;

    // Instead of using sqrt(d), compare squared x-distance
    for (int i = left; i <= right; i++) {
        long long dx = points[i].x - midX;

        if (dx * dx < d) {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
        if (a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    });

    // Compare only points that can possibly improve d
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size(); j++) {
            long long dy = strip[j].y - strip[i].y;

            if (dy * dy >= d)
                break;

            d = min(d, dist(strip[i], strip[j]));

            if (d == 0)
                return 0;
        }
    }

    return d;
    }

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Sort by x-coordinate
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    });

    cout << closestPair(points, 0, N - 1) << '\n';

    return 0;
}
