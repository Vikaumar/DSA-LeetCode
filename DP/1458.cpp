// =======================================================
// LeetCode 1458. Max Dot Product of Two Subsequences
// -------------------------------------------------------
// Approach: Dynamic Programming
//
// dp[i][j] = maximum dot product using
//            nums1[0..i-1] and nums2[0..j-1]
//            subsequences starting in the position i of nums1 and position j of nums2.
//
// Transitions:
//   - Take current pair
//   - Skip element from nums1
//   - Skip element from nums2
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        const int NEG_INF = -1e9;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int take = nums1[i - 1] * nums2[j - 1];
                take += max(0, dp[i - 1][j - 1]);

                dp[i][j] = max({
                    take,
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            }
        }

        return dp[n][m];
    }
};
