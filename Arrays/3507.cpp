#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 3507 - Minimum Pair Removal

 Problem:
 Given an array nums, repeatedly remove the adjacent pair with the
 minimum sum by replacing it with their sum.
 Continue until the array becomes non-decreasing.
 Return the number of operations required.

 Approach:
 - While the array is not non-decreasing:
     1. Find the adjacent pair with the minimum sum.
     2. Merge that pair into a single element (their sum).
     3. Count the operation.
 - Stop once the array is non-decreasing.

 This greedy approach works because merging the smallest adjacent
 pair minimizes disruption to the order of the array.

 Time Complexity:
 O(n^2)
 - Each operation scans the array → O(n)
 - Up to (n − 1) merge operations

 Space Complexity:
 O(1) extra space (in-place modifications)
*/

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int n = nums.size();
            int minSum = nums[0] + nums[1];
            int idx = 0;

            // Find adjacent pair with minimum sum
            for (int i = 0; i < n - 1; i++) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    idx = i;
                }
            }

            // Merge the chosen pair
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            operations++;
        }

        return operations;
    }

private:
    bool isNonDecreasing(const vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};
