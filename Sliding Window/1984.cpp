#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 1984 - Minimum Difference Between Highest and Lowest of K Scores

 Problem:
 Given an integer array nums and an integer k, pick any k elements
 such that the difference between the maximum and minimum elements
 is minimized. Return that minimum difference.

 Approach:
 - Sort the array.
 - Any group of k elements with minimum difference must be a
   contiguous subarray in the sorted order.
 - Slide a window of size k and compute:
       nums[i + k - 1] - nums[i]
 - Take the minimum over all such windows.

 Time Complexity:
 O(n log n)  (due to sorting)

 Space Complexity:
 O(1) extra space (excluding sort overhead)
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for (int i = 0; i + k <= n; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};
