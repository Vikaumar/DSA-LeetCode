#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 1200 - Minimum Absolute Difference

 Problem:
 Given an array of distinct integers, find all pairs of elements
 with the minimum absolute difference.
 Return the result in ascending order.

 Approach:
 - Sort the array.
 - The minimum absolute difference must occur between
   adjacent elements in the sorted array.
 - First pass: compute the minimum difference.
 - Second pass: collect all adjacent pairs that have
   this minimum difference.

 Time Complexity:
 O(n log n)  (sorting)

 Space Complexity:
 O(n) for the output
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 1; i < (int)arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
