// LeetCode 2483. Minimum Penalty for a Shop
// Approach: Prefix Suffix Sums
// Time: O(n)
// Space: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string cus) {
        int n = cus.size();
        vector<int> pn(n + 1, 0), py(n + 1, 0);

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            pn[i + 1] = pn[i] + (cus[i] == 'N');
            py[j] = py[j + 1] + (cus[j] == 'Y');
        }

        int ans = 0, minPenalty = INT_MAX;

        for (int i = 0; i <= n; i++) {
            int penalty = pn[i] + py[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};
