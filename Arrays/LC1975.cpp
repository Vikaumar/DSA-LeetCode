// LeetCode 1975. Maximum Matrix Sum
// Approach: Greedy + Parity Observation
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                sum += abs(x);
                if (x < 0) negCount++;
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negCount % 2 == 1) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};
