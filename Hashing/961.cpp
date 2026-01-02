// LeetCode 961. N-Repeated Element in Size 2N Array
// Approach: Hash Map Frequency Count
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
            if (freq[x] == n / 2) return x;
        }
        return -1;
    }
};
