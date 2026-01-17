#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 3047 - Largest Square Area

 Approach:
 For every pair of rectangles, compute their overlapping region.
 If they overlap, the largest square that can be formed inside the
 intersection has side = min(overlap width, overlap height).
 Track the maximum such square area.

 Time Complexity:
 O(n^2), where n is the number of rectangles.

 Space Complexity:
 O(1), excluding input storage.
*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                if (x1 < x2 && y1 < y2) {
                    long long side = min(x2 - x1, y2 - y1);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};
