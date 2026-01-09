// =======================================================
// LeetCode 865. Smallest Subtree with all the Deepest Nodes
// -------------------------------------------------------
// Approach: DFS + Height Comparison
//
// Idea:
//   - Recursively calculate depth of left & right subtrees
//   - If both depths are equal → current node is LCA
//   - Otherwise, go towards the deeper subtree
//
// Time Complexity: O(n)
// Space Complexity: O(h)   (recursion stack)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        if (L.second == R.second)
            return {root, L.second + 1};
        else if (L.second > R.second)
            return {L.first, L.second + 1};
        else
            return {R.first, R.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
