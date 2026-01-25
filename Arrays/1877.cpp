#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 1877 - Minimize Maximum Pair Sum in Array

 Problem:
 Given an integer array nums of even length, pair up the elements
 such that the maximum pair sum is minimized.
 Return that minimized maximum pair sum.

 Approach:
 - Sort the array.
 - Pair the smallest element with the largest, second smallest
   with second largest, and so on.
 - Track the maximum sum among all pairs.

 This greedy strategy ensures the largest possible sum is minimized.

 Time Complexity:
 O(n log n)  (sorting)

 Space Complexity:
 O(1) extra space (excluding sort overhead)
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }

        return ans;
    }
};
