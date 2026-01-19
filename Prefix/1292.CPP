#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 1292 - Maximum Side Length of a Square with Sum ≤ Threshold

 Approach:
 1. Build a 2D prefix sum array so that sum of any submatrix
    can be computed in O(1).
 2. Binary search on the side length of the square.
 3. For a given side length k, check if there exists at least
    one k x k square whose sum is ≤ threshold.

 The feasibility of a square size is monotonic, which makes
 binary search applicable.

 Time Complexity:
 O(m * n * log(min(m, n)))

 Space Complexity:
 O(m * n)
*/

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum matrix (1-indexed)
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        int left = 1, right = min(m, n);
        int ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (isValid(mid, pref, threshold, m, n)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

private:
    bool isValid(int k, vector<vector<int>>& pref,
                 int threshold, int m, int n) {

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                int sum = pref[i + k][j + k]
                        - pref[i][j + k]
                        - pref[i + k][j]
                        + pref[i][j];

                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }
};
