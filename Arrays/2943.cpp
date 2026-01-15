#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 2943 - Maximize Area of Square Hole in Grid

 Idea:
 - Removing k consecutive bars creates a gap of size (k + 1)
 - Find the maximum consecutive removable bars horizontally and vertically
 - The largest square side = min(horizontal_gap, vertical_gap)
 - Answer = side * side

 Time Complexity: O(H log H + V log V)
 Space Complexity: O(1) extra
*/

class Solution {
public:
    // Returns maximum gap formed by consecutive removable bars
    int maxGap(vector<int>& bars) {
        if (bars.empty()) return 1;

        sort(bars.begin(), bars.end());

        int curr = 1, best = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
            } else {
                best = max(best, curr);
                curr = 1;
            }
        }
        best = max(best, curr);

        return best + 1; // k bars removed → gap of k+1
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {
        int maxH = maxGap(hBars);
        int maxV = maxGap(vBars);
        int side = min(maxH, maxV);
        return side * side;
    }
};
