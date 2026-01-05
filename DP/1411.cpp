// =======================================================
// LeetCode 1411. Number of Ways to Paint N x 3 Grid
// -------------------------------------------------------
// Approach:
//   Dynamic Programming with Pattern Counting
//   Each row can be painted in two patterns:
//     1) ABA  -> first and third same
//     2) ABC  -> all three different
//
// Transitions:
//   aba[i] = aba[i-1] * 3 + abc[i-1] * 2
//   abc[i] = aba[i-1] * 2 + abc[i-1] * 2
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long aba = 6; // patterns like A-B-A
        long long abc = 6; // patterns like A-B-C

        for (int i = 2; i <= n; i++) {
            long long newAba = (aba * 3 + abc * 2) % MOD;
            long long newAbc = (aba * 2 + abc * 2) % MOD;
            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};
