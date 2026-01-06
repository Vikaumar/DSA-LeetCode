// =======================================================
// LeetCode 1161. Maximum Level Sum of a Binary Tree
// -------------------------------------------------------
// Approach (Simple Explanation):
//   - Traverse the tree level by level using BFS
//   - For each level, calculate the sum of node values
//   - Keep track of the maximum sum seen so far
//   - Return the level number (1-indexed) having the maximum sum
//   - If multiple levels have the same sum, the earliest level is chosen
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, ansLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int sz = q.size();
            long long currSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                currSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                ansLevel = level;
            }

            level++;
        }

        return ansLevel;
    }
};
