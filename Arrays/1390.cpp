// =======================================================
// LeetCode 1390. Four Divisors
// -------------------------------------------------------
// Approach:
//   Brute-force divisor enumeration up to sqrt(n)
//   - Count divisors for each number
//   - Sum divisors if and only if the count is exactly 4
//   - Stop early if divisor count exceeds 4
//
// Time Complexity: O(n * sqrt(max(nums)))
// Space Complexity: O(1)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums) {
            int divisorCount = 0;
            int divisorSum = 0;

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int d1 = d;
                    int d2 = x / d;

                    divisorCount++;
                    divisorSum += d1;

                    if (d1 != d2) {
                        divisorCount++;
                        divisorSum += d2;
                    }

                    if (divisorCount > 4) break;
                }
            }

            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }

        return totalSum;
    }
};
