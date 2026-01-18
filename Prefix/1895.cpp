#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 1895 - Largest Magic Square

 A k x k square is magic if:
 - All rows have the same sum
 - All columns have the same sum
 - Both diagonals have the same sum

 Approach:
 - Precompute prefix sums for rows, columns, and diagonals
 - Try all possible square sizes from large to small
 - For each square, check row sums, column sums, and diagonals
 - Return the largest valid size found

 Time Complexity:
 O(m * n * min(m, n))

 Space Complexity:
 O(m * n)
*/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    for (int r = 0; r < k && ok; r++) {
                        if (row[i + r][j + k] - row[i + r][j] != target)
                            ok = false;
                    }

                    for (int c = 0; c < k && ok; c++) {
                        if (col[i + k][j + c] - col[i][j + c] != target)
                            ok = false;
                    }

                    int d1 = diag1[i + k][j + k] - diag1[i][j];
                    int d2 = diag2[i + k][j] - diag2[i][j + k];

                    if (ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }

        return 1;
    }
};
