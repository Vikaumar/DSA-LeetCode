/*
LeetCode 756 - Pyramid Transition Matrix

Approach:
- Use DFS + Backtracking to build the pyramid from bottom to top.
- Use a map to store allowed transitions.
- Use memoization to avoid recomputation of the same states.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Map: "AB" -> list of characters that can be placed on top
    unordered_map<string, vector<char>> transitions;

    // Memoization to store already processed bottoms
    unordered_map<string, bool> memo;

    // DFS to check if pyramid can be built from current bottom
    bool dfs(const string &bottom) {
        // Base case: reached the top
        if (bottom.size() == 1)
            return true;

        // If already computed, return stored result
        if (memo.count(bottom))
            return memo[bottom];

        vector<string> nextRows;
        buildNextRows(bottom, 0, "", nextRows);

        // Try all possible next rows
        for (const string &row : nextRows) {
            if (dfs(row))
                return memo[bottom] = true;
        }

        return memo[bottom] = false;
    }

    // Build all possible next rows from current bottom
    void buildNextRows(const string &bottom, int index,
                       string current, vector<string> &rows) {
        // Completed one possible row
        if (index == bottom.size() - 1) {
            rows.push_back(current);
            return;
        }

        string key = bottom.substr(index, 2);

        // No valid transition
        if (transitions.find(key) == transitions.end())
            return;

        // Try all allowed characters
        for (char ch : transitions[key]) {
            buildNextRows(bottom, index + 1, current + ch, rows);
        }
    }

public:
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        // Build transition map
        for (const string &s : allowed) {
            transitions[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom);
    }
};
