// =======================================================
// LeetCode 3453. Separate Squares I
// -------------------------------------------------------
// Approach: Binary Search on y-coordinate
//
// Idea:
//   - Binary search for the smallest y such that the area
//     below that horizontal line equals half the total area.
//   - For each square below the line, add the vertical slice
//     that lies below mid.
//
// Time Complexity: O(n * log C)  where C ≈ range of y
// Space Complexity: O(1)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long totalArea = 0;
        double hi = 0;
        for (auto &sq : squares) {
            long long l = sq[2];
            totalArea += (long long)l * l;
            hi = max(hi, (double)(sq[1] + l));
        }
        double lo = 0;
        double target = totalArea / 2.0;
        const double eps = 1e-5;

        while (hi - lo > eps) {
            double mid = (lo + hi) / 2.0;
            double below = 0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];
                if (y < mid) {
                    below += l * min(mid - y, l);
                }
            }

            if (below >= target) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};
