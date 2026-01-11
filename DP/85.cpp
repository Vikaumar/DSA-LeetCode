// =======================================================
// LeetCode 85. Maximal Rectangle
// -------------------------------------------------------
// Approach: Histogram + Monotonic Stack
//
// Idea:
//   - Convert each row into a histogram of heights
//   - For each histogram, compute largest rectangle area
//   - Track the maximum area across all rows
//
// Time Complexity: O(rows * cols)
// Space Complexity: O(cols)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);  // sentinel
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
