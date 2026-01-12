// =======================================================
// LeetCode 1266. Minimum Time Visiting All Points
// -------------------------------------------------------
// Approach: Greedy (Chebyshev Distance)
//
// Idea:
//   - Time between two points = max(dx, dy)
//   - Sum this for all consecutive points
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            time += max(dx, dy);
        }

        return time;
    }
};
