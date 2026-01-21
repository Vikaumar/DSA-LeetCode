#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 3315 - Minimize Bitwise Array

 Approach:
 For each number b in nums, we want to find the smallest integer a
 such that (a | (a + 1)) == b.

 Observations:
 - If b == 2, no such integer exists, so return -1.
 - Otherwise, scan bits from left to right to find the first zero bit.
 - Flip the bit just before that zero to construct the smallest valid a.

 Bitwise trick:
 - Find the first position j where bit j is 0
 - Toggle bit (j - 1) using XOR

 Time Complexity:
 O(n * 32) ≈ O(n)

 Space Complexity:
 O(n)
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int b : nums) {
            if (b == 2) {
                ans.push_back(-1);
                continue;
            }

            int res = -1;
            for (int j = 1; j < 32; j++) {
                if (((b >> j) & 1) == 0) {
                    res = b ^ (1 << (j - 1));
                    break;
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};
