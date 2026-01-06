// =======================================================
// LeetCode 1161. Maximum Level Sum of a Binary Tree
// -------------------------------------------------------
// Approach:
//   Use Breadth-First Search (Level Order Traversal)
//   Compute sum of each level and track the level
//   having the maximum sum (1-indexed)
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

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
