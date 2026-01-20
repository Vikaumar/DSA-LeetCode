/*
    LeetCode 3314 - Minimum Bitwise Array

    Approach:
    For each nums[i] = b, find the minimum x such that:
        (x | (x + 1)) == b

    Observations:
    - (x | (x + 1)) is always odd
    - So if b is even (or b == 0), no solution exists -> answer = -1
    - Brute force from x = 0 to b to find the smallest valid x

    Time Complexity: O(n * b) in worst case (brute force)
    Space Complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int b = nums[i];

            // If b is even, no x can satisfy (x | (x+1)) == b
            if (b % 2 == 0) continue;

            for (int x = 0; x <= b; x++) {
                if ( (x | (x + 1)) == b ) {
                    ans[i] = x;
                    break;
                }
            }
        }
        return ans;
    }
};
