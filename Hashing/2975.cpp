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
    static const int MOD = 1000000007;

    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {

        auto getDistances = [&](vector<int>& f, int limit) {
            f.push_back(1);
            f.push_back(limit);
            sort(f.begin(), f.end());

            unordered_set<int> d;
            for (int i = 0; i < f.size(); i++) {
                for (int j = 0; j < i; j++) {
                    d.insert(f[i] - f[j]);
                }
            }
            return d;
        };

        auto hDist = getDistances(hFences, m);
        auto vDist = getDistances(vFences, n);

        long long best = -1;
        for (int x : hDist) {
            if (vDist.count(x)) {
                best = max(best, (long long)x);
            }
        }

        if (best == -1) return -1;
        return (best * best) % MOD;
    }
};