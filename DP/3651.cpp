/*
    LeetCode 3651
    Minimum Cost Grid with Teleports

    Approach:
    - DP with teleport layers
    - dp[t][i][j]: minimum cost to reach (i, j) using at most t teleports
    - Use suffix minimum optimization for teleport transitions

    Time Complexity: O(k * m * n + k * maxValue)
    Space Complexity: O(k * m * n)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const long long INF = 1e18;

        int maxVal = 0;
        for (auto &row : grid)
            for (int v : row)
                maxVal = max(maxVal, v);

        vector<vector<vector<long long>>> dp(
            k + 1, vector<vector<long long>>(m, vector<long long>(n, INF))
        );

        // Base case: no teleport
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                long long best = INF;
                if (i > 0) best = min(best, dp[0][i - 1][j]);
                if (j > 0) best = min(best, dp[0][i][j - 1]);
                dp[0][i][j] = best + grid[i][j];
            }
        }

        // DP with teleports
        for (int t = 1; t <= k; t++) {
            vector<long long> bestVal(maxVal + 2, INF);

            // Minimum cost for each value using t-1 teleports
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    bestVal[grid[i][j]] = min(bestVal[grid[i][j]], dp[t - 1][i][j]);

            // Suffix minimum for teleport optimization
            for (int v = maxVal - 1; v >= 0; v--)
                bestVal[v] = min(bestVal[v], bestVal[v + 1]);

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    long long cur = dp[t - 1][i][j];          // no teleport
                    cur = min(cur, bestVal[grid[i][j]]);     // teleport

                    if (i > 0) cur = min(cur, dp[t][i - 1][j] + grid[i][j]);
                    if (j > 0) cur = min(cur, dp[t][i][j - 1] + grid[i][j]);

                    dp[t][i][j] = cur;
                }
            }
        }

        return (int)dp[k][m - 1][n - 1];
    }
};
