#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 2975 - Maximum Square Area by Removing Fences From a Field

 We collect all pairwise distances (gaps) between
 horizontal lines (including boundaries at 1 and m)
 and vertical lines (including boundaries at 1 and n).
 The largest distance that appears in both sets is the side of the
 largest possible square.
 Return (side^2 % MOD) or -1 if no such square exists.
*/

class Solution {
public:
    static constexpr int MOD = 1000000007;

    int maximizeSquareArea(int m, int n,
                            vector<int>& hFences,
                            vector<int>& vFences) {
        // Helper: get all possible distances between fence pairs
        auto getGaps = [&](vector<int>& fences, int boundary) {
            fences.push_back(1);
            fences.push_back(boundary);
            sort(fences.begin(), fences.end());

            unordered_set<int> gaps;
            int sz = fences.size();
            for (int i = 0; i < sz; ++i) {
                for (int j = 0; j < i; ++j) {
                    gaps.insert(fences[i] - fences[j]);
                }
            }
            return gaps;
        };

        auto hGaps = getGaps(hFences, m);
        auto vGaps = getGaps(vFences, n);

        long long maxSide = -1;
        for (int dist : hGaps) {
            if (vGaps.count(dist)) {
                maxSide = max(maxSide, (long long)dist);
            }
        }

        if (maxSide <= 0) return -1;
        return (int)((maxSide * maxSide) % MOD);
    }
};
