// LeetCode 1351. Count Negative Numbers in a Sorted Matrix
// Approach: Binary Search on each row
// Time Complexity: O(nlog m)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[i][mid] < 0)
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            cnt += (m - left);
        }

        return cnt;
    }
};
